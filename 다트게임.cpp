#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int N = dartResult.size();
    int answer = 0;
    vector<int> score;
    string tempt;

    for (int i = 0; i < N; i++)
    {
        if (dartResult[i] == 'S')
        {
            int tN = stoi(tempt);
            score.push_back(pow(tN, 1));
            tempt.clear();
        }            
        else if (dartResult[i] == 'D')
        {
            int tN = stoi(tempt);
            score.push_back(pow(tN, 2));
            tempt.clear();
        }

        else if (dartResult[i] == 'T')
        {
            int tN = stoi(tempt);
            score.push_back(pow(tN, 3));
            tempt.clear();
        }

        else if (dartResult[i] == '*')
        {
            if (score.size() == 1)
                score[0] = score[0] * 2;
            else
            {
                for (int j = score.size() - 1; j >= (score.size() - 2); j--)
                {
                    if (j < 0)
                        break;
                    score[j] = score[j] * 2;
                }
            }
        }
        else if (dartResult[i] == '#')
            score[score.size() - 1] = score[score.size() - 1] * (-1);
        else if (dartResult[i] >= '0' && dartResult[i] <= '9')
            tempt.push_back(dartResult[i]);
    }

    for (int i = 0; i < 3; i++)
        answer += score[i];

    return answer;
}
