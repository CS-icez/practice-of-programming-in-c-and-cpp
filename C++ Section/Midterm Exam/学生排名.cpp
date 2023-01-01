#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef pair<string, int> PAIR;
class MyMap:public map<string, int>
{
public:
	struct S{
		string name;
		int gpa;
		bool operator<(const S& s) const{
			if (gpa != s.gpa) return gpa > s.gpa;
			if (name.length() != s.name.length()) return name.length() < s.name.length();
			return name < s.name;
		}
	};
	set<S> s;
	friend istream& operator>>(istream& is, MyMap& m){
		string t; int r;
		cin >> t >> r;
		for (auto it = m.s.begin(); it != m.s.end(); ++it)
			if (it->name == t) return is;
		m.s.insert({t, r});
		return is;
	}
	friend ostream& operator<<(ostream& os, MyMap& m){
		for (auto it = m.s.begin(); it != m.s.end(); ++it){
			cout << it->name << " " << it->gpa << endl;
		}
		return os;
	}
};
int main()
{
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		MyMap mm;
		for (int i = 0; i < n; ++i)
			cin >> mm;
		cout<<mm;
        
	}
	return 0; 
}
