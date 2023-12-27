#include "code.cpp"

int line1[4] = {0};
int line2[4] = {0};
int lineNum = true;
int lineLength = 4;
int numCount = 0;

int proNum(int index);

bool processLine()
{
    lineLength = numCount;
    numCount = 0;
    bool startNum = true;
    for(int i=0;curLine.size()>0;i++)
    {
        if(std::isdigit(curLine[0]))
        {
            if(startNum)
            {
                if(lineNum)
                {
                    line1[numCount] = firstNum(curLine);
                }else{
                    line2[numCount] = firstNum(curLine);
                }
                numCount++;
                startNum = false;
            }
        }else{
            startNum = true;
        }
        curLine.erase(0,1);
    }
    lineNum = false;
    return true;
}

int externalTest()
{
    return 0;
}


void finalLine()
{
    for(int i=0;i<lineLength;i++)
    {
        log(line1[i]);
        log(">-<");
        log(line2[i]);
        log(',');
    }

    for(int i=0;i<lineLength;i++)
    {
        int tmp = proNum(i);
            log(tmp);
        log(',');
        total *= tmp;
        if(total == 0)
        {
            total = tmp;
        }
    }

}


int proNum(int index)
{
    int inNum = line1[index];
    int inTar = line2[index];

    for(int i=0;i<inNum;i++)
    {
        if((i * (inNum - i)) > inTar)
        {
            log(i);
            log('>');
            return (inNum - i) + 1 - i;
        }
    }
    return 0;
}