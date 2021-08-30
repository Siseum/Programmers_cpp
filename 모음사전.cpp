#include <string>
#include <vector>

using namespace std;

int solution(string word)
{
    int answer = 0;

    string aStr;
    string tempt;

    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] == 'A')
            aStr.push_back('1');
        else if (word[i] == 'E')
            aStr.push_back('2');
        else if (word[i] == 'I')
            aStr.push_back('3');
        else if (word[i] == 'O')
            aStr.push_back('4');
        else if (word[i] == 'U')
            aStr.push_back('5');
    }

    while (true)
    {
        if (aStr == tempt)
            break;

        answer++;

        if (tempt.size() < 5)
            tempt.push_back('1');

        else if (tempt.size() == 5 && tempt[4] != '6')
            tempt[4]++;

        if (tempt.size() == 5 && tempt[4] == '6')
        {
            for (int i = 4; i >= 1; i--)
            {
                if (tempt[i] == '6')
                {
                    tempt[i - 1]++;
                    tempt.pop_back();
                }
            }
        }
    }

    return answer;
}
