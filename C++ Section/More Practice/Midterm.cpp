#include<iostream>
using namespace std;

class Midterm {
private:
  int val; 
public:
	Midterm(int x = 0){
		val = x;
	}
	friend Midterm operator+(const Midterm& a, int t){
		return Midterm(a.val+t);
	}
	Midterm& operator++(int){
		++val;
		return *this;
	}
	operator int(){
		return val;
	}
	Midterm& operator-=(int x){
		val -= x;
		return *this;
	}
};

int Min(int a,int b) {
  if(a < b)
    return a;
  else
    return b;
}
int main(){
  Midterm a; 
  cout << a << endl;
  cout << a + 2021 << endl;
  Midterm b(1000);
  cout << b ++ << endl; 
  ((b-=10)-=20)-=30;
  cout << b ++ << endl; 
  cout << Min(255,b) <<endl;
  return 0;
}
