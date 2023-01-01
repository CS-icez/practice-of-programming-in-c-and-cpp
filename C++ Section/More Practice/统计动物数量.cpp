#include <iostream>
using namespace std;
class Animal{
public:
	inline static int number{0};
	Animal(){++number;}
	virtual ~Animal(){--number;}
};

class Cat: public Animal{
public:
	inline static int number{0};
	Cat(){++number;}
	~Cat(){--number;}
};

class Dog: public Animal{
public:
	inline static int number{0};
	Dog(){++number;}
	~Dog(){--number;}
};
void print() {
	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
}

int main() {
	print();
	Dog d1, d2;
	Cat c1;
	print();
	Dog* d3 = new Dog();
	Animal* c2 = new Cat;
	Cat* c3 = new Cat;
	print();
	delete c3;
	delete c2;
	delete d3;
	print();
}
