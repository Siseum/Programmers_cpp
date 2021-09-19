#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char board[500][500] = { 0, };
bool check[500][500][4] = { false, };

vector<int> solution(vector<string> grid)
{
    vector<int> answer;

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            board[i][j] = grid[i][j];
        }
    }
    

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int Y = i;
                int X = j;
                int dir = k;
                int Count = 0;

                while (true)
                {
                    if (dir == 0)
                        Y = (Y - 1 + grid.size()) % grid.size();
                    else if (dir == 1)
                        X = (X + 1 + grid[0].size()) % grid[0].size();
                    else if (dir == 2)
                        Y = (Y + 1 + grid.size()) % grid.size();
                    else if (dir == 3)
                        X = (X - 1 + grid[0].size()) % grid[0].size();

                    Count++;

                    if (check[Y][X][dir])
                        break;

                    check[Y][X][dir] = true;

                    if (board[Y][X] == 'R')
                        dir = (dir + 1 + 4) % 4;
                    else if (board[Y][X] == 'L')
                        dir = (dir - 1 + 4) % 4;

                    if (i == Y && j == X && dir == k)
                    {
                        answer.push_back(Count);
                        break;
                    }

                }

            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    return answer;
}
