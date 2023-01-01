#include <iostream>
using namespace std;

// 该题的标准做法是重载->, 不过, 没有什么是加一个中间过程解决不了的:)

struct A;
struct D{
	int v;
	A* operator+(const A* t);
};
	
struct A{
	int v;
	A(int _v): v(_v){}
	int get_value(){return v;}
	
	D operator+(const A* t){
		return D{v+t->v};
	}
};

A a(0);

A* D::operator+(const A* t){
	a.v = v+t->v;
	return &a;
}

struct B: public A{
	B(int _v): A(_v){}
};
struct C: public A{
	C(int _v): A(_v){}
};
int main() {
    int t;
    cin >> t;
    while (t --){
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        A a(aa);
        B b(bb);
        C c(cc);
        A* x = &a;
        A* y = &b;
        A* z = &c;
        cout << (x->get_value() + y->get_value() + z->get_value()) << " ";
        cout << ((*x) + y + z)->get_value() << endl;
    }
    return 0;
}
