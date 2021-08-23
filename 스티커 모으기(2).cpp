#include <iostream>
#include <vector>
using namespace std;

int dp[100001];

int solution(vector<int> s)
{
    int answer =0;
    int n= s.size();
    if(n == 1)
        return s[0];
    
    dp[0]=s[0];
    dp[1]=s[0];
    
    for(int i=2;i<n-1;i++)
        dp[i]=max(dp[i-2]+s[i],dp[i-1]);
    
    answer = max(answer,dp[n-2]);
    
    dp[0]=0;
    dp[1]=s[1];
    
    for(int i=2;i<n;i++)
        dp[i]=max(dp[i-2]+s[i],dp[i-1]);
    
    answer = max(answer, dp[n-1]);

    return answer;
}
