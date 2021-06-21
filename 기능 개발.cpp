#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    vector<int> day;
    bool check[100] = { 0, };

    for (int i = 0; i < progresses.size(); i++)
    {
        if ((100 - progresses[i]) % speeds[i] == 0)
            day.push_back(((100 - progresses[i]) / speeds[i]));
        else
            day.push_back(((100 - progresses[i]) / speeds[i]) + 1);
    }

    for (int i = 0; i < day.size(); i++)
    {
        if (check[i] == true)
            continue;

        check[i] = true;
        int count = 1;
        int Compare = day[i];

        for (int j = i + 1; j < day.size(); j++)
        {
            if (Compare < day[j])
                break;
            else
            {
                check[j] = true;
                count++;
            }
        }
        answer.push_back(count);
    }

    return answer;
}
