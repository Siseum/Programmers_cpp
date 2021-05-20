#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    int N = new_id.length();

    //1단계
    for (int i = 0; i < N; i++)
    {
        if (answer[i] >= 'A' && answer[i] <= 'Z')
            answer[i] = tolower(answer[i]);
    }

    //2단계
    for (int i = 0; i < answer.length(); i++)
    {
        if ((answer[i] >= 'a' && answer[i] <= 'z') || (answer[i] >= '0' && answer[i] <= '9')
            || (answer[i] == '-') || (answer[i] == '_') || (answer[i] == '.'))
            continue;
        answer.erase(answer.begin() + i);
        i--;
    }

    //3단계
    for (int i = 1; i < answer.length(); i++)
    {
        if (answer[i - 1] == '.' && answer[i] == '.')
        {
            answer.erase(answer.begin() + i);
            i--;
        }
    }

    //4단계
    if (answer.front() == '.')
        answer.erase(answer.begin());
    if (answer.back() == '.')
        answer.erase(answer.begin() + answer.length() -1);

    //5단계
    if (answer.empty())
        answer.push_back('a');

    //6단계
    if (answer.length() >= 16)
    {
        answer.erase(15);
        if (answer.back() == '.')
            answer.erase(answer.begin() + 14);
    }

    //7단계
    if (answer.length() <= 2)
    {
        char a = answer.back();
        while (answer.length() < 3)
            answer.push_back(a);
    }


    return answer;
}
