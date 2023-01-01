#include <iostream>
#include <map>
using namespace std;

map<int, int> mp;	//strength, id

int main(){
	mp[1e9] = 1;
	int n, id, strength;
	cin >> n;
	
	while (n--){
		cin >> id >> strength;
		cout << id << " ";
		
		auto up = mp.upper_bound(strength);
		if (up == mp.begin()) cout << up->second << endl;
		else{
			auto lp = up; --lp;
			if (lp->first+up->first < 2*strength)
				cout << up->second << endl;
			else
				cout << lp->second << endl;
		}
		mp[strength] = id;
	}
}
