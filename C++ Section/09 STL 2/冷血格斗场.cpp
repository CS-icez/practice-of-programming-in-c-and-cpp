#include <iostream>
#include <map>
#include <utility>
using namespace std;

map<int, int> mp;	//pow, id

int main(){
	mp[1e9] = 1;
	int n, id, pow, oppo;
	cin >> n;
	
	while (n--){
		cin >> id >> pow;
		auto up = mp.lower_bound(pow);
		if (up == mp.begin() || up->first == pow) 
			oppo = up->second;
		else{
			auto low = up; --low;
			int pl = low->first, pu = up->first, il = low->second, iu = up->second;
			
			if (pu+pl != 2*pow) 
				oppo = (pu+pl < 2*pow? iu: il);
			else oppo = (iu < il? iu: il);
		}
		
		cout << id << " " << oppo << endl;
		if (!mp.count(pow) || mp[pow] > id)
			mp[pow] = id;
	}
}
