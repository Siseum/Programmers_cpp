#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int N=commands.size();
    int first=0;
    int second=0;
    int third=0;
    
    for(int i=0;i<N;i++)
    {
        vector<int> tempt;
        first= commands[i][0]-1;
        second=commands[i][1]-1;
        third=commands[i][2]-1;
        
        
        for(int j=first;j<=second;j++)
            tempt.push_back(array[j]);
        
        sort(tempt.begin(),tempt.end());
        
        answer.push_back(tempt[third]);
        
    }
    
    return answer;
}
