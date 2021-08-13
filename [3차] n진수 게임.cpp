#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p)
{
    string answer = "";

    int Number = 0;

    p = p - 1;
    int turn = 0;

    while (answer.size() < t)
    {
        string Base = "";
        int tNumber = Number++;
        while (tNumber > 0)
        {
            char t = ((tNumber % n) + '0');
            Base = t + Base;
            tNumber = tNumber / n;
        }
        if (Number == 1)
        {
            char t = (tNumber)+'0';
            Base = t + Base;
        }

        for (int i = 0; i < Base.size(); i++)
        {
            if (p == turn)
            {
                if (Base[i] - '0' == 10)
                    answer.push_back('A');
                else if (Base[i] - '0' == 11)
                    answer.push_back('B');
                else if (Base[i] - '0' == 12)
                    answer.push_back('C');
                else if (Base[i] - '0' == 13)
                    answer.push_back('D');
                else if (Base[i] - '0' == 14)
                    answer.push_back('E');
                else if (Base[i] - '0' == 15)
                    answer.push_back('F');
                else
                    answer.push_back(Base[i]);
            }

            turn = (turn + 1) % m;

            if (answer.size() >= t)
                break;
        }

    }

    return answer;
}
