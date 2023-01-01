#include <iostream>
#include <cstring>
using namespace std;

class Array2 {
public:
	int* p;
	int r, c;
	Array2(int a, int b){
		r = a, c = b;
		p = new int[a*b];
	}
	Array2() = default;
	Array2& operator=(const Array2& t){
		r = t.r, c = t.c;
		p = new int[r*c];
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				p[i*c+j] = t.p[i*c+j];
		return *this;
	}
	~Array2(){
		delete[] p;
	}
	int* operator[](int t){
		return p+c*t;
	}
	int operator()(int i, int j){
		return *(p+c*i+j);
	}
};

int main() {
    Array2 a(3,4);
    int i,j;
    for(  i = 0;i < 3; ++i )
        for(  j = 0; j < 4; j ++ )
            a[i][j] = i * 4 + j;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << a(i,j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;     b = a;
    for(  i = 0;i < 3; ++i ) {
        for(  j = 0; j < 4; j ++ ) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
