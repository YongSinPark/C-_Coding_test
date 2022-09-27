/*
4.명함을 의미하는 NameCard 클래스를 작성하여 아래의 프로그램이 동작 되도록 완성 하시오. 
이 클래스에는 다음의 정보가 저장되어야 한다.
성명, 회사이름, 전화번호, 직급
단, 직급 정보를 제외한 나머지는 문자열의 형태로 저장을 하되, 길이에 딱 맞는 메모리 공간을 할당 받는 형태로 정의하자(동적 할당을 하라는 뜻). 
그리고 직급 정보는 int형 멤버변수를 선언해서 저장을 하되, 아래의 enum 선언을 활용해야 한다.
enum {CLERK, SENIOR, ASSIST, MANAGER};
 위의 enum 선언에서 정의된 상수는 순서대로 사원, 주임, 대리, 과장을 뜻한다. 그럼 다음 main 함수와 실행의 예를 참조하여, 이 문제에서 원하는 형태대로 NameCard 클래스를 완성 하시오.

int main(void)
{    
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);    
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}

이름 : Lee
회사 : ABCEng
전화번호 : 010-1111-2222
직급 : 사원
이름 : Hong
회사 : OrangeEng
전화번호 : 010-3333-4444
직급 : 주임
이름 : Kim
회사 : SoGoodComp
전화번호 : 010-5555-6666
직급 : 대리

*/
#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;



namespace COMP_POS{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
};

class NameCard
{
private:
    typedef struct Info {
        char* name;
        char* company;
        char* phone_num;
        int comp_pos;
    } Info;
    Info* pnt;
public:
    NameCard(const char* name, const char* company, const char* phone_num, int comp_pos);
    NameCard();
    virtual ~NameCard();
    void ShowNameCardInfo();
};

NameCard::NameCard(const char* name, const char* company, const char* phone_num, int comp_pos)
{
   Info *pnt = new Info;

    pnt->name = new char[strlen(name)+1];
    pnt->company = new char[strlen(company)+1];
    pnt->phone_num = new char[strlen(phone_num)+1];

    strcpy(pnt->name, name);
    strcpy(pnt->company, company);
    strcpy(pnt->phone_num, phone_num);
    pnt->comp_pos = comp_pos;
    cout << pnt->name << " " << pnt->company << " " << pnt->phone_num << " " << pnt->comp_pos << endl;
    cout << this->pnt << endl;
    this->pnt = pnt;
}

NameCard::~NameCard() {}

void NameCard::ShowNameCardInfo()   
{
    cout << this->pnt << endl;
    cout << "이름 : " << pnt->name << endl;
    cout << "회사 : " << pnt->company << endl;
    cout << "휴대폰번호 : " << pnt->phone_num << endl;
    cout << "직급 : " << pnt->comp_pos << endl;
}

int main(void)
{    
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);    
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}