#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";

    int tempt1 = 3;
    int tempt2 = 1;

    while (1)
    {
        n = n - tempt2;

        if (n < tempt1)
            break;

        tempt2 = tempt1;
        tempt1 = tempt1 * 3;
    }

    while (tempt2 != 0)
    {
        if (n / tempt2 == 0)
            answer = answer + "1";
        else if (n / tempt2 == 1)
            answer = answer + "2";
        else if (n / tempt2 == 2)
            answer = answer + "4";

        n = n % tempt2;
        tempt2 = tempt2 / 3;
    }

    return answer;
}
