

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <regex>

bool doLog = false;
std::string fileDes;
std::ifstream inFile;
std::string curLine;
bool found1st = false;
int num1 = 0;
int numLine = 0;
int total = 0;

void unwordNum(std::string &inString);
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
        unwordNum(curLine);

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


void unwordNum(std::string &inString)
{
    inString = std::regex_replace(inString, std::regex("(one)"), "o1e");
    inString = std::regex_replace(inString, std::regex("(two)"), "t2o");
    inString = std::regex_replace(inString, std::regex("(three)"), "t3e");
    inString = std::regex_replace(inString, std::regex("(four)"), "f4r");
    inString = std::regex_replace(inString, std::regex("(five)"), "f5e");
    inString = std::regex_replace(inString, std::regex("(six)"), "s6x");
    inString = std::regex_replace(inString, std::regex("(seven)"), "s7n");
    inString = std::regex_replace(inString, std::regex("(eight)"), "e8t");
    inString = std::regex_replace(inString, std::regex("(nine)"), "n9e");

}