#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    bool is_pow=false;
    
    for(long long i=1;i*i<=n;i++)
    {
        if(i*i==n)
        {
            answer=i;
            is_pow=true;
            break;
        }
    }
    
    if(is_pow)
        answer = (answer+1)*(answer+1);
    else
        answer = -1;
    
    return answer;
}
