#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    
    int zeroCount=0;
    int hSame=0;
    int lSame=0;
    
    for(int i=0;i<6;i++)
    {
        if(lottos[i]==0)
            zeroCount++;
    }
    
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(win_nums[i]==lottos[j])
            {
                lSame++;
                break;
            }
        }
    }
    
    hSame=lSame+zeroCount;
    
    if(lSame<=1)
        lSame=6;
    else 
        lSame = 7 - lSame;
    
    if(hSame<=1)
        hSame=6;
    else 
        hSame = 7 - hSame;
    
    answer.push_back(hSame);
    answer.push_back(lSame);
    
    return answer;
}
