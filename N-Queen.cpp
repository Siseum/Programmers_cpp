#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;
int n;
int answer;

void Check(int y, int x, int value)
{
    for (int i = 0; i < n; i++)
    {
        v[y][i] += value;
        v[i][x] += value;
    }

    int ty = y;
    int tx = x;

    while (true)
    {
        if (ty + 1 < n && tx - 1 >= 0)
        {
            v[ty + 1][tx - 1] +=value ;
            ty = ty + 1;
            tx = tx - 1;
        }
        else
            break;
    }

    ty = y;
    tx = x;

    while (true)
    {
        if (ty + 1 < n && tx + 1 < n)
        {
            v[ty + 1][tx + 1] += value;
            ty = ty + 1;
            tx = tx + 1;
        }
        else
            break;
    }
}

void NQueen(int y, int Count)
{
    if (Count == n)
    {
        answer++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (v[y][i] == 0)
        {
            Check(y, i, 1);
            NQueen(y+1, Count+1);
            Check(y, i, -1);
        }
    }
}

int solution(int N)
{
    n = N;
    v.resize(n);
    for (int i = 0; i < n; i++)
        v[i].resize(n, 0);

    for (int i = 0; i < n; i++)
    {
        Check(0, i, 1);
        NQueen(1, 1);
        Check(0, i, -1);
    }

    return answer;
}
