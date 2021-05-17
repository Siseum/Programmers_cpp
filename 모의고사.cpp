#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> varr[3] = { {1,2,3,4,5},
                     {2, 1, 2, 3, 2, 4, 2, 5},
                     {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
};

vector<int> solution(vector<int> answers) {

    int Count = 0;
    vector<int> answer;

    for (int i = 0; i < 3; i++)
    {
        int tCount = 0;
        int mod = varr[i].size();
        for (int j = 0; j < answers.size(); j++)
        {
            if (varr[i][j % mod] == answers[j])
                tCount++;
        }

        if (tCount > Count)
        {
            answer.clear();
            Count = tCount;
            answer.push_back(i + 1);
        }
        else if (tCount == Count)
        {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
