#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int>info[101];

int solution(int n, vector<vector<int>> wires)
{
    int answer = 1234567890;

    for (int i = 0; i < wires.size(); i++)
    {
        info[wires[i][0]].push_back(wires[i][1]);
        info[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++)
    {
        int Count1 = 1;
        int Count2 = 1;

        int num1 = wires[i][0];
        int num2 = wires[i][1];

        bool check1[101] = { false, };
        bool check2[101] = { false };

        check1[num1] = true;
        check2[num2] = true;

        queue<int> tempt;

        for (int j = 0; j < info[num1].size(); j++)
        {
            if (info[num1][j] == num2)
                continue;

            tempt.push(info[num1][j]);
            Count1++;
            check1[info[num1][j]] = true;
        }

        while (!tempt.empty())
        {
            int n = tempt.front();
            tempt.pop();
            check1[n] = true;

            for (int j = 0; j < info[n].size(); j++)
            {
                if (check1[info[n][j]])
                    continue;
                tempt.push(info[n][j]);
                Count1++;
            }
        }

        for (int j = 0; j < info[num2].size(); j++)
        {
            if (info[num2][j] == num1)
                continue;

            tempt.push(info[num2][j]);
            Count2++;
            check2[info[num2][j]] = true;
        }

        while (!tempt.empty())
        {
            int n = tempt.front();
            check2[n] = true;
            tempt.pop();

            for (int j = 0; j < info[n].size(); j++)
            {
                if (check2[info[n][j]])
                    continue;
                tempt.push(info[n][j]);
                Count2++;
            }
        }

        answer = min(answer, abs(Count1 - Count2));
    }

    return answer;
}
