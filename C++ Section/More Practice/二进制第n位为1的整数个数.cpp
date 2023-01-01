#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Pred{
public:
	int n;
	Pred(int _n): n(_n){}
	bool operator()(int t){return t&(1<<n);}
};
int main(int argc, char** argv) {	
	int n, x;
	vector<int> intVec;
	cin>>n>>x; 
	while(x) {
		intVec.push_back(x);
		cin>>x;
	}
	cout<<count_if(intVec.begin(), intVec.end(), Pred(n))<<endl;
	return 0;
}
