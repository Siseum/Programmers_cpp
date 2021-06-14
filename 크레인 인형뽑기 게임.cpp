#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> count;
    vector<int> result;

    for (int i = 0; i < board.size(); i++)
    {
        bool is_zero = true;
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][i] == 0)
                continue;
            if (board[j][i] != 0)
            {
                count.push_back(board.size() - j);
                is_zero = false;
                break;
            }
        }
        if (is_zero)
            count.push_back(0);
    }

    for (int i = 0; i < moves.size(); i++)
    {
        int tj = moves[i] - 1;
        if (count[tj] == 0)
            continue;
        int ti = board.size() - count[tj];

        result.push_back(board[ti][tj]);
        board[ti][tj] = 0;
        count[tj]--;

        int rCount = result.size();
        if (rCount < 2)
            continue;
        if (result[rCount - 1] == result[rCount - 2])
        {
            answer = answer + 2;
            result.erase(result.begin() + rCount - 2, result.begin() + rCount);
        }

    }

    return answer;
}
