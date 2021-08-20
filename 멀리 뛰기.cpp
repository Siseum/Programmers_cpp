#include <string>
#include <vector>

using namespace std;

long long solution(int n) 
{
    long long Count[2001]={0,1,2};

    for(int i=3;i<=n;i++)
    {
        Count[i] = (Count[i-1]+Count[i-2]) % 1234567;
    }  

    return Count[n];
}
