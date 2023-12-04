#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <string_view>



bool doLog = false;
std::string fileDes;
std::ifstream inFile;
std::string curLine;
int gameNum;
int totalGood = 0;
int curNum;
int highR;//12 Max 
int highG;//13 Max
int highB;//14 Max


bool processLine();

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
            if(!processLine())
            {
                totalGood += gameNum;
            }
        }

        std::cout << "Total: " << totalGood << "\n";
        inFile.close();
    }else{
        std::cout << "cannot open file\n";
    }


}


bool processLine()
{
    curLine.erase(0, 5);
    gameNum = std::stoi(curLine);

    if(doLog)
    {
        std::cout << curLine << "\n";
        std::cout << gameNum << "\n";

    }

    bool onNum = true;

    for (int i=0; 0<curLine.size(); i++)
    {
        if(std::isdigit(curLine[0]))
        {
            if(!onNum)
            {
                curNum = std::stoi(curLine);
                onNum = true;
            }
            if(doLog)
            {
                std::cout << "d"<<curNum;
            }
            curLine.erase(0,1);

        //}else if(curLine[0] == ':' || ';' || ',' || ' '){
        //    if(doLog)
        //    {
        //        std::cout << "|he" << curLine[0] << "|";
        //    }
//
        //    curLine.erase(0,1);
        //    onNum = false;
//
        }else{
            if(doLog)
            {
                std::cout << curNum;
            }
            switch (curLine[0])
            {
                case ':':
                case ';':
                case ',':
                case ' ':
            if(doLog)
            {
                //std::cout << "|he" << curLine[0] << "|";
            }

            curLine.erase(0,1);
            onNum = false;

                break;
                case 'r':
                if(curNum > 12)
                {
                    return true;
                }
                curLine.erase(0,3);

                break;
                case 'g':
                if(curNum > 13)
                {
                    return true;
                }
                curLine.erase(0,5);

                break;
                case 'b':
                if(curNum > 14)
                {
                    return true;
                }
                curLine.erase(0,4);
            
                break;
            }
        }
    
    }
    return false;
}