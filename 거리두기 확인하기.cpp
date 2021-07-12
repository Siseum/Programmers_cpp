#include <string>
#include <vector>

using namespace std;

vector<int> answer;
vector<vector<string>> p;

int ni[4] = { 1,2,0,0 };
int nj[4] = { 0,0,1,2 };

int ni2[2] = {1,1};
int nj2[2] = {-1,1};

bool is_Check(vector<string>v, int i, int j)
{
    for (int k = 0; k < 4; k++)
    {
        int nextI = i + ni[k];
        int nextJ = j + nj[k];

        if (nextI < 0 || nextI >= 5 || nextJ < 0 || nextJ >= 5)
            continue;
        if (v[nextI][nextJ] == 'X' && k % 2 == 0)
            k++;
        else if (v[i][j] == 'P' && v[nextI][nextJ] == 'P')
            return false;
    }

    for (int k = 0; k < 2; k++)
    {
        int nextI = i + ni2[k];
        int nextJ = j + nj2[k];
        if (nextI < 0 || nextI >= 5 || nextJ < 0 || nextJ >= 5)
            continue;
        if (v[i][j] == 'P' && v[nextI][nextJ] == 'P')
        {
            if (v[i+1][j] == 'X' && v[nextI - 1][nextJ] == 'X')
                continue;
            return false;
        }
    }

    return true;
}

void Check(int index)
{
    vector<string> v = p[index];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (v[i][j] == 'P')
            {
                if (is_Check(v, i, j) == false)
                {
                    answer.push_back(0);
                    return;
                }
            }
        }
    }
    answer.push_back(1);
}

vector<int> solution(vector<vector<string>> places) 
{
    p = places;

    for (int i = 0; i < p.size(); i++)
        Check(i);

    return answer;
}
