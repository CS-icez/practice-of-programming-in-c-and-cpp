#include <set>
#include <iostream>
using namespace std;
template <class T>
class MySet: public set<T> {
public:
	using Base = set<T>;
	void insert(const T& t){
		if (!Base::insert(t).second) cout << "Error insert " << t << endl;
	}
	void erase(const T& t){
		if (!Base::count(t)) cout << "Error erase " << t << endl;
		else Base::erase(t);
	}
};
int main(){
	int n; scanf("%d",&n);
	MySet<int> S;
	for (int i=1;i<=n;i++){
		cout<<"Operation #"<<i<<":"<<endl;
		string type; int w;
		cin>>type>>w;
		if (type=="insert") S.insert(w);
		else if (type=="erase") S.erase(w);
	}
	cout<<endl;
	MySet<string> S2;
	for (int i=1;i<=n;i++){
		cout<<"Operation #"<<i<<":"<<endl;
		string type; string w;
		cin>>type>>w;
		if (type=="insert") S2.insert(w);
		else if (type=="erase") S2.erase(w);
	}
}
