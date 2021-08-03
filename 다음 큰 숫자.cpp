#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int answer = 0;
    int nCount = 0;
    int tempt = n;
    int tCount = 0;

    while (tempt != 0)
    {
        if (tempt & 1)
            nCount++;
        tempt = tempt >> 1;
    }

    while (1)
    {
        n++;
        int tempt = n;
        tCount = 0;
        while (tempt != 0)
        {
            if (tempt & 1)
                tCount++;
            tempt = tempt >> 1;
        }

        if (tCount == nCount)
        {
            answer = n;
            break;
        }
    }

    return answer;
}
