#include <iostream>
#include <fstream>
#include <string>
#include <cctype>



bool doLog = false;
std::string fileDes;
std::ifstream inFile;
std::string curLine;
int *winNums;
int *curNums;
int wonCards[32] = {0};
int lineTotal;
int total = 0;
int state = 0;




bool processLine();
template<typename T>
void log(T inLog);
void checkWin();

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
        if(std::string(argv[2]) == "Q8/test" && total == 30)
        {
            log("test pass");
        }
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

bool processLine()
{

    curLine.erase(0,5);
    state = 0;
    int fillCount = 0;
    while (curLine.size() > 0)
    {
        switch (state)
        {
            case 0:
                if(curLine[0] == ':')
                {
                    curNums = new int[curLine.size()/3];
                    winNums = new int[curLine.size()/3];
                    state = 1;
                    curLine.erase(0,1);
                }
                curLine.erase(0,1);
            break;
            case 1:
                if(curLine[0] == '|')
                {
                    log("|---|");
                    fillCount = 0;
                    state = 2;
                    curLine.erase(0,2);
                }else if(curLine[0] == ' ')
                {
                    curLine[0] = '0';
                }else{
                    curNums[fillCount] = std::stoi(curLine);
                    log(curNums[fillCount]);
                    log(',');
                    fillCount++;
                    curLine.erase(0,3);
                }
            break;
            case 2:
                if(curLine[0] == ' ')
                {
                    curLine[0] = '0';
                }
                winNums[fillCount] = std::stoi(curLine);
                log(winNums[fillCount]);
                log(',');
                fillCount++;
                curLine.erase(0,3);

            break;
        
        }
        
    }
    checkWin();
    log("\n");
    return true;
}

void checkWin()
{
    int runTimes = 0;
    lineTotal = 0;
    for(int i=0;winNums[i]!=0;i++)
    {
        for(int b=0;curNums[b]!=0;b++)
        {
            runTimes++;
            if(winNums[i] == curNums[b])
            {
                lineTotal += 1;
                //log("match: ");
                //log(i);
                //log(", ");
                //log(b);

            }
        }
    }
    log("\nmulti: ");
    int multi = wonCards[0] + 1;
    log(multi);
    for(int i=0;i<lineTotal;i++)
    {
        wonCards[i+1] += multi;
        total+=multi;
    }
    for(int i=0;i<31;i++)
    {
        wonCards[i] = wonCards[i+1];
    }
    total++;
}