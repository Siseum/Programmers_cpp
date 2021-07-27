#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Arr;
int One;
int Zero;

void Counting(int N, int a, int b)
{
    if (N == 2)
    {
        int tOne = 0;
        int tZero = 0;
        int A = 0;
        int B = 0;
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                A = a;
                B = b;
            }
            else if (i == 1)
            {
                A = a;
                B = b + N / 2;
            }
            else if (i == 2)
            {
                A = a + N / 2;
                B = b;
            }
            else if (i == 3)
            {
                A = a + N / 2;
                B = b + N / 2;
            }

            for (int j = 0; j < N / 2; j++)
            {
                for (int k = 0; k < N / 2; k++)
                {
                    if (Arr[A + j][B + k] == 1)
                        tOne++;
                    else
                        tZero++;
                }
            }
        }
        if (tOne != 0 && tZero != 0)
        {
            Zero += tZero;
            One += tOne;
        }
        else if (tOne == 0)
            Zero++;
        else if (tZero == 0)
            One++;
    }

    else
    {
        for (int i = 0; i < 4; i++)
        {
            int tOne = 0;
            int tZero = 0;
            int A = 0;
            int B = 0;

            if (i == 0)
            {
                A = a;
                B = b;
            }
            else if (i == 1)
            {
                A = a;
                B = b + N / 2;
            }
            else if (i == 2)
            {
                A = a + N / 2;
                B = b;
            }
            else if (i == 3)
            {
                A = a + N / 2;
                B = b + N / 2;
            }

            for (int j = 0; j < N / 2; j++)
            {
                for (int k = 0; k < N / 2; k++)
                {
                    if (Arr[A + j][B + k] == 1)
                        tOne++;
                    else
                        tZero++;
                }
            }
            if (tOne != 0 && tZero != 0)
                Counting(N / 2, A, B);
            else if (tOne == 0)
                Zero++;
            else if (tZero == 0)
                One++;
        }
    }

}

vector<int> solution(vector<vector<int>> arr)
{
    vector<int> answer;

    Arr = arr;

    int tOne = 0;
    int tZero = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 0)
                tZero++;
            else
                tOne++;
        }
    }

    if (tZero != 0 && tOne == 0)
        Zero = 1;
    else if (tZero == 0 && tOne != 0)
        One = 1;

    else
        Counting(Arr.size(), 0, 0);

    answer.push_back(Zero);
    answer.push_back(One);

    return answer;
}
