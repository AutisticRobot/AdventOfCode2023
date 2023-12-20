#include "code.cpp"
#include <cctype>

int *sorArr[24];
int *desArr[24];
int length = 24;
int state = 0;
bool startNum = true;


bool processLine()
{
    if(curLine.size()<2)
    {
        return false;
    }
    switch (state)
    {
        case 0:
            curLine.erase(0,7);
        break;
        case 1:


        break;

    }

    for(int i=0;curLine.size()>0;i++)
    {
        std::string tmp;
        switch (state)
        {
            case 0:
                if(std::isdigit(curLine[0]))
                {
                    if(startNum)
                    {
                        tmp = firstNum(curLine);
                        log(firstNum(curLine));
                        log(' ');
                        startNum = false;
                    }

                }else{
                    startNum = true;
                }
                state = 1;
            break;

            case 1:

            break;

        }

            curLine.erase(0,1);
    }
    log("\n");
    return true;
}

int externalTest()
{
    return 0;
}