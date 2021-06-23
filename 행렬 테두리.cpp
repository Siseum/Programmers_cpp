#include <string>
#include <vector>

using namespace std;

int result;
vector<vector<int>> v;

int dirI[4] = { 0,1,0,-1 };
int dirJ[4] = { 1,0,-1,0 };

void Change(int row1, int col1, int row2, int col2)
{
    int tempt1 = v[row1][col1];
    int tempt2 = 0;

    int trow = row1;
    int tcol = col1;

    for (int i = 0; i < 4; i++)
    {
        int nexti = dirI[i];
        int nextj = dirJ[i];

        while (1)
        {
            if (trow + nexti >= row1 && tcol + nextj >= col1
                && trow + nexti <= row2 && tcol + nextj <= col2)
            {
                result = min(result, tempt1);

                tempt2 = v[trow + nexti][tcol + nextj];
                v[trow + nexti][tcol + nextj] = tempt1;
                tempt1 = tempt2;
                

                trow = trow + nexti;
                tcol = tcol + nextj;

            }
            else
                break;
        }

    }

}


vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    result = 1234567890;

    int number = 1;

    for (int i = 1; i <= rows; i++)
    {
        vector<int> tempt;
        for (int j = 1; j <= columns; j++)
            tempt.push_back(number++);
        v.push_back(tempt);
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int row1 = queries[i][0] - 1;
        int col1 = queries[i][1] - 1;
        int row2 = queries[i][2] - 1;
        int col2 = queries[i][3] - 1;

        Change(row1, col1, row2, col2);
        answer.push_back(result);
        result = 1234567890;
    }

    return answer;
}
