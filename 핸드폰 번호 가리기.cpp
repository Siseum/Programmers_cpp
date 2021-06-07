#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = phone_number;
    int n = phone_number.size()-4;
    
    for(int i=0;i<n;i++)
        answer[i]='*';
    
    return answer;
}
