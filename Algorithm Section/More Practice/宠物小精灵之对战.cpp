#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <bitset>
#include <map>
#include <queue>
#include <set>
using namespace std;

const int N = 333;
bool vic[N][N];
bool l[N][N], r[N][N];

int main(){
	int n;
	cin >> n;
	char ch;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			cin >> ch;
			vic[i][j] = (ch=='W');
		}
	
	for (int i = 1; i <= n; ++i)
		l[i][i] = r[i][i] = 1;
	
	for (int i = n-1; i; --i)
		for (int j = i+1; j <= n; ++j){
			for (int k = i+1; k <= j && !l[i][j]; ++k)
				if (r[i+1][k] && l[k][j] && vic[i][k])
					l[i][j] = 1;
			for (int k = i; k < j && !r[i][j]; ++k)
				if (r[i][k] && l[k][j-1] && vic[j][k])
					r[i][j] = 1;
		}
	
	for (int i = 1; i <= n; ++i)	
		if (r[1][i] && l[i][n])
			cout << i << " ";
	
}
