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
int gameState = 0;// 0 - 1st line, 1 - middle line, 2 - last line
int lineNum = 0;
char *ALine;
char *BLine;
char *CLine;



bool processLine();
void firstLineSetup();
void stringToCharArr(char inArr[]);

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

    if(gameState == 0)
    {
        firstLineSetup();
        return true;
    }


    return true;
}

void firstLineSetup()
{
    gameState = 1;

    ALine = new char[curLine.size()] {'N'};
    BLine = new char[curLine.size()] {'N'};
    CLine = new char[curLine.size()] {'N'};
        if(doLog)
        {
            std::cout << ALine[0] << std::endl;
        }
    stringToCharArr(ALine);

}


void stringToCharArr(char inArr[])
{
    for(int i=0;i<curLine.size();i++)
    {
        inArr[i] = curLine[i];
    }
}