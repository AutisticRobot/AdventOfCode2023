#include "code.cpp"
#include <cctype>

int sorArr[24] = {0};
int desArr[24] = {0};
int tranArr[3] = {0};//des,sor,rang
int length = -1;
int state = 0;
bool startNum = true;

void resetArr(bool hasNum);


bool processLine()
{
    bool hasNum = false;
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

    int pos = 0;
    for(int i=0;curLine.size()>0;i++)
    {
        int tmp;
        switch (state)
        {
            case 0:
                if(std::isdigit(curLine[0]))
                {
                    if(startNum)
                    {
                        length++;
                        tmp = firstNum(curLine);
                        sorArr[length] = tmp;
                        log(sorArr[length]);
                        log(' ');
                        startNum = false;
                        hasNum = true;
                    }

                }else{
                    startNum = true;
                }
            break;

            case 1:
                if(std::isdigit(curLine[0]))
                {
                    if(startNum)
                    {
                        tmp = firstNum(curLine);
                        tranArr[pos] = tmp;
                        log(tranArr[pos]);
                        log(pos);
                        startNum = false;
                        pos++;
                        hasNum = true;
                    }

                }else{
                    startNum = true;
                }

            break;

        }

        curLine.erase(0,1);
    }/*
    //log(length);
    log("pos: ");
    log(pos);
    if(pos == 2)
    {

        tranArr[2] = 0;

        log(tranArr[2]);
    }*/
    pos = 0;
    state = 1;
    if(!hasNum)
    {
        log("translaation");
    }
    log("\n");

    //process translation

    for(int i=0;i<=length;i++)
    {
        int num = sorArr[i];
        //log(tranArr[1] <= num);
        if(tranArr[1] <= num && num <= (tranArr[1] + tranArr[2]))
        {
            desArr[i] = num - tranArr[1] + tranArr[0];
            //log("(");
            //log(desArr[i]);
            //log(",");
            //log(i);
            //log(".");
            sorArr[i] = 0;
        }
    }

    resetArr(hasNum);

    
    return true;
}

void resetArr(bool hasNum)
{
    //put destination back to source
    if(!hasNum)
    {
        //log("/\\noNum");
        for(int i=0;i<=length;i++)
        {
            if(desArr[i] != 0)
            {
                sorArr[i] = desArr[i];
            }
        }
    }

}

void endFunc()
{
    resetArr(false);
    int low = sorArr[0];
    for(int i=0;i<=length;i++)
    {
        log(sorArr[i]);
        log(",");
        if(sorArr[i] < low)
        {
            low = sorArr[i];
        }
    }
    total = low;
}


int externalTest()
{
    return 0;
}