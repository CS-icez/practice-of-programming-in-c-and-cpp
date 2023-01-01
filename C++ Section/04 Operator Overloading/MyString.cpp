#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class MyString {
	char * p;
public:
	MyString(const char * s) {
		if( s) {
			p = new char[strlen(s) + 1];
			strcpy(p,s);
		}
		else
			p = NULL;

	}
	~MyString() { if(p) delete [] p; }
	MyString(const MyString& t){
		p = new char[strlen(t.p)+1];
		strcpy(p, t.p);
	}
	
	void Copy(const char* s){
		p = new char[strlen(s) + 1];
		strcpy(p,s);
	}
	
	operator const char*(){
		return p;
	}
	
	MyString& operator=(const MyString& t){
		p = new char[strlen(t.p)+1];
		strcpy(p, t.p);
		return *this;
	}
};
int main()
{
	char w1[200],w2[100];
	while( cin >> w1 >> w2) {
		MyString s1(w1),s2 = s1;
		MyString s3(NULL);
		s3.Copy(w1);
		cout << s1 << "," << s2 << "," << s3 << endl;

		s2 = w2;
		s3 = s2;
		s1 = s3;
		cout << s1 << "," << s2 << "," << s3 << endl;
		
	}
}
