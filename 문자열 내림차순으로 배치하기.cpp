#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Sorting(char a, char b)
{
    if(a>b)
        return true;
    else
        return false;
}

string solution(string s) {
    string answer = "";
    
    sort(s.begin(),s.end(),Sorting);
    
    answer = s;
    
    return answer;
}
