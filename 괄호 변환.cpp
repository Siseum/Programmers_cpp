#include <string>
#include <vector>

using namespace std;

bool NormalCheck(string u)
{
    int Count = 0;

    for (int i = 0; i < u.size(); i++)
    {
        if (Count < 0)
            return false;
        if (u[i] == '(')
            Count++;
        else if (u[i] == ')')
            Count--;
    }
    return true;
}

string solution(string p) {
    string answer = "";
    int index = 0;
    if (p == "")
        return p;
    
    int Count = 0;
    string u;
    string v;

    for (index = 0; index < p.size(); index++)
    {
        u.push_back(p[index]);
        if (p[index] == '(')
            Count++;
        else if (p[index] == ')')
            Count--;
        if (Count == 0)
            break;;
    }

    for (int i = index+1; i < p.size(); i++)
        v.push_back(p[i]);

    if (NormalCheck(u))
    {
        answer += u;
        answer += solution(v);
    }
    else
    {
        answer = "(";
        answer += solution(v);
        answer +=")";

        u.erase(u.begin());
        u.erase(u.end() - 1);

        for (int i = 0; i < u.size(); i++)
        {
            if (u[i] == ')')
                answer += '(';
            else
                answer += ')';
        }
    }

    return answer;
}
