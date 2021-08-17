#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) 
{
    int answer = 0;
    vector<int> ways(n+1);
    
    ways[0]=1;
    
    for(int m : money)
    {
        for(int i= m; i<=n; i++)
        {
            ways[i] += ways[i-m];
            ways[i] %= 1000000007;
        }
    }
    
    return ways[n];
}
