#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = s;

    if (isalpha(answer[0]))
        answer[0] = toupper(answer[0]);

    for (int i = 1; i < answer.size(); i++)
    {
        if (answer[i - 1] == ' ')
            answer[i] = toupper(answer[i]);

        else if (isalpha(answer[i]))
            answer[i] = tolower(answer[i]);

    }
    return answer;
}
