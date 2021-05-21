#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int Left[2]={3,0};
    int Right[2]={3,2};
    
    int N= numbers.size();
    
    for(int i=0;i<N;i++)
    {
        if(numbers[i]==1)
        {
            Left[0]=0;
            Left[1]=0;
            answer.push_back('L');
        }
        
        else if(numbers[i]==4)
        {
            Left[0]=1;
            Left[1]=0;
            answer.push_back('L');
        }
        
        else if(numbers[i]==7)
        {
            Left[0]=2;
            Left[1]=0;
            answer.push_back('L');
        }
        
        else if(numbers[i]==3)
        {
            Right[0]=0;
            Right[1]=2;
            answer.push_back('R');
        }
        
        else if(numbers[i]==6)
        {
            Right[0]=1;
            Right[1]=2;
            answer.push_back('R');
        }
        
        else if(numbers[i]==9)
        {
            Right[0]=2;
            Right[1]=2;
            answer.push_back('R');
        }
        
        else if(numbers[i]==2)
        {
            int LD = abs(Left[0]-0)+abs(Left[1]-1);
            int RD = abs(Right[0]-0)+abs(Right[1]-1);
            
            if(LD<RD)
            {
                Left[0]=0;
                Left[1]=1;
                answer.push_back('L');
            }
            
            else if(LD>RD)
            {
                Right[0]=0;
                Right[1]=1;
                answer.push_back('R');
            }
            
            else if(hand == "right")
            {
                Right[0]=0;
                Right[1]=1;
                answer.push_back('R');
            }
            
            else if(hand == "left")
            {
                Left[0]=0;
                Left[1]=1;
                answer.push_back('L');
            }
        }
        
        else if(numbers[i]==5)
        {
            int LD = abs(Left[0]-1)+abs(Left[1]-1);
            int RD = abs(Right[0]-1)+abs(Right[1]-1);
            
            if(LD<RD)
            {
                Left[0]=1;
                Left[1]=1;
                answer.push_back('L');
            }
            
            else if(LD>RD)
            {
                Right[0]=1;
                Right[1]=1;
                answer.push_back('R');
            }
            
            else if(hand == "right")
            {
                Right[0]=1;
                Right[1]=1;
                answer.push_back('R');
            }
            
            else if(hand == "left")
            {
                Left[0]=1;
                Left[1]=1;
                answer.push_back('L');
            }
        }
        
        else if(numbers[i]==8)
        {
            int LD = abs(Left[0]-2)+abs(Left[1]-1);
            int RD = abs(Right[0]-2)+abs(Right[1]-1);
            
            if(LD<RD)
            {
                Left[0]=2;
                Left[1]=1;
                answer.push_back('L');
            }
            
            else if(LD>RD)
            {
                Right[0]=2;
                Right[1]=1;
                answer.push_back('R');
            }
            
            else if(hand == "right")
            {
                Right[0]=2;
                Right[1]=1;
                answer.push_back('R');
            }
            
            else if(hand == "left")
            {
                Left[0]=2;
                Left[1]=1;
                answer.push_back('L');
            }
        }
        
        else if(numbers[i]==0)
        {
            int LD = abs(Left[0]-3)+abs(Left[1]-1);
            int RD = abs(Right[0]-3)+abs(Right[1]-1);
            
            if(LD<RD)
            {
                Left[0]=3;
                Left[1]=1;
                answer.push_back('L');
            }
            
            else if(LD>RD)
            {
                Right[0]=3;
                Right[1]=1;
                answer.push_back('R');
            }
            
            else if(hand == "right")
            {
                Right[0]=3;
                Right[1]=1;
                answer.push_back('R');
            }
            
            else if(hand == "left")
            {
                Left[0]=3;
                Left[1]=1;
                answer.push_back('L');
            }
        }
        
        
    }
   
    return answer;
}
