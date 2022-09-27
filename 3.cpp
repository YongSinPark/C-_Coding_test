#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX_NUM 20

using namespace std;

class Array_sort
{
private:
    int arr[MAX_NUM];
    
public:
    Array_sort();
    virtual ~Array_sort();
    int temp;
    std::vector<int> vecArr;
    void Input_array();
    void Print_arr();
    void Sort_array();
    bool Find_index();
};

Array_sort::Array_sort(){}
Array_sort::~Array_sort(){}

void Array_sort::Input_array()
{
	while(1)
	{
		cout << "배열 값을 입력하세요 : ";
    	cin >> temp;
    	if(temp == -1) break;
    	vecArr.push_back(temp);	
	}
}

void Array_sort::Print_arr()
{
	vector<int>::iterator itr;
	
	cout << "sort 전 : "; 
    for(itr = vecArr.begin(); itr != vecArr.end(); itr++)
    {
    	cout << *itr << " ";
    }
    cout << endl;
}

void Array_sort::Sort_array()
{
    vector<int>::iterator itr;
    cout << "sort 후 : ";
    sort(vecArr.begin(), vecArr.end());
    for(itr = vecArr.begin(); itr != vecArr.end(); itr++)
    {
    	cout << *itr << " ";
	}
	cout << endl;
}

bool Array_sort::Find_index()
{
    int tmp;
    cout << "찾고싶은 숫자를 입력하세요 : ";
    cin >> tmp;
    
    vector<int>::iterator itr;
    for (itr = vecArr.begin(); itr != vecArr.end(); itr++)
    {
        if(*itr == tmp) 
        {
            cout << "찾았습니다! Return true!\n";
            return true;
        }
    }
    cout << "찾는 숫자가 없습니다. Return false!\n";
    return false;
}

int main()
{
	Array_sort* array_sort = new Array_sort();
	
	array_sort->Input_array();
	array_sort->Print_arr();
	array_sort->Sort_array();
	array_sort->Find_index();
	
	return 0;
}