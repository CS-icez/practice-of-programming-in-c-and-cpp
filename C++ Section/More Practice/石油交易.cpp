#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map<int, int> oil;	//price, left

int main(){
	oil[40] = 1e9;
	int N, x, y, z, sum;
	cin >> N;
	string op;
		
	while (N--){
		cin >> op;
		if (op == "SELL"){
			cin >> x >> y;
			oil[y] += x;
		}
		else{
			cin >> z;
			sum = 0;
			for (auto it = oil.begin(); z; ++it){
				if (!it->second) continue;
				int t = min(it->second, z);
				sum += it->first*t;
				z -= t;
				it->second -= t;
			}
			cout << sum << endl;
		}
	}	
}
