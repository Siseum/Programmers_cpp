#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    string answer;
    
    map<string,int> Hash;
    map<string,int> Hash2;
    
    int N1=participant.size();
    int N2=completion.size();
    
    for(int i=0;i<N1;i++)
        Hash[participant[i]]++;
    
    for(int i=0;i<N2;i++)
        Hash2[completion[i]]++;
    
    for(int i=0;i<N1;i++)
    {
        if(Hash[participant[i]] != Hash2[participant[i]])
        {
            answer = participant[i];
            break;
        }
    }
       
    return answer;
}
