#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int index = 0;

    k = number.size() - k;

    for (int i = k; i > 0; i--)
    {
        char tChar = 0;
        for (int j = index; j <= number.size() - i; j++)
        {
            if (tChar < number[j])
            {
                tChar = number[j];
                index = j + 1;
            }
        }
        answer += tChar;
    }
    return answer;
}
