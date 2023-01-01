#include <iomanip>
#include <iostream>
using namespace std;

class TNone {};
TNone None;
template<class T>
class Option{
public:
	T data;
	bool b;
	Option(){
		b = 0;
	}
	Option(TNone){
		b = 0;
	}
	Option(const T& t){
		data = t;
		b = 1;
	}
	string has_value(){
		return b? "true": "false";
	}
	const T& value() const{
		return data;
	}
	void operator=(TNone){
		b = 0;
	}
	operator bool() const{
		return b;
	}
	T& operator*(){
	return data;}
	const T& operator*() const{
	return data;}
};
int main() {
  cout << boolalpha;

  Option<int> a(0), b, c(1);
  cout << a.has_value() << endl;
  cout << b.has_value() << endl;
  b = a;
  *b += 10;
  cout << a.value() << endl;
  cout << b.value() << endl;
  c = None;
  cout << c.has_value() << endl;

  Option< Option<int> > x = None;
  const Option< Option<int> > y = a;
  Option< Option<int> > z = c;
  if (x)
    cout << "x has value" << endl;
  if (y)
    cout << "y has value" << endl;
  if (z)
    cout << "z has value" << endl;
  x = y;
  x = x;
  *x = b;
  **x = 20;
  cout << x.value().value() + **y << endl;
  return 0;
}
