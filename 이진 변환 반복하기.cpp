#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    int Count = 0;
    int zeroCount = 0;
    string str = s;

    while (str != "1")
    {
        Count++;
        deque<char> tempt;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0')
                zeroCount++;
            else if (str[i] == '1')
                tempt.push_front('1');
        }

        int n = tempt.size();
        tempt.clear();

        while (n != 0)
        {

            tempt.push_front(n % 2 + '0');
            n = n / 2;
        }

        str.clear();
        for (int i = 0; i < tempt.size(); i++)
            str.push_back(tempt[i]);
    }

    answer.push_back(Count);
    answer.push_back(zeroCount);

    return answer;
}
