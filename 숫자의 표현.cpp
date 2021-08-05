#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    int answer = 0;
    
    for(int i=1;i<=n;i++)
    {
        int tempt=0;
        for(int j=i;j<=n;j++)
        {
            tempt +=j;
            if(tempt==n)
            {
                answer++;
                break;
            }
            else if(tempt>n)
                break;
        }
    }
    
    return answer;
}
