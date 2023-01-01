#include <iostream>
using namespace std;
class Mammal {
public:
  Mammal() { cout << "Mammal constructor...\n"; }
  virtual ~Mammal() { cout << "Mammal destructor...\n"; }
  Mammal (const Mammal & rhs);
  virtual void Speak() const { cout << "Mammal speak!\n"; }
  virtual Mammal* Clone() { return new Mammal(*this); }
};
  
class Dog : public Mammal {
public:
	Dog();
	~Dog();
	void Speak() const;
	
	Dog(const Dog& t): Mammal(t){
		cout << "Dog copy constructor..." << endl;
	}
	
	Dog* Clone(){return new Dog(*this);
	}
};

Mammal::Mammal (const Mammal & rhs) {
  cout << "Mammal Copy Constructor...\n";
}
  
Dog::Dog(){ cout << "Dog constructor...\n"; }
Dog::~Dog(){ cout << "Dog destructor...\n"; }
void Dog::Speak()const { cout << "Woof!\n"; }

int main() {
  Mammal* x=new Dog, *y=new Mammal;
  Mammal* x1=x->Clone(), *y1=y->Clone();
  x1->Speak(); y1->Speak();
  return 0;
}
