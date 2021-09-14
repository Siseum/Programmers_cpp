#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int Check[1001][1001] = { 0, };

vector<int> solution(vector<int> enter, vector<int> leave) {
    vector<int> answer;
    vector<int> Room;

    int eIndex = 0;
    int lIndex = 0;

    while (true)
    {
        if (eIndex == enter.size() && lIndex == leave.size())
            break;

        if (find(Room.begin(), Room.end(), leave[lIndex]) == Room.end())
            Room.push_back(enter[eIndex++]);

        else
        {
            if (enter[eIndex - 1] == leave[lIndex++])
            {
                for (int i = 0; i < Room.size(); i++)
                {
                    for (int j = 0; j < Room.size(); j++)
                    {
                        Check[Room[i]][Room[j]] = 1;
                        Check[Room[j]][Room[i]] = 1;
                    }
                }

                auto iter = find(Room.begin(), Room.end(), enter[eIndex - 1]);
                Room.erase(iter);
            }
            else
            {
                auto iter = find(Room.begin(), Room.end(), leave[lIndex - 1]);
                Room.erase(iter);

                for (int i = 0; i < Room.size(); i++)
                {
                    for (int j = 0; j < Room.size(); j++)
                    {
                        Check[Room[i]][Room[j]] = 1;
                        Check[Room[j]][Room[i]] = 1;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= enter.size(); i++)
    {
        int count = 0;
        for (int j = 1; j <= enter.size(); j++)
        {
            if (i == j)
                continue;
            if (Check[i][j] == 1)
                count++;
        }
        answer.push_back(count);
    }


    return answer;
}
