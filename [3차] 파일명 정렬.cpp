#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Info
{
    string str;
    string head;
    int number;
    int order;
};

bool Sorting(Info a, Info b)
{
    if (a.head < b.head)
        return true;

    else if (a.head == b.head)
    {
        if (a.number < b.number)
            return true;
        else if (a.number == b.number)
        {
            if (a.order < b.order)
                return true;
        }
    }

    return false;
}

vector<string> solution(vector<string> files) 
{
    vector<string> answer;
    vector<Info> info;

    for (int i = 0; i < files.size(); i++)
    {
        string thead;
        string tnumber;
        Info t;
     
        for (int j = 0; j < files[i].size(); j++)
        {
            if (isalpha(files[i][j]))
                thead.push_back(tolower(files[i][j]));
          
            else if (files[i][j] == ' ' || files[i][j] == '.' || files[i][j] == '-')
                thead.push_back(files[i][j]);
          
            else if (isdigit(files[i][j]))
            {
                tnumber.push_back(files[i][j]);
                if (j + 1 == files[i].size() || !isdigit(files[i][j + 1]))
                    break;
            }
        }

        t.str = files[i];
        t.head = thead;
        t.number = stoi(tnumber);
        t.order = i;
        info.push_back(t);
    }

    sort(info.begin(), info.end(), Sorting);

    for (int i = 0; i < info.size(); i++)
        answer.push_back(info[i].str);

    return answer;
}
