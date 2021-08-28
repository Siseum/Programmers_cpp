#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) 
{
    int answer = 0;
    int len = a.size();
    vector<int> left(len);
    vector<int> right(len);

    int Min = a[0];
    for(int i = 0; i < len; i++)
    {
        if(Min > a[i])
            Min = a[i];

        left[i] = Min;
    }

    Min = a[len-1];
    for(int i = len-1; i >= 0; i--)
    {
        if(Min > a[i])
            Min = a[i];
        right[i] = Min;
    }

    for(int i = 0; i < len; i++)
    {
        if(a[i] <= left[i] || a[i] <= right[i])
            answer++;
    }

    return answer;
}
