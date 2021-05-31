#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pn=0;
    int yn=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='p'||s[i]=='P')
            pn++;
        else if(s[i]=='y' || s[i]=='Y')
            yn++;
    }
    
    if(pn != yn)
        answer = false;
    
    return answer;
}
