#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 0;
    string tempt = "";
    string aStr = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (!isalpha(s[i]))
            aStr.push_back(s[i]);

        else
        {
            tempt.push_back(s[i]);

            if (tempt == "zero")
            {
                aStr.push_back('0');
                tempt.clear();
            }
            else if (tempt == "one")
            {
                aStr.push_back('1');
                tempt.clear();
            }
            else if (tempt == "two")
            {
                aStr.push_back('2');
                tempt.clear();
            }
            else if (tempt == "three")
            {
                aStr.push_back('3');
                tempt.clear();
            }
            else if (tempt == "four")
            {
                aStr.push_back('4');
                tempt.clear();
            }
            else if (tempt == "five")
            {
                aStr.push_back('5');
                tempt.clear();
            }
            else if (tempt == "six")
            {
                aStr.push_back('6');
                tempt.clear();
            }
            else if (tempt == "seven")
            {
                aStr.push_back('7');
                tempt.clear();
            }
            else if (tempt == "eight")
            {
                aStr.push_back('8');
                tempt.clear();
            }
            else if (tempt == "nine")
            {
                aStr.push_back('9');
                tempt.clear();
            }
        }
    }

    answer = stoi(aStr);

    return answer;
}
