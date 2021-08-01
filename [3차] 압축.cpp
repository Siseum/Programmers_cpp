#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    map<string, int> m;
    int Count = 1;

    char Ctempt[2] = { 'A','\0' };
    for (int i = 0; i < 26; i++)
    {
        string str(Ctempt);
        Ctempt[0]++;
        m[str] = Count++;
    }

    string tempt = "";

    for (int i = 0; i < msg.size(); i++)
    {
        tempt += msg[i];
        if (m[tempt] != 0 && i == msg.size() - 1)
            answer.push_back(m[tempt]);
        else if (m[tempt] == 0)
        {
            m[tempt] = Count++;
            tempt.pop_back();
            answer.push_back(m[tempt]);
            i--;
            tempt.clear();
        }
    }

    return answer;
}
