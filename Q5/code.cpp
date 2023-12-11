#include <iostream>
#include <fstream>
#include <string>
#include <cctype>



bool doLog = false;
std::string fileDes;
std::ifstream inFile;
std::string curLine;
int total = 0;
int lineSize;
int gameState = 0;// 0 - 1st line, 1 - middle line, 2 - last line
int lineNum = 0;
char *ALine;
char *BLine;
char *CLine;
char *linePoint[3];
char scanBloc[3][7];
int Loffset = 0;
int Roffset = 0;



bool processLine();
void firstLineSetup();
void stringToCharArr(char inArr[]);//turns string curLine into char array inArr[]
void proSymbol(int symPos);
char getPos(int pos, int line, int offset);//helper function for filling out scan bloc
void scanBlocAt(int pos);

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
        if(true)
        {
            if(total == 705066)
            {
                std::cout << "def worng" << std::endl;
            }
        }
        inFile.close();
    }else{
        std::cout << "cannot open file\n";
    }


}


bool processLine()
{


    switch (lineNum%3)
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
        break;
    }

    stringToCharArr(linePoint[2]);

    for(int i=0;i<lineSize;i++)
    {
        if(!(std::isdigit(linePoint[1][i]) || linePoint[1][i] == '.'))
        {
            if(doLog)
            {
                std::cout << "process symbol:" << linePoint[1][i] << std::endl;
            }
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
    if(symPos < 3)
    {
        Loffset = 3 - symPos;
    }else{
        Loffset = 0;
    }
    if(symPos > (lineSize - 4))
    {
        Roffset = (lineSize - 4) - symPos;
    }else{
        Roffset = 0;
    }


    while (fillPos <= 20)
    {
        int line = fillPos/7;
        int pos = fillPos%7;
        scanBloc[line][pos] = getPos(pos, line, symPos);
        if(doLog)
        {
            std::cout << scanBloc[line][pos];
            if(pos == 6)
            {
                std::cout << ";" << gameState << ',' << lineNum % 3 << "\n";
            }
        }
        fillPos++;
    }

    for(int i=0;i<9;i++)
    {
        scanBlocAt(i);
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
    if(pos > (Roffset + 6))
    {
        return 'X';
    }

    offset -= 3;
    return linePoint[line][pos+offset];
}

void scanBlocAt(int pos)
{
    int line = pos / 3;
    int col = pos % 3;

    if(std::isdigit(scanBloc[line][col+2]))
    {

        int curNum = 0;

        for(int i=0;i<5;i++)
        {

            if(std::isdigit(scanBloc[line][col+i]))
            {
                curNum *= 10;
                curNum += (scanBloc[line][col+i] - 48);
                scanBloc[line][col+i] = 'X';
            }else if(i == 1){
                curNum = 0;
            }else if(i > 2){
                i = 42;
            }

            if(doLog)
            {
                std::cout << scanBloc[line][col+i];
            }
        }
        if(doLog)
        {
            std::cout << std::endl << curNum << std::endl;
        }

        total += curNum;

    }

}