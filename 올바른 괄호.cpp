#include <iostream>
#include<string>
#include <stack>

using namespace std;

bool solution(string str)
{
    bool answer = true;
    
    stack<char> s;
    
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(')
            s.push('(');
        else if(str[i]==')')
        {
            if(s.empty())
                return false;
            else
                s.pop();
        }
    }

    if(!s.empty())
        answer=false;
        
    return answer;
}
