
class Range
{
    public:
    long int start;
    long int end;

    Range(long int inStart, long int inEnd)
    {
        start = inStart;
        end = inEnd;
    }

    bool operator=(Range r1)
    {
        if(!(*this < r1) && !(*this > r1))
        {return true;}
        return false;
    }
    bool operator!=(Range r1)
    {
        return !(*this = r1);
    }
    bool operator<(Range r1)
    {
        if(end < r1.start)
        {return true;}
        return false;
    }
    bool operator>(Range r1)
    {
        if(start > r1.end)
        {return true;}
        return false;

    }

    Range operator+(Range r1)
    {
        Range out = Range(start, end);
        if(out != r1){return out;}

        if(start > r1.start){out.start = r1.start;}
        if(end   < r1.end  ){out.end   = r1.end;}

        return out;
    }
    /*
    Range operator-(Range r1)
    {
        Range out = Range(start, end);
        if(out != r1){return out;}

        if(start < r1.start){out.start = r1.start;}
        if(end   > r1.end  ){out.end   = r1.end;}

        return out;

    }
    */
};