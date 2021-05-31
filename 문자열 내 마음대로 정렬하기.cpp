#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool Sorting(string a, string b)
{
    if(a[N]<b[N])
        return true;
    else if(a[N]==b[N])
        return a<b;
    else
        return false;
}


vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N=n;
    sort(strings.begin(),strings.end(),Sorting);
    answer = strings;
         
    return answer;
}
