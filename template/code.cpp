#include <iostream>
#include <fstream>
#include <string>
#include <cctype>



bool doLog = false;
std::string fileDes;
std::ifstream inFile;
std::string curLine;
int total = 0;



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