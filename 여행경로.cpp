#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
vector<string> tempt;
vector<bool> check;
bool End = false;
vector<vector<string>> tickets;

void dfs(string start, int Count)
{
    tempt.push_back(start);

    if (Count == check.size())
    {
        End = true;
        answer = tempt;
        return;
    }

    for (int i = 0; i < tickets.size(); i++)
    {
        if (start == tickets[i][0] && check[i] == false)
        {
            check[i] = true;
            dfs(tickets[i][1], Count + 1);
            check[i] = false;
        }

        if (End)
            return;
    }

    tempt.pop_back();
}
