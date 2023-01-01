#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
class CMean {
private:
	int& r;
	int total{0};
	int n{0};
public:
	CMean(int& t): r(t){}
	void operator()(int t){
		total += t;
		r = total / ++n;
	}
};

int main(int argc, char* argv[]) {
	int  v;
	int t;
	cin >> t;
	while ( t -- ) {
		cin >> v;
		vector<int> vec;
		while (v) {
			vec.push_back(v);
			cin >> v;
		}
		int myAver = 0;
		for_each(vec.begin(), vec.end(), CMean(myAver));
		cout << myAver << endl;
	}
	return 0;
}
