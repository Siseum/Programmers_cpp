#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int Count = 0;
    int div = 2 * w + 1;
    int start = 1;

    for (int i = 0; i < stations.size(); i++)
    {
        if(start<stations[i]-w)
            Count = stations[i] - w - start;
        else 
        {
            start = stations[i]+w+1;
            continue;
        }

        if (Count % div == 0)
            answer += Count / div;
        else
            answer += Count / div + 1;

        start = stations[i] + w + 1;
    }

    if (start <= n)
    {
        Count = n - start + 1;

        if (Count % div == 0)
            answer += Count / div;
        else
            answer += Count / div + 1;
    }

    return answer;
}
