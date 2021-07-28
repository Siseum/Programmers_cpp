#include <string>
using namespace std;

int Check[11][11][11][11] = { 0, };

int solution(string dirs) 
{
    int answer = 0;
    int Y = 0;
    int X = 0;

    for (int i = 0; i < dirs.size(); i++)
    {
        int a1 = 0;
        int b1 = 0;
        int a2 = 0;
        int b2 = 0;

        if (X > 0)
            a1 = X + 5;
        else
            a1 = -X;

       if (Y > 0)
            b1 = Y + 5;
        else
            b1 = -Y;
 
       if (dirs[i] == 'U')
       {
           if (Y >= 5)
               continue;
           Y++;
       }
       else if (dirs[i] == 'D')
       {
           if (Y <= -5)
               continue;
           Y--;
       }
       else if (dirs[i] == 'R')
       {
           if (X >= 5)
               continue;
           X++;
       }
       else if (dirs[i] == 'L')
       {
           if (X <= -5)
               continue;
           X--;
       }

        if (X > 0)
            a2 = X + 5;
        else
            a2 = -X;

        if (Y > 0)
            b2 = Y + 5;
        else
            b2 = -Y;


        if (Check[b1][a1][b2][a2] == 0)
        {
            Check[b1][a1][b2][a2]++;
            Check[b2][a2][b1][a1]++;
            answer++;
        }
    }

    return answer;
}
