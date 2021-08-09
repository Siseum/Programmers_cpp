#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores)
{
    string answer = "";

    for (int i = 0; i < scores.size(); i++)
    {
        int max = 0;
        int min = 101;
        double sum = 0.0f;

        for (int j = 0; j < scores.size(); j++)
        {
            sum += scores[j][i];
            if (scores[j][i] > max)
                max = scores[j][i];

            if (scores[j][i] < min)
                min = scores[j][i];
        }

        if (scores[i][i] != max && scores[i][i] != min)
            sum = sum / scores.size();

        else
        {
            int Count = 0;
            for (int j = 0; j < scores.size(); j++)
            {
                if (scores[i][i] == scores[j][i])
                    Count++;
            }

            if (Count == 1)
                sum = (sum - scores[i][i]) / (scores.size() - 1);
            else
                sum = sum / scores.size();
        }

        if (sum >= 90.0f)
            answer.push_back('A');
        else if (sum >= 80.0f)
            answer.push_back('B');
        else if (sum >= 70.0f)
            answer.push_back('C');
        else if (sum >= 50.0f)
            answer.push_back('D');
        else
            answer.push_back('F');
    }

    return answer;
}
