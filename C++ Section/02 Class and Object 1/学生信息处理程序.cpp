#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
using namespace std;

class Student {
private:
	int age, id;
	char name[23]{};
	int s[4];
	double avg;
public:
	void input(){
		char c;
		cin.getline(name, 20, ',');
		scanf("%d%c", &age, &c);
		scanf("%d%c", &id, &c);
		for (int i = 0; i < 4; ++i)
			scanf("%d%c", &s[i], &c);
	}
	void calculate(){
		avg = 0;
		for (int i = 0; i < 4; ++i)
			avg += s[i];
		avg /= 4;
	}
	void output(){
		cout << name << "," << age << "," << id
			<< "," << avg;
	}
};

int main() {
	Student student;        // 定义类的对象
	student.input();        // 输入数据
	student.calculate();    // 计算平均成绩
	student.output();       // 输出数据
}
