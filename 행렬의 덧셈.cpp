#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int>tempt;
    int row = arr1.size();
    int col = 0;

    for (int i = 0; i < row; i++)
    {
        int col = arr1[i].size();
        for (int j = 0; j < col; j++)
            tempt.push_back(arr1[i][j] + arr2[i][j]);
        answer.push_back(tempt);
        tempt.clear();
    }

    return answer;
}
