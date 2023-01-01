//Head.h
#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <assert.h>
using namespace std;

extern int Hour, Minute;	//当前时间
extern const int N;	//兵种数
enum type_w{dragon, ninja, iceman, lion, wolf};	//武士名枚举
extern const char* name_w[];	//武士名字符串
extern int init_hp[], init_atk[];	//武士初始生命值、攻击力
enum type_weapon{sword, bomb, arrow};	//武器名枚举
extern const char* name_weapon[3];	//武器名字符串
enum type_side{red, blue};	//阵营枚举
extern const char* name_side[2];	//阵营字符串
extern int nCity, K;	//城市总数，忠诚度梯度

class Creature;

class City{
	friend class GameControl;
private:
	Creature* r{nullptr};
	Creature* b{nullptr};
	int id;
	
public:
	void set(int t);	//设置编号
	void fight();	//战斗
	void leave(type_side col);
	void enter(type_side col, Creature* war);
};

extern City city[];	//城市

class Weapon{
	friend class GameControl;
	friend bool cmp_weapon_1(const Weapon* a, const Weapon* b);	//排序规则
	friend bool cmp_weapon_2(const Weapon* a, const Weapon* b);	//排序规则
	friend class Wolf;
	friend void City::fight();
private:
	type_weapon type;	//类型
	int coeff, dua;	//伤害系数，耐久
	Creature* owner;	//持有者
	int avi{1};	//是否可用
	
public:	
	Weapon(type_weapon T);	//构造
	type_weapon getType();	//返回类型
	//void attack(Creature& enemy);	//攻击
	bool used();
	bool get_avi();
	int get_coeff();
};

bool cmp_weapon_1(const Weapon* a, const Weapon* b);
bool cmp_weapon_2(const Weapon* a, const Weapon* b);

class Creature{
	friend class GameControl;
	friend class Wolf;
	friend void City::fight();
protected:
	int id, health, atk, pos;	//编号，生命值，攻击力，位置
	type_side side;	//阵营
	type_w type;	//类型
	Weapon* w[10]{};	//武器
	int sum_wp{0};	//持有武器数
	int s, b, a;	//各类武器数
	int alive{1};
	
	void run();
	
public:
	Creature(int tot, type_side col, type_w T);	//构造
	virtual ~Creature();
	
	void makeWeapon(type_weapon T);	//制作武器
	int getAtk();	//返回攻击力
	void hurted(int damage);	//受伤
	void attack(int weapon_id, Creature& enemy);	//攻击
	void sortWeapon(int method);	//整理武器
	int get_sum_wp();	//返回武器数量
	type_w getType();	//返回类型
	virtual void endFight() = 0;	//战斗结束后行为
	virtual void birth() = 0;	//诞生后行为
	virtual bool timeToRun();	//不得不用虚函数，只有Lion予以实现
	virtual void moveAction() = 0;	//前进后行为
	virtual void snatch(Creature& enemy);
};

class Dragon: public Creature{
	friend class GameControl;
private:
	double morale;	//士气
public:
	Dragon(int tot, int ele, type_side col);	//构造
	void birth();
	void endFight();
	void moveAction();
};

class Ninja: public Creature{
	friend class GameControl;
private:
public:
	Ninja(int tot, type_side col);	//构造
	void birth();
	void endFight();
	void moveAction();
};

class Iceman: public Creature{
	friend class GameControl;
private:
public:
	Iceman(int tot, type_side col);	//构造
	void birth();
	void endFight();
	void moveAction();
};

class Lion: public Creature{
	friend class GameControl;
private:
	int loyalty;
public:
	Lion(int tot, int ele, type_side col);	//构造
	void birth();
	void endFight();
	bool timeToRun();
	void moveAction();
};

class Wolf: public Creature{
	friend class GameControl;
public:
	Wolf(int tot, type_side col);	//构造
	void birth();
	void endFight();
	void moveAction();
	void snatch(Creature& enemy);
};

class Headquarter{
	friend class GameControl;
private:
	type_side side;	//阵营
	type_w name[5];	//武士制造顺序
	//int total[5];	//某种武士总数，按type_w顺序
	int sum_total;	//所有武士总数
	int ele;	//生命元
	int can_create;	//有制造能力
	int now;	//该造谁了
	Creature* warrior[110];	//武士
	
