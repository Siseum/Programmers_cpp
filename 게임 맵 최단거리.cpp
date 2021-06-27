#include<vector>
#include<queue>
using namespace std;

int answer;
vector<vector<int>> m;
queue<pair<int, int>> q;
queue<int> qCount;

int ny[4] = { 1,-1,0,0 };
int nx[4] = { 0,0,1,-1 };
bool check[100][100] = { 0, };

int N;
int M;

void bfs()
{
    int Y = q.front().first;
    int X = q.front().second;
    int Count = qCount.front();

    while (!q.empty())
    {
        int Y = q.front().first;
        int X = q.front().second;
        int Count = qCount.front();

        q.pop();
        qCount.pop();

        if ((Y == N - 1 && X == M - 1) || Count > N * M)
        {
            if (Count > N * M)
                Count = N * M + 1;
            else
                answer = min(answer, Count);
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextY = Y + ny[i];
            int nextX = X + nx[i];

            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M && m[nextY][nextX] == 1 && check[nextY][nextX] != true)
            {
                q.push({ nextY,nextX });
                qCount.push(Count + 1);
                check[nextY][nextX] = true;
            }
        }
    }

}


int solution(vector<vector<int> > maps)
{
    N = maps.size();
    M = maps[0].size();

    answer = N * M + 1;
    m = maps;
    q.push({ 0,0 });
    qCount.push(1);
    check[0][0] = true;
    bfs();

    if (answer >= N * M + 1)
        answer = -1;

    return answer;
}
