#include <iostream>
#include <string>
using namespace std;

const int op[10][6] = {{}, {1, 2, 4, 5}, {1, 2, 3}, {2, 3, 5, 6}, {1, 4, 7},
				{2, 4, 5, 6, 8}, {3, 6, 9}, {4, 5, 7, 8}, {7, 8, 9},
				{5, 6, 8, 9}};

inline void turn(string& str, int x){
	for (int i = 0; op[x][i]; ++i)
		str[op[x][i]] = (str[op[x][i]]+1)%4;
}

inline bool check(string& str){
	for (int i = 1; i <= 9; ++i)
		if (str[i]) return 0;
	return 1;
}

#define f(i) for (a[i] = 0; a[i] < 4; ++a[i])
#define g for (int i = 1; i <= 9; ++i)

int main(){
	string ori("0"), cur, sq;
	char c;
	for (int i = 0; i < 9; ++i){
		cin >> c;
		ori += c-'0';
	}
	
	int step = 1e9, a[10];

	f(1) f(2) f(3) f(4) f(5) f(6) f(7) f(8) f(9){
		cur = ori;
		int sum = 0;
		g sum += a[i];
		if (sum >= step) continue;
		g for (int j = 0; j < a[i]; ++j)
			turn(cur, i);
		if (!check(cur)) continue;
		step = sum;
		sq = "0";
		g sq += a[i];
	}
	
	for (int i = 1, flag = 0; i <= 9; ++i)
		while (sq[i]--){
			if (flag) cout << " ";
			cout << i;
			flag = 1;
		}
}
