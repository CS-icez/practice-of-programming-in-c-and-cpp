#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//全局变量
int Time;	//时间
const int N = 5;	//兵种
enum type_w{dragon, ninja, iceman, lion, wolf};	//武士名枚举
const char* name_w[N] = {"dragon", "ninja", "iceman", "lion", "wolf"};	//武士名字符串
int hp[N];	//武士初始生命值

class Headquarter{
private:
	string side;
	type_w name[N];	//武士名
	int total[N];	//某种武士总数，按type_w顺序
	int sum_total;	//所有武士总数
	int ele;	//生命元
	bool can_create;
	int now;	//该造谁了
	
	void generate(int pos){	//真实生成函数
		++total[pos]; ++sum_total;
		ele -= hp[pos];
		printf("%03d ", Time);
		cout << side;
		printf(" %s %d born with strength %d,%d %s in ",name_w[pos], sum_total, hp[pos], total[pos], name_w[pos]);
		cout << side;
		printf(" headquarter\n");
	}
public:
	Headquarter(string s, type_w id[5]){
		side = s;
		for (int i = 0; i < N; ++i)
			name[i] = id[i];
	}
	void reset(int x){
		memset(total, 0, sizeof total);
		sum_total = 0;
		ele = x;
		can_create = true;
		now = 0;
	}
	bool create(){	//生成武士外部接口，返回是否成功并输出信息
		if (!can_create) return false;
		for (int i = 0; i < N; ++i)
			if (hp[name[now]] <= ele){
				generate(name[now]);
				now = (now+1)%N;
				return true;
			}
			else now = (now+1)%N;
		printf("%03d ", Time);
		cout << side;
		printf(" headquarter stops making warriors\n");
		return can_create = false;
	}
};

int main(){
	int T;	//数据组数
	scanf("%d", &T);
	if (!T) return 0;
	int T1 = 1;	//目前所在数据组数
	
	type_w name_of_red[N]{iceman, lion, wolf, ninja, dragon};
	type_w name_of_blue[N]{lion, dragon, ninja, iceman, wolf};
	
	Headquarter redH("red", name_of_red);
	Headquarter blueH("blue", name_of_blue);
	int maxEle;
	string name;
	
Case:
	printf("Case:%d\n", T1++);
	Time = 0;
	scanf("%d", &maxEle);
	redH.reset(maxEle);
	blueH.reset(maxEle);
	
	for (int i = 0; i < N; ++i)
		scanf("%d", hp+i);
	
	for (bool f1 = true, f2 = true; f1||f2; ++Time){
		f1 = redH.create();
		f2 = blueH.create();
	}
	
	if (T1 <= T) goto Case;
}
