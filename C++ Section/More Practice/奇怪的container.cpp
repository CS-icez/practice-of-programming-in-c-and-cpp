#include <iostream>
#include <string>
using namespace std;
template <class T> 
class container{
private:
	T data;
public:
	container(T t): data(t){}
	T operator+(const container<T>& t){
		return data+t.data+t.data;
	}
	T operator+(const T& t){
		return data+t;
	}
};
int main(){
	int n,m;
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
    container <int> a = n;
    container <int> b = m;
    cout<<a+b<<endl;
    cout<<a+m<<endl;
    container <string> sa = string(s1);
    container <string> sb = string(s2);
    cout<<sa+sb<<endl;
    cout<< sa + s2<<endl;
}
