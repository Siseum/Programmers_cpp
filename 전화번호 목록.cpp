#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool solution(vector<string> pb)
{
    bool answer = true;

    sort(pb.begin(), pb.end());

    for (int i = 0; i < pb.size() - 1; i++)
    {
        if (answer == false)
            break;
        string tempt1 = pb[i];
        string tempt2 = pb[i + 1].substr(0, tempt1.size());

        if (tempt1 == tempt2)
        {
            answer = false;
            break;
        }
    }

    return answer;
}
