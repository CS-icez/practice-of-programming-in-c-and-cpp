#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
	void operator=(const char* s){   // 不是一个好的写法, 但足以通过本题
		r = 0, i = 0;
		int j = 0;
		for (; s[j] != '+'; ++j) r = r*10+s[j]-'0';
		for (++j; s[j] != 'i'; ++j) i = i*10+s[j]-'0';
	}
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}
