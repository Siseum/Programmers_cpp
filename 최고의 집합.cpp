#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) 
{
    vector<int> answer;

    if(s<n)
    {
        answer.push_back(-1);
        return answer; 
    }

    int t1 = s/n;
    int t2 = s%n;

    for(int i=0;i<n;i++)
    {
        if(i<t2)
            answer.push_back(t1+1);
        else
            answer.push_back(t1);
    }

    sort(answer.begin(),answer.end());

    return answer;
}
