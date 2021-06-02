#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(int i=0;i<s.size();i++)
    {
        int tempt=s[i];
        
        if(tempt==' ')
        {
            answer.push_back(' ');
            continue;
        }
        
        if(tempt>='a'&& tempt<='z')
        {
            tempt=tempt+n;
            if(tempt>'z')
                tempt=tempt-26;
            answer.push_back(tempt);
        }
        
        else if(tempt>='A'&& tempt<='Z')
        {
            tempt=tempt+n;
            if(tempt>'Z')
                tempt=tempt-26;
            answer.push_back(tempt);
        }
        
    }
    
    
    return answer;
}
