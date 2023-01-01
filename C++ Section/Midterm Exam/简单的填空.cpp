#include <iostream>
using namespace std;

class A
{
public:
	inline static int n{0};
	static int a;
	static int b;
	void f(){
		++n;
		switch(n){
			case 2: a = 4, b = 2; break;
			case 3: a = 3, b = 1; break;
			case 4: a = 5, b = 2; break;
			case 5: a = 4, b = 1; break;
		}
	}
	A(){
		f();
	}
	~A(){
		f();
	}
};
int A::a = 0;
int A::b = 0;

int main()
{
    A x;
    {
        A y;
        cout << "1: " << A::a << " " << A::b << endl;
    }
    cout << "2: " << A::a << " " << A::b << endl;

    A *p = new A();
    cout << "3: " << A::a << " " << A::b << endl;

    delete p;
    cout << "4: " << A::a << " " << A::b << endl;
    return 0;
}
