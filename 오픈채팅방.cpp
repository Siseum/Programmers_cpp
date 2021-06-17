#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid; // id만 따로 저장
    map<string,string> nick_info;  // key 아이디 / value 닉네임
    stringstream ss;
    string action;
    string id;
    string nickname;
    
    for(int i=0;i<record.size();i++)
    {
        ss.str(record[i]);
        ss>>action;
        if(action == "Enter")
        {
            ss >> id;
            ss >> nickname;
            answer.push_back("님이 들어왔습니다.");
            uid.push_back(id);
            nick_info[id]=nickname;
        }
        else if(action == "Leave")
        {
            ss >> id;
            answer.push_back("님이 나갔습니다.");
            uid.push_back(id);
        }
        else
        {
            ss >> id;
            ss >> nickname;
            nick_info[id]=nickname;
        }
        ss.clear();
    }
    
    for(int i=0;i<answer.size();i++)
        answer[i] = nick_info[uid[i]] + answer[i];
    
    return answer;
}
