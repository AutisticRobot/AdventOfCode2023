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
char *linePoint;
char scanBloc[3][5];



bool processLine();
void firstLineSetup();
void stringToCharArr(char inArr[]);//turns string curLine into char array inArr[]
void proSymbol(int symPos);
char getPos(int pos, int line);//helper function for filling out scan bloc

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
        linePoint = ALine;

        break;
        case 1:
        linePoint = BLine;

        break;
        case 2:
        linePoint = CLine;


            if(doLog)
            {
                std::cout << "switch case 2" << std::endl;
            }
        break;
    }

    for(int i=0;i<lineSize;i++)
    {
        if(!(std::isdigit(linePoint[i]) || linePoint[i] == '.'))
        {
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
    int Loffset = 0;
    int Roffset = 0;
    if(symPos < 2)
    {
        Loffset = 2 - symPos;
    }
    if(symPos > (lineSize - 2))
    {
        Roffset = (lineSize - 2) - symPos;
    }


    while (fillPos <= 14)
    {
        int line = fillPos/5;
        int pos = fillPos%5;
        scanBloc[line][pos] = getPos(pos, line);
        fillPos++;
    }

    if(doLog)
    {
        std::cout << scanBloc[0] << ',';
        std::cout << scanBloc[1] << ',';
        std::cout << scanBloc[2] << ',';
    }

}

char getPos(int pos,int line)
{

    if(line == 0 && gameState == 0)
    {
        return '.';
    }
    if(line == 2 && gameState == 2)
    {
        return '.';
    }

    return (char)pos;
}