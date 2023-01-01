#include <cstdlib>
#include <iostream>
using namespace std;
int strlen(const char * s) 
{	int i = 0;
	for(; s[i]; ++i);
	return i;
}
void strcpy(char * d,const char * s)
{
	int i = 0;
	for( i = 0; s[i]; ++i)
		d[i] = s[i];
	d[i] = 0;
		
}
int strcmp(const char * s1,const char * s2)
{
	for(int i = 0; s1[i] && s2[i] ; ++i) {
		if( s1[i] < s2[i] )
			return -1;
		else if( s1[i] > s2[i])
			return 1;
	}
	return 0;
}
void strcat(char * d,const char * s)
{
	int len = strlen(d);
	strcpy(d+len,s);
}
class MyString
{
private:
	char* s{nullptr};
	unsigned len{0};
public:
	MyString(){}
	MyString(const char* p){
		len = strlen(p);
		s = new char[len+1];
		strcpy(s, p);
	}
	MyString(const MyString& r){
		len = r.len;
		s = new char[len+1];
		strcpy(s, r.s);
	}
	~MyString(){
		if (s != nullptr) delete[] s;
	}
	
	MyString& operator=(const MyString& r){
		if (s == r.s) return *this;
		len = r.len;
		if (s != nullptr) delete[] s;
		s = new char[len+1];
		strcpy(s, r.s);
		return *this;
	}
	friend MyString operator+(const MyString& a, const MyString& b){
		MyString res;
		res.len = a.len+b.len;
		res.s = new char[res.len+1];
		strcpy(res.s, a.s);
		strcpy(res.s+a.len, b.s);
		return res;
	}
	MyString& operator+=(const MyString& r){
		return *this = *this+r;
	}
	bool operator<(const MyString& r){
		return strcmp(s, r.s) == -1;
	}
	bool operator==(const MyString& r){
		return strcmp(s, r.s) == 0;
	}
	bool operator>(const MyString& r){
		return strcmp(s, r.s) == 1;
	}
	char& operator[](unsigned pos){
		return s[pos];
	}
	const MyString operator()(unsigned pos, unsigned size){
		MyString res;
		res.len = size;
		res.s = new char[size+1];
		for (unsigned i = 0; i < size; ++i)
			res.s[i] = s[pos+i];
		res.s[size] = '\0';
		return res;
	}
	
	friend ostream& operator<<(ostream& os, const MyString& r){
		if (r.s != nullptr) os << r.s;
		return os;
	}
};


int CompareString( const void * e1, const void * e2)
{
	MyString * s1 = (MyString * ) e1;
	MyString * s2 = (MyString * ) e2;
	if( * s1 < *s2 )
	return -1;
	else if( *s1 == *s2)
	return 0;
	else if( *s1 > *s2 )
	return 1;
}
int main()
{
	MyString s1("abcd-"),s2,s3("efgh-"),s4(s1);
	MyString SArray[4] = {"big","me","about","take"};
	cout << "1. " << s1 << s2 << s3<< s4<< endl;
	s4 = s3;
	s3 = s1 + s3;
	cout << "2. " << s1 << endl;
	cout << "3. " << s2 << endl;
	cout << "4. " << s3 << endl;
	cout << "5. " << s4 << endl;
	cout << "6. " << s1[2] << endl;
	s2 = s1;
	s1 = "ijkl-";
	s1[2] = 'A' ;
	cout << "7. " << s2 << endl;
	cout << "8. " << s1 << endl;
	s1 += "mnop";
	cout << "9. " << s1 << endl;
	s4 = "qrst-" + s2;
	cout << "10. " << s4 << endl;
	s1 = s2 + s4 + " uvw " + "xyz";
	cout << "11. " << s1 << endl;
	qsort(SArray,4,sizeof(MyString),CompareString);
	for( int i = 0;i < 4;i ++ )
	cout << SArray[i] << endl;
	//s1的从下标0开始长度为4的子串
	cout << s1(0,4) << endl;
	//s1的从下标5开始长度为10的子串
	cout << s1(5,10) << endl;
	return 0;
}
