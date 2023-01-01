#include <iostream>
#include <string>
#include <set>
using namespace std;

struct Dir{
	string name;
	Dir* dir[33]{};
	int nDir{0};
	set<string> files{};
};

void readDir(Dir* dir){
	string temp;
	while (cin >> temp){
		if (temp == "]") break;
		if (temp[0] == 'f')
			dir->files.insert(temp);
		else{
			dir->dir[dir->nDir] = new Dir{temp};
			readDir(dir->dir[dir->nDir]);
			++dir->nDir;
		}
	}
}

void output(const Dir* dir, int indent){
	for (int i = 0; i < indent; ++i)
		cout << "|     ";
	cout << dir->name << endl;
	
	for (int i = 0; i < dir->nDir; ++i){
		output(dir->dir[i], indent+1);
		delete dir->dir[i];
	}
		
	for (const auto& t: dir->files){
		for (int i = 0; i < indent; ++i)
			cout << "|     ";
		cout << t << endl;
	}
}

int main(){	
	int cnt = 0;
	string input;
	while (cin >> input){
		if (input == "#") break;
		
		cout << "DATA SET " << (++cnt) << ":" << endl;
		
		Dir rt;
		rt.name = "ROOT";
		
		while (1){
			if (input == "*"){
				output(&rt, 0);
				break;
			}
			
			if (input[0] == 'f') 
				rt.files.insert(input);
			else{
				rt.dir[rt.nDir] = new Dir{input};
				readDir(rt.dir[rt.nDir]);
				++rt.nDir;
			}
			
			
			cin >> input;
		}
		cout << endl;
	}
	
}
