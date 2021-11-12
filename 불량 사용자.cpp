#include <string>
#include <vector>

using namespace std;

vector<string> user;
vector<string> ban;
bool userCheck[8] = { false, };
vector<int> checkVector;
int answer = 0;

void IdSearch(int Count, int n)
{
    if (find(checkVector.begin(), checkVector.end(), n) != checkVector.end())
        return;

    if (Count == ban.size())
    {
        answer++;
        checkVector.push_back(n);
        return;
    }

    for (int i = 0; i < user.size(); i++)
    {
        bool is_same = false;
        if (userCheck[i] == false && user[i].size() == ban[Count].size())
        {
            is_same = true;
            for (int j = 0; j < user[i].size(); j++)
            {
                if (ban[Count][j] == '*')
                    continue;
                if (user[i][j] != ban[Count][j])
                {
                    is_same = false;
                    break;
                }
            }
        }

        if (is_same)
        {
            userCheck[i] = true;
            IdSearch(Count + 1, n + (1 << i));
            userCheck[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    user = user_id;
    ban = banned_id;

    IdSearch(0, 0);

    return answer;
}
