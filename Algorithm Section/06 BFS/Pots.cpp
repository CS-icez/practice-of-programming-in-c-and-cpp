#include <iostream>
#include <string>
#include <cstring>
using namespace std;



struct Node{
	int l, r, lst, op;	//lst use op to reach this node
};

int a, b, c;
Node q[10000];
int step[111][111];
int head = 0, tail = 0;
string name[6]{"FILL(1)", "FILL(2)", "DROP(1)",
			"DROP(2)", "POUR(1,2)", "POUR(2,1)"};

void output(int idx){
	if (~q[idx].lst){		
		output(q[idx].lst);
		cout << name[q[idx].op] << endl;
	}
}

void bfs(){
	while (head < tail){
		Node cur = q[head];
		for (int i = 0, l1, r1; i < 6; ++i){
			switch (i){
				case 0:
					l1 = a; r1 = cur.r; break;
				case 1:
					r1 = b; l1 = cur.l; break;
				case 2:
					l1 = 0; r1 = cur.r; break;
				case 3:
					r1 = 0; l1 = cur.l; break;
				case 4:
					if (cur.l < b-cur.r)
						l1 = 0, r1 = cur.r+cur.l;
					else
						l1 = cur.l-b+cur.r, r1 = b;
					break;
				case 5:
					if (cur.r < a-cur.l)
						r1 = 0, l1 = cur.r+cur.l;
					else
						r1 = cur.r-a+cur.l, l1 = a;
					break;
			}
			if (~step[l1][r1]) continue;
			
			step[l1][r1] = step[cur.l][cur.r]+1;
			q[tail++] = {l1, r1, head, i};
			
			if (l1 == c || r1 == c){
				cout << step[l1][r1] << endl;
				output(tail-1);
				return;
			}
			
		}
		++head;
	}
	cout << "impossible";
}

int main(){
	cin >> a >> b >> c;
	memset(step, -1, sizeof step);
	
	if (c == 0){
		cout << 0 << endl;
		return 0;
	}
	
	q[tail++] = {0, 0, -1, 0};
	step[0][0] = 0;

	bfs();
}
