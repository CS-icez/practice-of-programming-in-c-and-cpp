#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const int N = 29;
int n;
bool avi[N][N];
int col[N], cnt;
bool book[N];

int main(){
	while (cin >> n, n){
		memset(avi, 0, sizeof avi);
		
		char ch;
		for (int i = 0; i < n; ++i){
			cin >> ch;
			int a = ch-'A';
			cin.ignore();
			while ((ch = getchar()) != '\n')
				avi[a][ch-'A'] = 1;
		}
		
		col[0] = 1, cnt = 1;
		
		for (int i = 1; i < n; ++i){
			memset(book, 0, sizeof book);
			for (int j = 0; j < i; ++j)
				if (avi[i][j]) book[col[j]] = 1;
			int t = 0;
			for (int j = 1; j <= cnt; ++j)
				if (!book[j]){
					t = j;
					break;
				}
			
			if (t) col[i] = t;
			else col[i] = ++cnt;
		}
		
		cout << cnt << " channel";
		if (cnt > 1) cout << "s";
		cout << " needed.\n";
	}
}
