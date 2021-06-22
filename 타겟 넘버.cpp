#include <string>
#include <vector>

using namespace std;

int Target;
int answer;
int Count;
vector<int> v;

void dfs(int n, int c)
{
    if(c==Count)
    {
        if(n==Target)
            answer++;
        return;
    }
    
    dfs(n+v[c],c+1);
    dfs(n-v[c],c+1);
}

int solution(vector<int> numbers, int target) 
{
    v = numbers;
    answer = 0;
    Count = numbers.size();
    Target = target;
    
    dfs(0,0);
    
    return answer;
}
