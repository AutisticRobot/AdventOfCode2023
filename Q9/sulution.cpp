#include "code.cpp"
#include <cctype>

long int sorArr[30] = {0};
long int desArr[30] = {0};
long int tranArr[3] = {0};//des,sor,rang
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
    startNum = true;
    for(long int i=0;curLine.size()>0;i++)
    {
        long int tmp;
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
                        log(tmp);
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
                        log(',');
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
    }
    //log(length);
    log("pos: ");
    log(pos);
    if(pos == 2)
    {

        tranArr[2] = 0;

        log(tranArr[2]);
    }
    pos = 0;
    state = 1;
    if(!hasNum)
    {
        log("translaation");
        tranArr[0] = 0;
        tranArr[1] = 0;
        tranArr[2] = 0;
        //log sorArr
        //for(long int i=0;i<=length;i++)
        //{
        //    log(',');
        //    log(sorArr[i]);
        //    log('>');
        //    log(desArr[i]);
        //}
    }
    log("\n");

    //process translation

    for(int i=0;i<=length;i++)
    {
        long int num = sorArr[i];
        //log(tranArr[1] <= num);
        if((tranArr[1] <= num) && (num <= (tranArr[1] + tranArr[2])) && !(tranArr[0] == tranArr[1]) && num != 0)
        {
            log("(");
            log(num);
            desArr[i] = num - tranArr[1] + tranArr[0];
            log(",");
            log(desArr[i]);
            log(")");
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
                desArr[i] = 0;
            }
        }
    }

}

void endFunc()
{
    resetArr(false);
    long int low = sorArr[0];
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


long int externalTest()
{
    return 0;
}