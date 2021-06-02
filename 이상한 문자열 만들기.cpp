#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";
    int index=0;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            answer.push_back(' ');
            index=0;
            continue;
        }
        
        if(index%2==0)
            answer.push_back(toupper(s[i]));
        else
            answer.push_back(tolower(s[i]));
        
        index++;
    }
    
    return answer;
}
