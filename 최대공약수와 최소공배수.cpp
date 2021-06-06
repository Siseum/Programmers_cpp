#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int n1=n;
    int m1=m;
    
    if(n1>m1)
    {
        int tempt=n1;
        n1=m1;
        m1=tempt;
    }
    
    while(n1 !=0)
    {
        int tempt = m1%n1;
        m1=n1;
        n1=tempt;
    }
    
    answer.push_back(m1);
    answer.push_back(n*m/m1);
    
    return answer;
}
