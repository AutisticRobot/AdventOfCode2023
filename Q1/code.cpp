

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

bool doLog = false;
std::string fileDes;
std::ifstream inFile;
std::string curLine;
bool found1st = false;
int num1 = 0;
int numLine = 0;
int total = 0;

void processLine();

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
            if(doLog){std::cout << numLine << "\n";}
            total += numLine;
            numLine = 0;
        }

        std::cout << "Total: " << total << "\n";
        inFile.close();
    }else{
        std::cout << "cannot open file\n";
    }


    return 0;
}

void processLine()
{
    for (int i=0;i<curLine.size();i++)
    {
        char curChar = curLine[i];
        if(!std::isalpha(curChar))
        {
            numLine = curChar - 48;
            if(!found1st)
            {
                num1 = numLine;
                found1st = true;
            }
        }
    }

    numLine += (num1 * 10);

    found1st = false;
    num1 = 0;
}