#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) 
{
    int answer = 0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int A_index=0;
    int B_index=0;

    while(B_index<B.size())
    {
        if(B[B_index] > A[A_index])
        {
            B_index++;
            A_index++;
            answer++;
        }
        else
            B_index++;
    }

    return answer;
}
