#include <iostream>
#include <fstream>
#include <string>
#include <cctype>



bool doLog = false;
std::string fileDes;
std::ifstream inFile;
std::string curLine;
int total = 0;
int curNum;
int lineSize;
int gameState = 0;// 0 - 1st line, 1 - middle line, 2 - last line
int lineNum = 0;
char *ALine;
char *BLine;
char *CLine;
char *linePoint[3];
char scanBloc[3][5];
int Loffset = 0;
int Roffset = 0;



bool processLine();
void firstLineSetup();
void stringToCharArr(char inArr[]);//turns string curLine into char array inArr[]
void proSymbol(int symPos);
char getPos(int pos, int line, int offset);//helper function for filling out scan bloc

int main(int argc, char *argv[])
{

    if(std::string(argv[1]) == "log")
    {
        doLog = true;
        std::cout << "Log activated" << std::endl;
    }

    fileDes = argv[argc-1];
    std::cout << fileDes << std::endl;
    inFile.open(fileDes);

    
    if(inFile.is_open())
    {
        if(std::getline(inFile,curLine))
        {
            firstLineSetup();
        }
        while (std::getline(inFile,curLine))
        {
            processLine();
            gameState = 1;
            lineNum++;
        if(doLog)
        {
            std::cout << ALine[0] << std::endl;
        }
        }


        gameState = 2;
        processLine();

        std::cout << "Total: " << total << "\n";
        inFile.close();
    }else{
        std::cout << "cannot open file\n";
    }


}


bool processLine()
{


    switch (lineNum%2)
    {
        case 0:
        linePoint[0] = CLine;
        linePoint[1] = ALine;
        linePoint[2] = BLine;

        break;
        case 1:
        linePoint[0] = ALine;
        linePoint[1] = BLine;
        linePoint[2] = CLine;

        break;
        case 2:
        linePoint[0] = BLine;
        linePoint[1] = CLine;
        linePoint[2] = ALine;


            if(doLog)
            {
                std::cout << "switch case 2" << std::endl;
            }
        break;
    }

    stringToCharArr(linePoint[1]);

    for(int i=0;i<lineSize;i++)
    {
        if(!(std::isdigit(linePoint[1][i]) || linePoint[1][i] == '.'))
        {
            std::cout << "process symbol:" << linePoint[1][i] << std::endl;
            proSymbol(i);
        }
    }

    if(gameState == 1)
    {

    }

    return true;
}

void firstLineSetup()
{
    lineSize = curLine.size();
    ALine = new char[lineSize] {'N'};
    BLine = new char[lineSize] {'N'};
    CLine = new char[lineSize] {'N'};
        if(doLog)
        {
            std::cout << ALine[0] << std::endl;
        }
    stringToCharArr(ALine);

}


void stringToCharArr(char inArr[])
{
    for(int i=0;i<lineSize;i++)
    {
        inArr[i] = curLine[i];
    }
}


void proSymbol(int symPos)
{
    int fillPos = 0;
    if(symPos < 2)
    {
        Loffset = 2 - symPos;
    }else{
        Loffset = 0;
    }
    if(symPos > (lineSize - 3))
    {
        Roffset = (lineSize - 3) - symPos;
    }else{
        Roffset = 0;
    }


    while (fillPos <= 14)
    {
        int line = fillPos/5;
        int pos = fillPos%5;
        scanBloc[line][pos] = getPos(pos, line, symPos);
        if(doLog)
        {
            std::cout << scanBloc[line][pos];
            if(pos == 4)
            {
                std::cout << ";" << gameState << "\n";
            }
        }
        fillPos++;
    }


}

char getPos(int pos,int line,int offset)
{

    if(line == 0 && gameState == 0)
    {
        return 'X';
    }
    if(line == 2 && gameState == 2)
    {
        return 'X';
    }
    if(pos < Loffset)
    {
        return 'X';
    }
    if(pos > (Roffset + 4))
    {
        return 'X';
    }

    offset -= 2;
    return linePoint[line][pos+offset];
}