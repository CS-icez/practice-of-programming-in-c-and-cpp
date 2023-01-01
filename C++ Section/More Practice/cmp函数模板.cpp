#include <vector>
#include <set>
#include <list>
#include <iostream>
using namespace std;

template <class T>
void cmp(T, int){
	#include <typeinfo>
	static char c = 'a';
	if (typeid(T) == typeid(int)) cout << (c++) << endl;
	else cout << "c" << endl;
}
int main(){
  int A[100];
  A[0]=1; A[1]=2;
  cmp(A[0],2);
  printf("finish 1\n");
  cmp(1, A[1]);
  printf("finish 2\n");
  cmp(A,A[1]);
  printf("finish 3\n");
}
