#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int answer;
int N;
int K;
int Distance[51][51];
int Distance2[51];

void bfs()
{
    queue<pair<int, int>> q;

    for (int i = 1; i <= N; i++)
    {
        if (Distance[1][i] > 0 && Distance[1][i] <= K)
        {
            Distance2[i] = Distance[1][i];
            q.push({ i,Distance[1][i] });
        }
    }

    while (!q.empty())
    {
        int Index = q.front().first;
        int Count = q.front().second;
        q.pop();
        answer++;

        for (int i = 2; i <= N; i++)
        {
            if (Distance[Index][i] == 0)
                continue;
            if (Distance2[i] !=0 && Count + Distance[Index][i] < Distance2[i])
            {
                answer--;
                Distance2[i] = Count + Distance[Index][i];
                q.push({ i,Count + Distance[Index][i] });
            }
            else if (Distance2[i] == 0 && Count + Distance[Index][i] <= K)
            {
                Distance2[i] = Count + Distance[Index][i];
                q.push({ i,Count + Distance[Index][i] });
            }
        }
    }

}


int solution(int n, vector<vector<int> > road, int k) {
    answer = 0;
    N = n;
    K = k;

    for (int i = 0; i < road.size(); i++)
    {
        int I = road[i][0];
        int J = road[i][1];

        if (Distance[I][J] == 0)
        {
            Distance[I][J] = road[i][2];
            Distance[J][I] = road[i][2];
        }
        else if (road[i][2] < Distance[I][J])
        {
            Distance[I][J] = road[i][2];
            Distance[J][I] = road[i][2];
        }
    }

    bfs();

    return answer + 1;
}
