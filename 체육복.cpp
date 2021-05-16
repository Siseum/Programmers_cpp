#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int lCount[31] = { 0, };
int rCount[31] = { 0, };

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = n - lost.size();

    for (int i = 0; i < lost.size(); i++)
        lCount[lost[i]]++;
    for (int i = 0; i < reserve.size(); i++)
        rCount[reserve[i]]++;

    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                answer++;
                lCount[lost[i]]--;
                rCount[reserve[j]]--;
                break;
            }
        }
    }
    
    for (int i = 0; i < lost.size(); i++)
    {
        if (lCount[lost[i]] == 0)
            continue;
        int back = lost[i] - 1;
        int next = lost[i] + 1;

        if (rCount[back] == 1)
        {
            rCount[back]--;
            answer++;
        }
        else if (rCount[next] == 1)
        {
            rCount[next]--;
            answer++;
        }
    }
    return answer;
}
