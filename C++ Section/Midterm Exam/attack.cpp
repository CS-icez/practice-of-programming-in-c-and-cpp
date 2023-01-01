#include <iostream>
#include <string>
using namespace std;

class Slime{
public:
	Slime(){
		cout << "A slime appears..." << endl;
	}
	virtual string name(){
		return "Slime";
	}
	virtual ~Slime(){
		cout << "A slime disappears..." << endl;
	}
	void attack(Slime* p){
		cout << name();
		cout << " attacked ";
		cout << p->name() << endl;
	}
};
	
class HydroSlime: public Slime{
public:
	string name() {return "Hydro Slime";}
	HydroSlime() {cout << "A hydro slime appears...\n";}
	~HydroSlime() {cout << "A hydro slime disappears...\n";}
};

class PyroSlime: public Slime{
public:
	string name () {return "Pyro Slime";}
	PyroSlime() {cout << "A pyro slime appears...\n";}
	~PyroSlime() {cout << "A pyro slime disappears...\n";}
};

int main(){
	Slime *a = new HydroSlime, *b = new PyroSlime;
	a->attack(b);
	b->attack(a);
	delete a;
	delete b;
	return 0;
}
