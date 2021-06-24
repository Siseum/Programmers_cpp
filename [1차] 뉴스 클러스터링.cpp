#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;
    vector<string> tempt1;
    vector<string> tempt2;

    for (int i = 0; i < str1.size() - 1; i++)
    {
        string tempt;
        if (
            ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z'))
            &&
            ((str1[i + 1] >= 'a' && str1[i + 1] <= 'z') || (str1[i + 1] >= 'A' && str1[i + 1] <= 'Z'))
            )
        {
            tempt.push_back(toupper(str1[i]));
            tempt.push_back(toupper(str1[i + 1]));
            tempt1.push_back(tempt);
        }
    }

    for (int i = 0; i < str2.size() - 1; i++)
    {
        string tempt;
        if (
            ((str2[i] >= 'a' && str2[i] <= 'z') || (str2[i] >= 'A' && str2[i] <= 'Z'))
            &&
            ((str2[i + 1] >= 'a' && str2[i + 1] <= 'z') || (str2[i + 1] >= 'A' && str2[i + 1] <= 'Z'))
            )
        {
            tempt.push_back(toupper(str2[i]));
            tempt.push_back(toupper(str2[i + 1]));
            tempt2.push_back(tempt);
        }
    }

    if (tempt1.size() == 0 && tempt2.size() == 0)
        return 65536;

    int index = 0;
    int num1 = 0;
    int num2 = 0;
    sort(tempt1.begin(), tempt1.end());
    sort(tempt2.begin(), tempt2.end());

    for (int i = 0; i < tempt1.size(); i++)
    {
        for (int j = index; j < tempt2.size(); j++)
        {
            if (tempt1[i] == tempt2[j])
            {
                index = ++j;
                num1++;
                break;
            }
        }
    }

    num2 = tempt1.size() + tempt2.size() - num1;
    double num3 = (double)num1 / num2 * 65536;
    answer = num3;

    return answer;
}
