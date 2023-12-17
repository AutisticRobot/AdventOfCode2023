#include <cstddef>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>



bool doLog = false;
std::string fileDes = "gTest";
std::ifstream inFile;
std::string curLine;
int total = 0;



int selfTest();
int externalTest();// function for the user to declare to be tested in selfTest() function;
bool processLine();
template<typename T>
void log(T inLog);
int firstNum(std::string inString);
int splitString(std::string instring, char delim, int &outLength, std::string *outStrings);

int main(int argc, char *argv[])
{

    if(std::string(argv[1]) == "log")
    {
        doLog = true;
        std::cout << "Log activated" << std::endl;
    }


    fileDes = argv[argc-1];

    if(fileDes == "gTest" || "test")
    {
        log("self test start\n");
        selfTest();
        log("self test done");
        std::cout << std::endl;
    }

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

template<typename T>
void log(T log)
{
    if(doLog)
    {
        std::cout << log;
    }
}


int firstNum(std::string inString)
{
    while(inString.size() > 0)
    {
        if(std::isdigit(inString[0]))
        {
            return std::stoi(inString);
        }else{
            inString.erase(0,1);
        }
    }
    return 0;
}

int selfTest()
{
    //splitString test
    int length;
    std::string *testSplitString;
    splitString("test-this", '-', length, testSplitString);
    log(testSplitString[0]);
    if(testSplitString[0] != "test")
    {
        std::cout << "splitString fail :" << testSplitString[0] << std::endl;
        return 1;
    }

    return externalTest();
}

int splitString(std::string instring, char delim, int &outLength, std::string *outStrings)
{
    int secs = 1;
    for(int i=0;i<instring.size();i++)
    {
        if(instring[i] == delim)
        {
            secs++;
        }
    }
    std::string output[secs];
    for(int i=0;i<secs;i++)
    {
        output[i] = instring;
    }
    secs = 0;// to keep record of curent open index in output

    for(int i=0;instring.size()>0;i++)
    {
        if(instring[0] != delim)
        {
            output[secs][i] = instring[0];

        }else{
            secs++;
            i = 0;
        }
        instring.erase(0,1);
    }

    outLength = secs++;
    outStrings = output;
    return 0;
}