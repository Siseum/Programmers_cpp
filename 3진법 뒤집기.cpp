#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int N=n;
    string str;
    
    while(N !=0)
    {
        str.push_back(N%3);
        N=N/3;
    }
    
    N=1;
    for(int i=str.size()-1;i>=0;i--)
    {
        answer+=(str[i])*N;
        N=N*3;
    }
    
    
    return answer;
}
