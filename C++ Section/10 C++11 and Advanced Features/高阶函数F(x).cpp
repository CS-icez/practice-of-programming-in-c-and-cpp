#include <iostream>
using namespace std;
template <class T, class U>
auto f(T t){
	return [t](U u){return u+t;};
};
int main()
{
   cout << f<int,int>(7)(9) << endl;   //16
   cout << f<string,string> (" hello!")("world")  <<endl; // world hello!
   cout << f<char,string> ('!')("world") << endl;
   
   
   return 0;    //world!
}
