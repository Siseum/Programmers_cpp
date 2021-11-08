#include <string>
#include <vector>

using namespace std;

bool dfs(int index, vector<vector<int>>& computers)
{
    if(computers[index][index]==0)
        return false;

    computers[index][index]=0;

    for(int i=0;i<computers.size();i++)
    {
        if(computers[index][i]==1)
            dfs(i,computers);
    }

    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0;i<computers.size();i++)
    {
        if(computers[i][i]==1 && dfs(i,computers))
            answer++;
    }

    return answer;
}
