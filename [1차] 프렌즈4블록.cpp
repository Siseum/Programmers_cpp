#include <string>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) 
{
    int answer = 0;

    deque<deque<char>>v;

    for (int i = 0; i < n; i++)
    {
        deque<char>tempt;
        for (int j = 0; j < m; j++)
            tempt.push_front(board[j][i]);
        v.push_back(tempt);
    }

    bool is_End = false;
    while (1)
    {
        if (is_End)
            break;
        vector<vector<int>> check(30, vector<int>(30));
        is_End = true;

        for (int i = 0; i < n - 1; i++)
        {
            int Start = min(v[i].size(), v[i + 1].size()) - 1;
            for (int j = Start; j > 0; j--)
            {

                if ((v[i][j] == v[i + 1][j]) && (v[i][j] == v[i][j - 1]) && (v[i][j] == v[i + 1][j - 1]))
                {
                    is_End = false;
                    if (check[i][j] == 0)
                    {
                        answer++;
                        check[i][j] = 1;
                    }
                    if (check[i + 1][j] == 0)
                    {
                        answer++;
                        check[i + 1][j] = 1;
                    }
                    if (check[i][j - 1] == 0)
                    {
                        answer++;
                        check[i][j - 1] = 1;
                    }
                    if (check[i + 1][j - 1] == 0)
                    {
                        answer++;
                        check[i + 1][j - 1] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < static_cast<int>(v.size()); i++)
        {
            for (int j = 0; j < static_cast<int>(v[i].size()); j++)
            {
                if (check[i][j] == 1)
                {
                    int Count = 0;
                    for (int k = j + 1; k < v[i].size(); k++)
                    {
                        if (check[i][k] == 1)
                            Count++;
                        else
                            break;
                    }
                    v[i].erase(v[i].begin() + j, v[i].begin() + j + 1 + Count);
                    check[i].erase(check[i].begin() + j, check[i].begin() + j + 1 + Count);
                }
            }

        }
    }

    return answer;
}
