/*
1.1 이름 영어 학점 부서이름을 입력 받아 t_profile 구조체 array에 save하되
    이름의 입력이 "end" 이면 입력을 종료 하고

1.2. 전체 데이터를 아래와 같이 출력 하도록 한다.
     단 출력 하는 기능을 함수로 작성을 한다.
void all_person(t_profile* p, int num);   // 전체사원출력
void elite_person(t_profile* p, int num); // elite 사원 출력
​
===== 사원 관리 프로그램 =====
​이름  영어  평점      부서명
==== ==== ====    =========

1.3. 영어 성적이 900점 이상이고 학점이 4.0 이상이면 elite사원 이다
   엘리트 사원을 아래와 같이 출력 하는 프로그램을 작성 하라
​========= elite 사원 ========
이름    영어    평점    부서명
====   ====   ====   =========
*/
/*
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{


}
*/
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>

using namespace std;

class T_profile
{
private:
    typedef struct Info {
        string user_name, team_name;
        int eng_score;
        char eng_grade;
    } t_Info;
public: 
    T_profile();
    virtual ~T_profile();
    std::vector<Info> team_profile;
    void Input_info();
    void Print_all_member();
    void Print_elite_member();
};

T_profile::T_profile()
{

};
T_profile::~T_profile() {};

void T_profile::Input_info()
{
    Info info;
    cout << "input user_name(exit : end) : ";
    cin >> info.user_name;
    if (info.user_name == "end") exit(0);
    cout << "eng_score : ";
    cin >> info.eng_score;
    cout << "eng_grade : ";
    cin >> info.eng_grade;
    cout << "team_name : ";
    cin >> info.team_name;
    team_profile.emplace_back(info);
}

void T_profile::Print_all_member()
{
    int cnt = 1;
    vector<Info>::iterator itr;
    cout << "<All member list>" << endl;

    for (itr = team_profile.begin(); itr != team_profile.end(); itr++)
    {
            cout << cnt << ":" << itr->user_name << " " << itr->eng_score << " " << itr->eng_grade << " " << itr->team_name << endl;
            cnt++;
    }
    cout << endl;
}
void T_profile::Print_elite_member()
{
    int cnt = 1;
    vector<Info>::iterator itr;
    cout << "<Elete member list>" << endl;

    for (itr = team_profile.begin(); itr != team_profile.end(); itr++)
    {
        if (itr->eng_score >= 900 && itr->eng_grade == 'A')
        {
            cout << cnt << ":" << itr->user_name << " " << itr->eng_score << " " << itr->eng_grade << " " << itr->team_name << endl;
            cnt++;
        }
    }
    cout << endl;
}
int main()
{
    T_profile *t_profile = new T_profile();

    while (1)
    {
        t_profile->Input_info();
        t_profile->Print_all_member();
        t_profile->Print_elite_member();
    }

}
