#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> c) 
{
    int answer = 0;
    
    sort(c.begin(),c.end());
    
    for(int i=0;i<=c[c.size()-1];i++)
    {
        int Count = 0;
        for(int j=0;j<c.size();j++)
        {
            if(i <= c[j])
                Count++;
            if(i <= Count)
            {
                answer = i;
                break;
            }
        }
    }
     
    return answer;
}
