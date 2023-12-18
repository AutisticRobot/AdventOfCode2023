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
    /* soooooo much left to learn about strings to get to barly 
    work how I intent it. will use a different method entirly instead.
    int length;
    std::string *testSplitString;
    splitString("test-this", '-', length, testSplitString);
    log(testSplitString[0]);
    if(testSplitString[0] != "test")
    {
        std::cout << "splitString fail :" << testSplitString[0] << std::endl;
        return 1;
    }
    */


    return externalTest();
}

// super fucky
/*
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
    log(secs);
    //std::string output[secs];
    outStrings = new std::string[secs];
    for(int i=0;i<secs;i++)
    {
        outStrings[i] = " ";
    }
    secs = 0;// to keep record of curent open index in output

    log("sepae: |");
    for(int i=0;instring.size()>0;i++)
    {
        if(instring[0] != delim)
        {
            outStrings[secs][i] = instring[0];

            log(outStrings[secs]);
        }else{
            secs++;
            i = -1;
        }
        instring.erase(0,1);
    }

    log("|  end");
    //log(output[0][0]-0);
    outLength = secs++;
    //outStrings = output;
    //log(output);
    log(outStrings);
    return 0;
}
*/