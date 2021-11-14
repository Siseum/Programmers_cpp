#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    int distance = 0;
    vector<vector<int>> node(n + 1);
    vector<int> nodeDistance(n + 1, 100000);
    nodeDistance[0] = 0;

    for (int i = 0; i < edge.size(); i++)
    {
        node[edge[i][0]].push_back(edge[i][1]);
        node[edge[i][1]].push_back(edge[i][0]);
    }

    queue<pair<int,int>> q;
    q.push({ 0, 1 });

    while (!q.empty())
    {
        int start = q.front().first;
        int from = q.front().second;

        q.pop();

        int tDistance = nodeDistance[start] + 1;

        if (tDistance >= nodeDistance[from])
            continue;

        if (distance < tDistance)
        {
            distance = tDistance;
            answer = 1;
        }
        else if (distance == tDistance)
            answer++;

        nodeDistance[from] = tDistance;

        for (int i = 0; i < node[from].size(); i++)
            q.push({ from,node[from][i] });
    }

    return answer;
}