	void builtin_creature(type_w type);	//制造武士
	
public:
	Headquarter(type_side s, type_w id[5]);	//构造
	void reset(int x);	//重置
	~Headquarter();	//析构
	
	void create();	//制造武士外部接口
};

class GameControl{
public:
	static GameControl& createObj();
	void headquarterGenerate();
	void lionRun();
	void moveForward();
	void wolfSnatch();
	void warriorFight();
	void headquarterReport();
	void warriorReport();
	
	void reset(int x);	//重置
	bool game_over();
	
private:
	type_w name_of_red[5]{iceman, lion, wolf, ninja, dragon};
	type_w name_of_blue[5]{lion, dragon, ninja, iceman, wolf};
	GameControl() = default;
	GameControl(const GameControl&) = delete;
	static GameControl gc;
	Headquarter redH{red, name_of_red};
	Headquarter blueH{blue, name_of_blue};
	int gameOver = 0;
	
	void endGame(type_side winner, type_side loser, const Creature* war);
	void builtin_warriorReport(Creature* t);
};


//City.cpp
//#include "Head.h"

void City::fight(){
	if (!r || !b) return;
	r->sortWeapon(1); b->sortWeapon(1);
	
	int r_wp = 0, b_wp = 0;
	
	if (id&1 && r->sum_wp > 0) r->attack(r_wp++, *b);
	
	int T = 1000;
	
	while (T--){
		if (!b->sum_wp && !r->sum_wp) break;
		if (!r->alive || !b->alive) break;
		
		for (int i = 0; i < 10; ++i, b_wp = (b_wp+1)%10)
			if (b->w[b_wp] != nullptr) break;
		if (b->w[b_wp]) b->attack(b_wp, *r);
		b_wp = (b_wp+1)%10;
		
		if (!r->alive || !b->alive) break;
		
		for (int i = 0; i < 10; ++i, r_wp = (r_wp+1)%10)
			if (r->w[r_wp] != nullptr) break;
		if (r->w[r_wp]) r->attack(r_wp, *b);
		r_wp = (r_wp+1)%10;
	}
	
	if (r->alive && b->alive)
		printf("%03d:%02d both red %s %d and blue %s %d were alive in city %d\n", 
				Hour, Minute, name_w[r->type], r->id, name_w[b->type], b->id, id);
	else if (!r->alive && !b->alive)
		printf("%03d:%02d both red %s %d and blue %s %d died in city %d\n",
				Hour, Minute, name_w[r->type], r->id, name_w[b->type], b->id, id);
	else if (r->alive)
		printf("%03d:%02d red %s %d killed blue %s %d in city %d remaining %d elements\n",
				Hour, Minute, name_w[r->type], r->id, name_w[b->type], b->id, id, r->health);
	else
		printf("%03d:%02d blue %s %d killed red %s %d in city %d remaining %d elements\n",
				Hour, Minute, name_w[b->type], b->id, name_w[r->type], r->id, id, b->health);
	
	if (r->alive) r->endFight();
	if (b->alive) b->endFight();
			
	if (r->alive && !b->alive) r->Creature::snatch(*b);
	else if (b->alive && !r->alive) b->Creature::snatch(*r);
	
	if (!b->alive) leave(blue);
	if (!r->alive) leave(red);
}
	
void City::set(int t){
	id = t;
}

void City::leave(type_side col){
	if (col == red) r = nullptr;
	else if (col == blue) b = nullptr;
}

void City::enter(type_side col, Creature* war){
	if (col == red) r = war;
	else if (col == blue) b = war;
}


//Creature.cpp
//#include "Head.h"

Creature::Creature(int tot, type_side col, type_w T): id{tot}, side{col}, type{T}{
	pos = side==red? 0: nCity+1;
	health = init_hp[type];
	atk = init_atk[type];
}

Creature::~Creature(){
	for (int i = 0; i < 10; ++i){
		if (!w[i]) continue;
		delete w[i];
		w[i] = nullptr;
	}
}

void Creature::makeWeapon(type_weapon T){
	w[sum_wp] = new Weapon(T);
	++sum_wp;
}

int Creature::getAtk(){
	return atk;
}

void Creature::hurted(int damage){
	health -= damage;
	if (health <= 0) alive = 0;
}

