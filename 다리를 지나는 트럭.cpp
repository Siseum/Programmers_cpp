#include <string>
#include <vector>
#include <utility>

using namespace std;

int solution(int length, int weight, vector<int> truck)
{
    int answer = 0;
    int bWeight = 0;
    int index = 0;
    vector<pair<int,int>> Clear;

    for (int i = 0; i < truck.size(); i++)
        Clear.push_back({ truck[i],0 });
    
    while (!Clear.empty())
    {
        answer++;

        for (int i = 0; i < index; i++)
        {
            if (Clear[i].second == length)
            {
                index--;
                bWeight -= Clear[i].first;
                Clear.erase(Clear.begin() + i);
            }
        }

        if (index < Clear.size() && bWeight + Clear[index].first <= weight)
        {
            bWeight += Clear[index].first;
            index++;
        }

        for (int i = 0; i < index; i++)
            Clear[i].second++;

    }

    return answer;
}
