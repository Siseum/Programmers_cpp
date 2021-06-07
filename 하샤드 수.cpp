#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int mod=0;
    int tempt = x;
    while(tempt !=0)
    {
        mod = mod + tempt %10;
        tempt = tempt/10;
    }
    
    if(x%mod !=0)
        answer = false;
    
    return answer;
}