void Creature::attack(int weapon_id, Creature& enemy){
	int damage = atk*w[weapon_id]->get_coeff()/10;
	enemy.hurted(damage);
	if (w[weapon_id]->getType() == bomb && type != ninja) hurted(damage/2);
	
	bool avi = w[weapon_id]->used();
	if (!avi){
		delete w[weapon_id];
		w[weapon_id] = nullptr;
		--sum_wp;
	}
	
	if (health <= 0) alive = 0;
	if (enemy.health <= 0) enemy.alive = 0;
}

void Creature::sortWeapon(int method){
	s = b = a = 0;
	for (int i = 0; i < 10; ++i){
		if (w[i] == nullptr) continue;
		switch(w[i]->getType()){
			case sword: ++s; break;
			case bomb: ++b; break;
			case arrow: ++a; break;
		}
	}
	sum_wp = s+b+a;
	if (method == 1) sort(w, w+10, cmp_weapon_1);
	else if (method == 2) sort(w, w+10, cmp_weapon_2);
}

type_w Creature::getType(){
	return type;
}

void Creature::run(){
	alive = 0;
	if (side == red) city[pos].leave(red);
	else city[pos].leave(blue);
}

void Creature::moveAction(){
	if (side == red) ++pos;
	else --pos;
	if (side == red && pos == nCity+1) return;
	if (side == blue && pos == 0) return;
	printf("%03d:%02d %s %s %d marched to city %d with %d elements and force %d\n",
			Hour, Minute, name_side[side], name_w[type], id, pos, health, atk);
}

int Creature::get_sum_wp(){
	return sum_wp;
}

void Creature::snatch(Creature& enemy){
	sortWeapon(2); enemy.sortWeapon(2);
	if (enemy.sum_wp == 0 || sum_wp == 10) return;
	
	for (int i = 0; i < enemy.sum_wp && sum_wp < 10; ++i)
		//enemy.w[i]->owner = this, 
		w[sum_wp++] = enemy.w[i], enemy.w[i] = nullptr;
}

bool Creature::timeToRun(){
	return false;
}


//Dragon.cpp
//#include "Head.h"

Dragon::Dragon(int tot, int ele, type_side col): Creature(tot, col, dragon){
	makeWeapon(type_weapon(tot%3));
	morale = (double)ele/init_hp[dragon];
}

void Dragon::birth(){}

void Dragon::endFight(){
	printf("%03d:%02d %s dragon %d yelled in city %d\n", Hour, Minute, name_side[side], id, pos);
}

void Dragon::moveAction(){
	Creature::moveAction();
}


//GameControl.cpp
//#include "Head.h"

GameControl& GameControl::createObj(){
	static GameControl gc;
	return gc;
}

void GameControl::headquarterGenerate(){
	redH.create();
	blueH.create();
}

void GameControl::reset(int x){
	redH.reset(x);
	blueH.reset(x);
	gameOver = 0;
	for (int i = 0; i < 23; ++i)
		city[i].r = city[i].b = nullptr;
}

void GameControl::lionRun(){
	for (int i = 0; i <= nCity+1; ++i){
		if (city[i].r && city[i].r->type == lion && city[i].r->timeToRun()){
			printf("%03d:%02d red lion %d ran away\n", Hour, Minute, city[i].r->id);
			city[i].r->run();
		}
		if (city[i].b && city[i].b->type == lion && city[i].b->timeToRun()){
			printf("%03d:%02d blue lion %d ran away\n", Hour, Minute, city[i].b->id);
			city[i].b->run();
		}	
	}
}

void GameControl::moveForward(){
	Creature* t;
	for (int i = nCity; i >= 0; --i){
		if (!city[i].r) continue;
		t = city[i].r;
		city[i].leave(red);
		city[i+1].enter(red, t);
		//if (i == nCity) gameOver = 1;
	}
	for (int i = 1; i <= nCity+1; ++i){
		if (!city[i].b) continue;
		t = city[i].b;
		city[i].leave(blue);
		city[i-1].enter(blue, t);
		//if (i == 1) gameOver = 1;
	}
	
	for (int i = 0; i <= nCity+1; ++i){
		if (city[i].r){
			city[i].r->moveAction();
			if (i == nCity+1) endGame(red, blue, city[nCity+1].r);
		}
		if (city[i].b){
			city[i].b->moveAction();
			if (i == 0) endGame(blue, red, city[0].b);
		}
	}
}

