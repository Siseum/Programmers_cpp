#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 1234567890;

    for (int i = 1; i <= s.size() / 2 + 1; i++)
    {
        string tStr = "";
        for (int j = 0; j < s.size();)
        {
            string tempt1 = s.substr(j, i);
            int Count = 1;

            if (j + i > s.size())
            {
                tStr = tStr + s.substr(j, s.size() - j);
                break;
            }

            while (1)
            {
                string tempt2 = s.substr(j + i, i);
                j = j + i;

                if (tempt1 == tempt2)
                    Count++;
                else
                {
                    if (Count == 1)
                        tStr = tStr + tempt1;
                    else
                        tStr = tStr + to_string(Count) + tempt1;
                    break;
                }
            }
        }
        if (answer > tStr.size())
            answer = tStr.size();
    }

    return answer;
}
