#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = s.size();
    
    if(n%2==0)
    {
        n=n/2;
        answer.push_back(s[n-1]);
        answer.push_back(s[n]);   
    }
    else
    {
        n=n/2;
        answer.push_back(s[n]);
    }
    return answer;
}
