#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcb(int a, int b)
{
    int c = 0;
    while(b!=0)
    {
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int lcm(int a, int b)
{
    return a * b / gcb(a,b);
}

int solution(vector<int> arr) 
{
    int answer = 0;

    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size()-1;i++)
    {
        answer = lcm (arr[i],arr[i+1]);
        arr[i+1]=answer;
    }

    return answer;
}
