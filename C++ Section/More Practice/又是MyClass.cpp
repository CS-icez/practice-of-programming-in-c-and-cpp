#include <iostream>
#include <cstring> 
#include <vector>
#include <cstdio> 
using namespace std;
template<class T>
class CMyClass{
private:
	T* p;
	unsigned len;
public:
	CMyClass(T* _p, unsigned _len): len(_len){
		p = new T[len];
		for (unsigned i = 0; i < len; ++i)
			p[i] = _p[i];
	}
	T& operator[](unsigned pos){
		return p[pos];
	}
};
int  a[40];
int main(int argc, char** argv) {
	int t;
	scanf("%d",&t);
	while ( t -- ) {
		int m;
		scanf("%d",&m);
		for (int i = 0;i < m; ++i) 
			scanf("%d",a+i);
		char s[100];
		scanf("%s",s);
		CMyClass<int> b(a, m);
		CMyClass<char> c(s, strlen(s));
		printf("%d %c\n", b[5], c[7]);
	}
	return 0;
}
