#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer;

    for (int i = 1; i <= yellow; i++)
    {
        if (yellow % i != 0)
            continue;

        int a = yellow / i;
        int b = i;

        if (brown == ((a + 2) * 2 + b * 2))
        {
            answer.push_back(a + 2);
            answer.push_back(b + 2);
            break;
        }
    }

    return answer;
}
