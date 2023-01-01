#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;

class TV_Drama{
	public:
	char name[100];
	int actor;
	int story;
	int acting_skill;
	TV_Drama(char* _name, int _actor, int _story, int _acting_skill):
			actor(_actor), story(_story), acting_skill(_acting_skill){
		unsigned len = strlen(_name);
		while (~len) name[len] = _name[len], --len;
	}
	bool operator<(const TV_Drama& t){
		return actor > t.actor;
	}
};
void Printer(const TV_Drama& t){
	cout << t.name << ";";
}

bool comparator_1(const TV_Drama& a, const TV_Drama& b){
	return a.story > b.story;
}

class comparator_2{
public:
	bool operator()(const TV_Drama& a, const TV_Drama& b){
		return a.acting_skill > b.acting_skill;
	}
};
int main(){
	list<TV_Drama> lst;
	int n;
	
	cin>>n;
	char  _name[100];
	int _actor, _story, _acting_skill;
	for (int i=0; i<n; i++){
        cin.ignore();
        cin.getline(_name,100);
        cin>>_actor>>_story>>_acting_skill;
		lst.push_back(TV_Drama(_name, _actor, _story, _acting_skill));
	}

	lst.sort();
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	lst.sort(comparator_1);
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	lst.sort(comparator_2());
	for_each(lst.begin(), lst.end(), Printer);	
	cout<<endl;

	return 0;
}
