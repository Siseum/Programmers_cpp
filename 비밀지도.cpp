#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string tempt1;
    string tempt2;
    vector<int> arr3;

    for (int i = 0; i < n; i++)
        arr3.push_back(arr1[i] | arr2[i]);

    for (int i = 0; i < n; i++)
    {
        int number = arr3[i];
        tempt1.clear();
        tempt2.clear();
        while (number != 0)
        {
            if (number % 2 == 0)
                tempt1.push_back(' ');
            else
                tempt1.push_back('#');
            number = number / 2;
        }

        for (int j = tempt1.size(); j <= n; j++)
            tempt1.push_back(' ');

        for (int j = n - 1; j >= 0; j--)
            tempt2.push_back(tempt1[j]);
        answer.push_back(tempt2);
    }

    return answer;
}
