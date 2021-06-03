#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> tempt;
    while(n !=0)
    {
        tempt.push_back(n%10);
        n=n/10;
    }
    
    sort(tempt.begin(),tempt.end(),greater<int>());
    
    for(int i=0;i<tempt.size();i++)
    {
        answer = answer*10+tempt[i];
    }
    
    return answer;
}