void GameControl::endGame(type_side winner, type_side loser, const Creature* war){
	gameOver = 1;
	printf("%03d:%02d %s %s %d reached %s headquarter with %d elements and force %d\n", 
		Hour, Minute, name_side[winner], name_w[war->type], war->id, name_side[loser], war->health, war->atk);
	printf("%03d:%02d %s headquarter was taken\n", Hour, Minute, name_side[loser]);
}

bool GameControl::game_over(){
	return gameOver;
}

void GameControl::headquarterReport(){
	printf("%03d:%02d %d elements in red headquarter\n", Hour, Minute, redH.ele);
	printf("%03d:%02d %d elements in blue headquarter\n", Hour, Minute, blueH.ele);
}

void GameControl::warriorReport(){
	for (int i = 0; i <= nCity+1; ++i){
		if (city[i].r) builtin_warriorReport(city[i].r);
		if (city[i].b) builtin_warriorReport(city[i].b);
	}
}

void GameControl::builtin_warriorReport(Creature* t){
	t->sortWeapon(1);
	printf("%03d:%02d %s %s %d has ", 
		Hour, Minute, name_side[t->side], name_w[t->type], t->id);
	printf("%d sword %d bomb %d arrow ", t->s, t->b, t->a);
	printf("and %d elements\n", t->health);
}

void GameControl::wolfSnatch(){
	for (int i = 1; i <= nCity; ++i){
		if (!city[i].r || !city[i].b) continue;
		if (city[i].r->type == city[i].b->type) continue;
		if (city[i].r->type == wolf)
			city[i].r->snatch(*city[i].b);
		else if (city[i].b->type == wolf) 
			city[i].b->snatch(*city[i].r);
	}
}

void GameControl::warriorFight(){
	for (int i = 1; i <= nCity; ++i)
		if (city[i].r && city[i].b) city[i].fight();
}


//Global.cpp
//#include "Head.h"

int Hour, Minute;
const int N = 5;
const char* name_w[N] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int init_hp[N], init_atk[N];
const char* name_weapon[3] = {"sword", "bomb", "arrow"};
const char* name_side[2]{"red", "blue"};
int nCity, K;
City city[23];
//有些应该放在对应的类里

bool cmp_weapon_1(const Weapon* a, const Weapon* b){
	if (!a) return false;
	if (!b) return true;
	if (a->type != b->type) return a->type < b->type;
	if (a->type == arrow) return a->dua < b->dua;
	return true;
}

bool cmp_weapon_2(const Weapon* a, const Weapon* b){
	if (!a) return false;
	if (!b) return true;
	if (a->type != b->type) return a->type < b->type;
	if (a->type == arrow) return a->dua > b->dua;
	return true;
}


//Headquarter.cpp
//#include "Head.h"

void Headquarter::builtin_creature(type_w type){
	//++total[type];
	++sum_total;
	ele -= init_hp[type];
	printf("%03d:%02d %s %s %d born\n", Hour, Minute, name_side[side], name_w[type], sum_total);
	
	switch(type){
		case dragon: warrior[sum_total-1] = new Dragon(sum_total, ele, side); break;
		case ninja: warrior[sum_total-1] = new Ninja(sum_total, side); break;
		case iceman: warrior[sum_total-1] = new Iceman(sum_total, side); break;
		case lion: warrior[sum_total-1] = new Lion(sum_total, ele, side); break;
		case wolf: warrior[sum_total-1] = new Wolf(sum_total, side); break;
	}
	warrior[sum_total-1]->birth();
	if (side == red) city[0].enter(red, warrior[sum_total-1]);
	else city[nCity+1].enter(blue, warrior[sum_total-1]);
}

Headquarter::Headquarter(type_side s, type_w id[5]){
	side = s;
	for (int i = 0; i < N; ++i)
		name[i] = id[i];
}

void Headquarter::reset(int x){
	//memset(total, 0, sizeof total);
	for (int i = 0; i < sum_total; ++i)
		delete warrior[i];
		
	sum_total = 0;
	ele = x;
	can_create = 1;
	now = 0;
}

Headquarter::~Headquarter(){
	for (int i = 0; i < sum_total; ++i)
		delete warrior[i];
}

void Headquarter::create(){	//生成武士外部接口
	if (!can_create) return;
	
	if (init_hp[name[now]] <= ele){
		builtin_creature(name[now]);
		now = (now+1)%N;
	}
	else can_create = 0;
	return;
}


//Iceman.cpp
//#include "Head.h"

