#include <iostream>
#include <string>
#include <stack>
using namespace std;

string ori, ans;
stack<int> stk;

int main(){
	while (cin >> ori){
		ans = ori;
		stk = stack<int>();
		
		for (unsigned i = 0; i < ori.size(); ++i)
			switch (ori[i]){
				case '(': stk.push(i); break;
				case ')':
					if (stk.empty()) ans[i] = '?';
					else ans[stk.top()] = ' ', ans[i] = ' ', stk.pop();
					break;
				default: ans[i] = ' '; break;
			}
			
		while (!stk.empty()) ans[stk.top()] = '$', stk.pop();
		cout << ori << endl << ans << endl;
	}
}
