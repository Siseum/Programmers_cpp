#include <string>
#include <vector>

using namespace std;

int dp[501][501];
int answer;

int solution(vector<vector<int>> t) 
{
    dp[0][0]=t[0][0];
    answer = dp[0][0];
    
    for(int i=1;i<t.size();i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                dp[i][j]=dp[i-1][j]+t[i][j];
            else if(j==i)
                dp[i][j]=dp[i-1][j-1]+t[i][j];
            else
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+t[i][j];
            
            answer=max(dp[i][j],answer);
        }
    }
    
    return answer;
}
