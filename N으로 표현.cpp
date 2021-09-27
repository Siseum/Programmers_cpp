#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int getNN(int N, int index)
{
    int result = N;
    for(int i=1;i<=index;i++)
    {
        result = result * 10 + N;
    }
    
    return result;
}

int solution(int N, int number) 
{
    if(N== number)
        return 1;
    
    vector<unordered_set<int>> dp(8);
    dp[0].insert(N);
    
    for(int k=1;k<8;k++)
    {
        for(int i=0;i<k;i++)
        {
            int j= k-1-i;
            
            for(int a : dp[i])
            {
                for(int b : dp[j])
                {
                    dp[k].insert(a+b);
                    
                    if(a-b>0)
                        dp[k].insert(a-b);
                    
                    dp[k].insert(a*b);
                    
                    if(a/b>0)
                        dp[k].insert(a/b);
                }
            }
            
        }
        
        dp[k].insert(getNN(N,k));
        
        if(dp[k].count(number))
            return k+1;
    }
    
    return -1;
}
