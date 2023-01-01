#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
class C1{
private:
	int* p;
	int size;
public:
	C1(int _size, const vector<int>& v): size(_size){
		p = new int[size];
		for (int i = 0; i < size; ++i)
			p[i] = v[i];
	}
	int* operator*(){
		return p;
	}
	int& operator[](int pos){
		return p[size-1-pos];
	}
};

int main()
{
    vector<int> v;
    int p;
    int size;
    int k;
    cin >> k;
    while(k--){
        cin >> size;
        v.clear();
        for(int i = 0; i < size; ++i){
            cin >> p;
            v.push_back(p);
        }
        C1 o1 = C1(size,v);
        ostream_iterator<int> it(cout,"---");
        copy(*o1, (*o1)+size, it);
        cout<<endl;
        for(int i = 0; i < size; ++i){
            o1[i]*=2;
            cout<<o1[i]<<"***";
        }
        cout<<endl;
    }
    
}
