#include <iostream>
using namespace std;
class CMyClassA {
	int val;
public:
	CMyClassA(int);
	void virtual print();
};
CMyClassA::CMyClassA(int arg) {
	val = arg;
	printf("A:%d\n", val);
}
void CMyClassA::print() {
	printf("%d\n", val);
	return;
}
class CMyClassB: public CMyClassA{
private:
	int val2;
public:
	CMyClassB(int t): CMyClassA(3*t), val2(t){
		cout << "B:" << t << endl;
	}
	void print(){
		cout << val2 << endl;
	}
};
int main(int argc, char** argv) {
	CMyClassA a(3), *ptr;
	CMyClassB b(5);
	ptr = &a; ptr->print();
	a = b;
	a.print();
	ptr = &b; ptr->print();
	return 0;
}
