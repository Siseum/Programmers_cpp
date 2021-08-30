#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> r) 
{
    int answer = 1;
    sort(r.begin(),r.end());
    
    int Pos = r[0][1];
    
    for(int i=1;i<r.size();i++)
    {
        if(r[i][1]<Pos)
            Pos=r[i][1];
        else if(r[i][0]>Pos)
        {
            Pos=r[i][1];
            answer++;
        }
    }
    
    return answer;
}
