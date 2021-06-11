#include <string>
#include <vector>

using namespace std;

int answer = 0;

bool check[8];

void dfs(int Count, int n, vector<string> data, vector<char> v)
{
    if (Count == 8)
    {
        for (int i = 0; i < n; i++)
        {
            char p1 = data[i][0];
            char p2 = data[i][2];
            char s = data[i][3];
            char number = data[i][4] - '0';

            if (s == '=')
            {
                for (int j = 0; j < 8; j++)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (v[j] == p1 && v[k] == p2 && abs(j - k) - 1 != number)
                            return;
                        else if (v[j] == p2 && v[k] == p1 && abs(j - k) - 1 != number)
                            return;
                    }
                }
            }

            else if (s == '>')
            {
                for (int j = 0; j < 8; j++)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (v[j] == p1 && v[k] == p2 && abs(j - k) - 2 < number)
                            return;
                        else if (v[j] == p2 && v[k] == p1 && abs(j - k) - 2 < number)
                            return;
                    }
                }
            }

            else if (s == '<')
            {
                for (int j = 0; j < 8; j++)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        if (v[j] == p1 && v[k] == p2 && abs(j - k) > number)
                            return;
                        else if (v[j] == p2 && v[k] == p1 && abs(j - k) > number)
                            return;
                    }
                }
            }

        }

        answer++;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        if (check[i])
            continue;

        if (i == 0)
            v.push_back('A');
        else if (i == 1)
            v.push_back('C');
        else if (i == 2)
            v.push_back('F');
        else if (i == 3)
            v.push_back('J');
        else if (i == 4)
            v.push_back('M');
        else if (i == 5)
            v.push_back('N');
        else if (i == 6)
            v.push_back('R');
        else if (i == 7)
            v.push_back('T');

        check[i] = true;
        dfs(Count + 1, n, data, v);
        check[i] = false;
        v.pop_back();
    }
}

int solution(int n, vector<string> data)
{
    answer = 0; 
    vector<char> v;
    dfs(0, n, data, v);

    return answer;
}