Iceman::Iceman(int tot, type_side col): Creature(tot, col, iceman){
	makeWeapon(type_weapon(tot%3));
}

void Iceman::birth(){}
void Iceman::endFight(){}
void Iceman::moveAction(){
	health -= health/10;
	Creature::moveAction();
}


//Lion.cpp
//#include "Head.h"

Lion::Lion(int tot, int ele, type_side col): Creature(tot, col, lion){
	makeWeapon(type_weapon(tot%3));
	loyalty = ele;
}

void Lion::birth(){
	printf("Its loyalty is %d\n", loyalty);
}

void Lion::endFight(){}

bool Lion::timeToRun(){
	return loyalty <= 0;
}

void Lion:: moveAction(){
	loyalty -= K;
	Creature::moveAction();
}


//Ninja.cpp
//#include "Head.h"

Ninja::Ninja(int tot, type_side col): Creature(tot, col, ninja){
	makeWeapon(type_weapon(tot%3));
	makeWeapon(type_weapon((tot+1)%3));
}

void Ninja::birth(){}
void Ninja::endFight(){}
void Ninja::moveAction(){
	Creature::moveAction();
}


//Weapon.cpp
//#include "Head.h"

Weapon::Weapon(type_weapon T): type{T}{
	switch(T){
		case sword: coeff = 2, dua = -1; break;
		case bomb: coeff = 4, dua = 1; break;
		case arrow: coeff = 3, dua = 2; break;
	}
}

type_weapon Weapon::getType(){
	return type;
}
	
bool Weapon::used(){
	return (avi = --dua);
}

bool Weapon::get_avi(){
	return avi;
}

int Weapon::get_coeff(){
	return coeff;
}


//Wolf.cpp
//#include "Head.h"

Wolf::Wolf(int tot, type_side col): Creature(tot, col, wolf){
	
}

void Wolf::birth(){}
void Wolf::endFight(){}
void Wolf::moveAction(){
	Creature::moveAction();
}

void Wolf::snatch(Creature& enemy){
	sortWeapon(2); enemy.sortWeapon(2);
	if (enemy.sum_wp == 0 || sum_wp == 10) return;
	
	type_weapon taken = enemy.w[0]->type;
	int s = 0;
	
	for (int i = 0; i < enemy.sum_wp && sum_wp < 10 && enemy.w[i]->getType() == taken; ++i)
		//enemy.w[i]->owner = this, 
		w[sum_wp++] = enemy.w[i], enemy.w[i] = nullptr, ++s;
		
	printf("%03d:%02d %s %s %d took %d %s from %s %s %d in city %d\n", 
			Hour, Minute, name_side[side], name_w[type], id, s, name_weapon[taken], name_side[enemy.side], name_w[enemy.type], enemy.id, pos);	
}


//main.cpp
//#include "Head.h"

int main(){
	//freopen("C://Users//20674//Desktop//WarCraft//datapub.in", "r", stdin);
	//freopen("C://Users//20674//Desktop//WarCraft//myout.txt", "w", stdout);
	
	int T;	//数据组数
	scanf("%d", &T);
	if (!T) return 0;
	int T1 = 1;	//目前所在数据组数
	
	int minuteList[7]{0, 5, 10, 35, 40, 50, 55};	//应该放进GameControl类
	
	
	int maxEle, timeLimit;
	string name;
	
	for (int i = 0; i < 23; ++i)
		city[i].set(i);
		
	GameControl& gc = GameControl::createObj();
	
Case:
	printf("Case %d:\n", T1++);
	cin >> maxEle >> nCity >> K >> timeLimit;
	gc.reset(maxEle);
	
	for (int i = 0; i < N; ++i)
		cin >> init_hp[i];
	for (int i = 0; i < N; ++i)
		cin >> init_atk[i];
	
	for (Hour = 0; ; ++Hour){
		for (int j = 0; j < 7; ++j){
			Minute = minuteList[j];
			if (Hour*60+Minute > timeLimit || gc.game_over())
				goto EndCase;
			
			switch(Minute){
				case 0: gc.headquarterGenerate(); break;
				case 5: gc.lionRun(); break;
				case 10: gc.moveForward(); break;
				case 35: gc.wolfSnatch(); break;
				case 40: gc.warriorFight(); break;
				case 50: gc.headquarterReport(); break;
				case 55: gc.warriorReport(); break;
			}
		}
	}

EndCase:
	if (T1 <= T) goto Case;
}
