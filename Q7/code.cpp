#include <iostream>
#include <fstream>
#include <string>
#include <cctype>



bool doLog = false;
std::string fileDes;
std::ifstream inFile;
std::string curLine;
char *winNums;
char *curNums;
int total = 0;
int state = 0;




bool processLine();
void log(std::string inLog);

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
        }



        std::cout << "Total: " << total << "\n";
        if(std::string(argv[2]) == "test" && total == 13)
        {
            log("test pass");
        }
        inFile.close();
    }else{
        std::cout << "cannot open file\n";
    }


}

void log(std::string log)
{
    if(doLog)
    {
        std::cout << log;
    }
}

bool processLine()
{
    curLine.erase(0,5);
    while (curLine.size() != 0)
    {
        switch (state)
        {
            case 0:
                if(curLine[0] == ':')
                {
                    state = 1;
                    curLine.erase(0,1);
                }
                curLine.erase(0,1);
            break;
            case 1:
            break;
            case 2:
            break;
        
        }
        
    }
    return true;
}