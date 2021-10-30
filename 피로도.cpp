#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer;
vector<vector<int>> DG;

void BT(int tire, int Count, int Index)
{
    if(Index == DG.size())
    {
        answer = max(answer, Count);
        return;
    }
    
    if(tire>=DG[Index][0])
        BT(tire-DG[Index][1], Count+1, Index+1);

    BT(tire, Count, Index+1);
    
}

int solution(int k, vector<vector<int>> dungeons) 
{
    DG = dungeons;
    
    sort(DG.begin(),DG.end());
    
    do
    {
        if(k>=DG[0][0])
            BT(k-DG[0][1],1,1);
        
        BT(k,0,1);
        
    }while(next_permutation(DG.begin(),DG.end()));
    
    return answer;
}
