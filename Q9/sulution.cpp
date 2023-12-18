#include "code.cpp"

std::string *lineArr;
int arrSize;


bool processLine()
{
    if(curLine.size()<2)
    {
        return false;
    }

    splitString(curLine, ' ', arrSize, lineArr);

    log(lineArr);
    log(',');

    return true;
}

int externalTest()
{
    return 0;
}