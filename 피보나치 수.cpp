#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    long long tempt[3] = {0,1,0};
    long long answer = 0;
    
    if(n==1)
        return 1;
    
    for(int i=2;i<=n;i++)
    {
        tempt[i%3]= (tempt[(i-2) % 3] + tempt[(i-1) % 3]) % 1234567;
    }

    answer = tempt[n%3];
    
    return answer;
}
