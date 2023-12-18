#include "code.cpp"

int *sor;
int *des;
int state = 0;


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
        switch (state)
        {
            case 0:
            case 1:
            std::string tmp;
            tmp = firstNum(curLine);
            log(firstNum(curLine));
            log('>');
            //log(curLine[0]);
            log(',');
            state = 1;

        }

            curLine.erase(0,1);
    }

    return true;
}

int externalTest()
{
    return 0;
}