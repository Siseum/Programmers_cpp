#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    int row = board.size();
    int col = board[0].size();

    for (int j = 0; j < col; j++)
    {
        if (board[0][j] == 1)
        {
            answer = 1;
            break;
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (board[i][j] == 1)
            {
                board[i][j] = min({ board[i - 1][j], board[i - 1][j - 1], board[i][j - 1] }) + 1;
                answer = max(answer, board[i][j] * board[i][j]);
            }
        }
    }

    return answer;
}
