//Head.h
//#pragma once
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
enum type_side{red, blue, none};	//阵营枚举
extern const char* name_side[3];	//阵营字符串
extern int nCity, R, K;	//城市总数，arrow攻击力，忠诚度梯度
enum type_alive{redW, blueW, noneW, bothW};

class Creature;

class City{
	friend class GameControl;
private:
	Creature* r{nullptr};
	Creature* b{nullptr};
	int id, ele;
	type_side flag{none};
	type_alive st[2]{noneW, noneW};	//当次胜方，上次胜方
	bool isBattleField{false};	//本轮是否为战场
	
public:
	void reset(int t);	//重置
	//void fight();	//战斗
	void leave(type_side col);
	void enter(type_side col, Creature* war);
	type_side atkSide();
};

extern City city[];	//城市

struct Sword{
	int atk;
	bool avi{true};
	void wornout(){
		atk = atk*8/10;
		avi = atk;
	}
};

struct Arrow{
	int dua{3};
	bool avi{true};
	void wornout(){
		avi = --dua;
	}
};

struct Bomb{
	bool avi{true};
};

class Creature{
	friend class GameControl;
	friend class Wolf;
protected:
	int id, health, atk, pos;	//编号，生命值，攻击力，位置
	type_side side;	//阵营
	type_w type;	//类型
	Sword s{0, 0};
	Arrow a{0, 0};
	Bomb b{0};
	bool alive{true};
	//bool needReward{false};
	
public:
	Creature(int tot, type_side col, type_w T);	//构造
	virtual ~Creature() = default;
	
	void makeWeapon(type_weapon T);	//制作武器
	void hurted(int damage);	//受伤
	void attack(Creature* enemy, bool real = true);	//攻击
	void fightBack(Creature* enemy, bool real = true);	//反击
	virtual void endFight(bool killed) = 0;	//战斗结束后行为
	virtual void birth() = 0;	//诞生后行为
	virtual void moveAction() = 0;	//前进后行为
	bool timeToSacrifice(Creature* enemy);
};

class Dragon: public Creature{
	friend class GameControl;
private:
	double morale;	//士气
public:
	Dragon(int tot, int ele, type_side col);	//构造
	void birth();
	void endFight(bool killed);
	void moveAction();
};

class Ninja: public Creature{
	friend class GameControl;
private:
public:
	Ninja(int tot, type_side col);	//构造
	void birth();
	void endFight(bool killed);
	void moveAction();
};

class Iceman: public Creature{
	friend class GameControl;
private:
	int step{0};
public:
	Iceman(int tot, type_side col);	//构造
	void birth();
	void endFight(bool killed);
	void moveAction();
};

class Lion: public Creature{
	friend class GameControl;
private:
	int loyalty;
	int health_bk;
public:
	Lion(int tot, int ele, type_side col);	//构造
	void birth();
	void endFight(bool killed);
	bool timeToRun();
	void moveAction();
	void run();
};

class Wolf: public Creature{
	friend class GameControl;
public:
	Wolf(int tot, type_side col);	//构造
	void birth();
	void endFight(bool killed);
	void moveAction();
	void snatch(Creature* enemy);
};

class Headquarter{
	friend class GameControl;
private:
	type_side side;	//阵营
	type_w name[5];	//武士制造顺序
	int sum_total;	//所有武士总数
	int ele, ele_earned;	//生命元
	int now;	//该造谁了
	Creature* warrior[110];	//武士
	int hp{2};	//剩余血量
	
	void builtin_creature(type_w type);	//制造武士
	
public:
	Headquarter(type_side s, type_w id[5]);	//构造
	void reset(int x);	//重置
	~Headquarter();	//析构
	
	void create();	//制造武士外部接口
};

class GameControl{
public:
	//const int nEvent = 10;
	//const int minuteList[]{0, 5, 10, 20, 30, 35, 38, 40, 50, 55};
	
	static GameControl& createObj();
	
	void headquarterGenerate();
	void lionRun();
	void moveForward();
	void generateEle();
	void takeEle();
	void shootArrow();
	void kamikaze();
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
	
	void endGame(type_side loser);
	void builtin_warriorReport(Creature* t);
	void builtin_warriorFight(City& c);
	void endFight(City& c, type_alive w);
};


//City.cpp
//#include "Head.h"
	
void City::reset(int t){
	id = t, ele = 0;
	r = b = nullptr;
	flag = none;
	st[0] = st[1] = noneW;
	isBattleField = 0;
}

void City::leave(type_side col){
	if (col == red) r = nullptr;
	else if (col == blue) b = nullptr;
}

void City::enter(type_side col, Creature* war){
	if (col == red) r = war;
	else if (col == blue) b = war;
}

type_side City::atkSide(){
	if (flag != none) return flag;
	return id&1? red: blue;
}


//Creature.cpp
//#include "Head.h"

Creature::Creature(int tot, type_side col, type_w T): id{tot}, side{col}, type{T}{
	pos = side==red? 0: nCity+1;
	health = init_hp[type];
	atk = init_atk[type];
}

void Creature::makeWeapon(type_weapon T){
	switch(T){
		case sword:
			if (atk >= 5) s = {atk*2/10, 1};
			break;
		case arrow:
			a = {3, 1}; break;
		case bomb:
			b = {1}; break;
	}
}

void Creature::hurted(int damage){
	health -= damage;
	if (health <= 0) alive = 0;
}

void Creature::attack(Creature* enemy, bool real /*= true*/){
	if (real) printf("%03d:%02d %s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",
					Hour, Minute, name_side[side], name_w[type], id, name_side[enemy->side], name_w[enemy->type], enemy->id, pos, health, atk);
	enemy->hurted(atk+s.atk);
	s.wornout();
	if (enemy->alive && enemy->type != ninja) enemy->fightBack(this, real);
}

void Creature::fightBack(Creature* enemy, bool real /*= true*/){
	if (real) printf("%03d:%02d %s %s %d fought back against %s %s %d in city %d\n",
					Hour, Minute, name_side[side], name_w[type], id, name_side[enemy->side], name_w[enemy->type], enemy->id, pos);
	enemy->hurted(atk/2+s.atk);
	s.wornout();
}

void Creature::moveAction(){
	if (side == red) ++pos;
	else --pos;
	
	if (side == red && pos == nCity+1)
		printf("%03d:%02d %s %s %d reached %s headquarter with %d elements and force %d\n", 
				Hour, Minute, name_side[red], name_w[type], id, name_side[blue], health, atk);
	else if (side == blue && pos == 0)
		printf("%03d:%02d %s %s %d reached %s headquarter with %d elements and force %d\n", 
				Hour, Minute, name_side[blue], name_w[type], id, name_side[red], health, atk);
	else
		printf("%03d:%02d %s %s %d marched to city %d with %d elements and force %d\n",
			Hour, Minute, name_side[side], name_w[type], id, pos, health, atk);
}

bool Creature::timeToSacrifice(Creature* enemy){
	if (!enemy || !enemy->alive) return false;
	if (!b.avi) return false;
	
	Creature* me;
	Creature* opp;
	
	switch(type){
		case dragon: me = new Dragon(*dynamic_cast<Dragon*>(this)); break;
		case ninja: me = new Ninja(*dynamic_cast<Ninja*>(this)); break;
		case iceman: me = new Iceman(*dynamic_cast<Iceman*>(this)); break;
		case lion: me = new Lion(*dynamic_cast<Lion*>(this)); break;
		case wolf: me = new Wolf(*dynamic_cast<Wolf*>(this)); break;
	}
	switch(enemy->type){
		case dragon: opp = new Dragon(*dynamic_cast<Dragon*>(enemy)); break;
		case ninja: opp = new Ninja(*dynamic_cast<Ninja*>(enemy)); break;
		case iceman: opp = new Iceman(*dynamic_cast<Iceman*>(enemy)); break;
		case lion: opp = new Lion(*dynamic_cast<Lion*>(enemy)); break;
		case wolf: opp = new Wolf(*dynamic_cast<Wolf*>(enemy)); break;
	}
	
	if (city[pos].atkSide() == side)
		me->attack(opp, false);
	else
		opp->attack(me, false);
		
	bool t = me->alive;
	delete me; delete opp;
	return !t;
}


//Dragon.cpp
//#include "Head.h"

Dragon::Dragon(int tot, int ele, type_side col): Creature(tot, col, dragon){
	makeWeapon(type_weapon(tot%3));
	morale = (double)ele/init_hp[dragon];
}

void Dragon::birth(){
	printf("Its morale is %.2f\n", morale);
}

void Dragon::endFight(bool killed){
	morale += killed? 0.2: -0.2;
	if (morale+1e-6 > 0.8 && city[pos].atkSide() == side)
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

void GameControl::reset(int maxEle){
	redH.reset(maxEle);
	blueH.reset(maxEle);
	gameOver = 0;
	for (int i = 0; i < 23; ++i)
		city[i].reset(i);
}

void GameControl::lionRun(){
	Lion* p;
	for (int i = 0; i <= nCity+1; ++i){
		if (city[i].r && city[i].r->type == lion){
			p = dynamic_cast<Lion*>(city[i].r);
			if (p->timeToRun()){
				printf("%03d:%02d red lion %d ran away\n", Hour, Minute, city[i].r->id);
				p->run();
			}
		}
		if (city[i].b && city[i].b->type == lion){
			p = dynamic_cast<Lion*>(city[i].b);
			if (p->timeToRun()){
				printf("%03d:%02d blue lion %d ran away\n", Hour, Minute, city[i].b->id);
				p->run();
			}
		}	
	}
}

void GameControl::moveForward(){
	Creature* pr[23];
	Creature* pb[23];
	for (int i = 0; i <= nCity+1; ++i){
		pr[i] = city[i].r, pb[i] = city[i].b;
		city[i].leave(red); city[i].leave(blue);
	}
		
		
	for (int i = 0; i <= nCity+1; ++i){
		if (i && pr[i-1]){
			city[i].enter(red, pr[i-1]);
			city[i].r->moveAction();
			if (i == nCity+1 && !--blueH.hp)
				endGame(blue);
		}
		if (i != nCity+1 && pb[i+1]){
			city[i].enter(blue, pb[i+1]);
			city[i].b->moveAction();
			if (!i && !--redH.hp)
				endGame(red);
		}
	}
	if (pr[nCity+1]) city[nCity+1].r = pr[nCity+1];
	if (pb[0]) city[0].b = pb[0];
}

void GameControl::endGame(type_side loser){
	gameOver = 1;
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
	for (int i = 0; i <= nCity+1; ++i)
		if (city[i].r) builtin_warriorReport(city[i].r);
	
	for (int i = 0; i <= nCity+1; ++i)
		if (city[i].b) builtin_warriorReport(city[i].b);
}

void GameControl::builtin_warriorReport(Creature* t){
	printf("%03d:%02d %s %s %d has ", 
		Hour, Minute, name_side[t->side], name_w[t->type], t->id);
	
	if (!t->s.avi && !t->b.avi && !t->a.avi)
		printf("no weapon\n");
	else{
		int flag = 0;
		if (t->a.avi){
			printf("arrow(%d)", t->a.dua);
			flag = 1;
		}
		if (t->b.avi){
			if (flag) putchar(',');
			printf("bomb");
			flag = 1;
		}
		if (t->s.avi){
			if (flag) putchar(',');
			printf("sword(%d)", t->s.atk);
		}
		putchar('\n');
	}
}

void GameControl::warriorFight(){
	for (int i = 1; i <= nCity; ++i)
		builtin_warriorFight(city[i]);
		
	for (int i = 1; i <= nCity && redH.ele >= 8; ++i)
		if (city[i].isBattleField && city[i].st[0] == redW)
			city[i].r->health += 8, redH.ele -= 8;
			
	for (int i = nCity; i && blueH.ele >= 8; --i)
		if (city[i].isBattleField && city[i].st[0] == blueW)
			city[i].b->health += 8, blueH.ele -= 8;
			
	redH.ele += redH.ele_earned, redH.ele_earned = 0;
	blueH.ele += blueH.ele_earned, blueH.ele_earned = 0;
}

void GameControl::generateEle(){
	for (int i = 0; i < 23; ++i)
		city[i].ele += 10;
}

void GameControl::takeEle(){
	for (int i = 1; i <= nCity; ++i)
		if (city[i].r && !city[i].b){
			printf("%03d:%02d red %s %d earned %d elements for his headquarter\n",
				Hour, Minute, name_w[city[i].r->type], city[i].r->id, city[i].ele);
			redH.ele += city[i].ele, city[i].ele = 0;	
		}
		else if (city[i].b && !city[i].r){
			printf("%03d:%02d blue %s %d earned %d elements for his headquarter\n",
				Hour, Minute, name_w[city[i].b->type], city[i].b->id, city[i].ele);
			blueH.ele += city[i].ele, city[i].ele = 0;
		}
}

void GameControl::shootArrow(){
	for (int i = 0; i <= nCity+1; ++i){
		if (i != nCity+1 && city[i].r && city[i+1].b && city[i].r->a.avi){
			city[i].r->a.wornout();
			city[i+1].b->hurted(R);
			printf("%03d:%02d red %s %d shot", Hour, Minute, name_w[city[i].r->type], city[i].r->id);
			if (!city[i+1].b->alive)
				printf(" and killed blue %s %d", name_w[city[i+1].b->type], city[i+1].b->id);
			putchar('\n');			
		}
		if (i && city[i].b && city[i-1].r && city[i].b->a.avi){
			city[i].b->a.wornout();
			city[i-1].r->hurted(R);
			printf("%03d:%02d blue %s %d shot", Hour, Minute, name_w[city[i].b->type], city[i].b->id);
			if (!city[i-1].r->alive)
				printf(" and killed red %s %d", name_w[city[i-1].r->type], city[i-1].r->id);
			putchar('\n');			
		}
	}
}

void GameControl::builtin_warriorFight(City& c){
	if (!c.r || !c.b){
		c.isBattleField = false;
		if (c.r && !c.r->alive) c.leave(red);
		else if (c.b && !c.b->alive) c.leave(blue);
		return;
	}
	if (!c.r->alive && !c.b->alive){
		c.isBattleField = false;
		c.leave(red); c.leave(blue);
		return;
	}
	c.isBattleField = true;
	
	if (c.r->type == lion) 
		dynamic_cast<Lion*>(c.r)->health_bk = max(0, c.r->health);
	if (c.b->type == lion) 
		dynamic_cast<Lion*>(c.b)->health_bk = max(0, c.b->health);
	
	if (!c.r->alive){
		endFight(c, c.b->alive? blueW: noneW);
		return;
	}
	else if (!c.b->alive){
		endFight(c, c.r->alive? redW: noneW);
		return;
	}
		
	if (c.atkSide() == red)
		c.r->attack(c.b);
	else
		c.b->attack(c.r);
	
	if (!c.r->alive){
		printf("%03d:%02d red %s %d was killed in city %d\n",
			Hour, Minute, name_w[c.r->type], c.r->id, c.id);
		endFight(c, c.b->alive? blueW: noneW);
	}
	else if (!c.b->alive){
		printf("%03d:%02d blue %s %d was killed in city %d\n",
			Hour, Minute, name_w[c.b->type], c.b->id, c.id);
		endFight(c, c.r->alive? redW: noneW);
	}
	else
		endFight(c, bothW);
	return;
}

void GameControl::endFight(City& c, type_alive w){
	switch(w){
		case redW:
			c.r->endFight(true);
			if (c.r->type == wolf)
				dynamic_cast<Wolf*>(c.r)->snatch(c.b);
			if (c.b->type == lion)
				c.r->health += dynamic_cast<Lion*>(c.b)->health_bk;
			c.leave(blue);

			c.st[1] = c.st[0], c.st[0] = redW;
			
			printf("%03d:%02d red %s %d earned %d elements for his headquarter\n",
				Hour, Minute, name_w[c.r->type], c.r->id, c.ele);
			redH.ele_earned += c.ele, c.ele = 0;
			
			if (c.st[1] == redW && c.flag != red){
				c.flag = red;
				printf("%03d:%02d red flag raised in city %d\n",
					Hour, Minute, c.id);
			}
			break;
		
		case blueW:
			c.b->endFight(true);
			if (c.b->type == wolf)
				dynamic_cast<Wolf*>(c.b)->snatch(c.r);
			if (c.r->type == lion)
				c.b->health += dynamic_cast<Lion*>(c.r)->health_bk;
			c.leave(red);
			
			c.st[1] = c.st[0], c.st[0] = blueW;
			
			printf("%03d:%02d blue %s %d earned %d elements for his headquarter\n",
				Hour, Minute, name_w[c.b->type], c.b->id, c.ele);
			blueH.ele_earned += c.ele, c.ele = 0;
			
			if (c.st[1] == blueW && c.flag != blue){
				c.flag = blue;
				printf("%03d:%02d blue flag raised in city %d\n",
					Hour, Minute, c.id);
			}
			break;
			
		case noneW:
			c.st[1] = c.st[0], c.st[0] = noneW;
			c.leave(red); c.leave(blue);
			break;
		
		case bothW:
			c.st[1] = c.st[0], c.st[0] = bothW;
			c.r->endFight(false); c.b->endFight(false);
			break;
	}
}

void GameControl::kamikaze(){
	for (int i = 1; i <= nCity; ++i){
		if (city[i].r && city[i].r->alive && city[i].r->timeToSacrifice(city[i].b)){
			printf("%03d:%02d red %s %d used a bomb and killed blue %s %d\n",
				Hour, Minute, name_w[city[i].r->type], city[i].r->id, name_w[city[i].b->type], city[i].b->id);
			city[i].leave(red), city[i].leave(blue);
		}
		else if(city[i].b && city[i].b->alive && city[i].b->timeToSacrifice(city[i].r)){
			printf("%03d:%02d blue %s %d used a bomb and killed red %s %d\n",
				Hour, Minute, name_w[city[i].b->type], city[i].b->id, name_w[city[i].r->type], city[i].r->id);
			city[i].leave(red), city[i].leave(blue);
		}
	}
}


//Global.cpp
//#include "Head.h"

int Hour, Minute;
const int N = 5;
const char* name_w[N] = {"dragon", "ninja", "iceman", "lion", "wolf"};
int init_hp[N], init_atk[N];
const char* name_weapon[3] = {"sword", "bomb", "arrow"};
const char* name_side[3]{"red", "blue", "none"};
int nCity, R, K;
City city[23];


//Headquater.cpp
//#include "Head.h"

void Headquarter::builtin_creature(type_w type){
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
	for (int i = 0; i < sum_total; ++i)
		delete warrior[i];
		
	sum_total = 0;
	ele = x;
	ele_earned = 0;
	now = 0;
	hp = 2;
}

Headquarter::~Headquarter(){
	for (int i = 0; i < sum_total; ++i)
		delete warrior[i];
}

void Headquarter::create(){
	if (init_hp[name[now]] <= ele){
		builtin_creature(name[now]);
		now = (now+1)%N;
	}
}


//Iceman.cpp
//#include "Head.h"

Iceman::Iceman(int tot, type_side col): Creature(tot, col, iceman){
	makeWeapon(type_weapon(tot%3));
}

void Iceman::birth(){}
void Iceman::endFight(bool){}
void Iceman::moveAction(){
	if (!(++step&1))
		health = max(1, health-9), atk += 20;
	Creature::moveAction();
}


//Lion.cpp
//#include "Head.h"

Lion::Lion(int tot, int ele, type_side col): Creature(tot, col, lion){
	loyalty = ele;
}

void Lion::birth(){
	printf("Its loyalty is %d\n", loyalty);
}

void Lion::endFight(bool killed){
	if (!killed) loyalty -= K;
}

bool Lion::timeToRun(){
	return loyalty <= 0;
}

void Lion:: moveAction(){
	Creature::moveAction();
}

void Lion::run(){
	alive = 0;
	if (side == red) city[pos].leave(red);
	else city[pos].leave(blue);
}


//Ninja.cpp
//#include "Head.h"

Ninja::Ninja(int tot, type_side col): Creature(tot, col, ninja){
	makeWeapon(type_weapon(tot%3));
	makeWeapon(type_weapon((tot+1)%3));
}

void Ninja::birth(){}
void Ninja::endFight(bool){}
void Ninja::moveAction(){
	Creature::moveAction();
}


//Wolf.cpp
//#include "Head.h"

Wolf::Wolf(int tot, type_side col): Creature(tot, col, wolf){
	
}

void Wolf::birth(){}
void Wolf::endFight(bool){}
void Wolf::moveAction(){
	Creature::moveAction();
}

void Wolf::snatch(Creature* enemy){
	if (!s.avi) s = enemy->s;
	if (!a.avi) a = enemy->a;
	if (!b.avi) b = enemy->b;	
}


//main.cpp
//#include "Head.h"

int main(){
	//提交前要注释掉！！！
	//freopen("C://Users//20674//Desktop//WarCraft//data.in", "r", stdin);
	//freopen("C://Users//20674//Desktop//WarCraft//myout.txt", "w", stdout);
	
	int T;	//数据组数
	scanf("%d", &T);
	int T1 = 1;	//目前所在数据组数
	
	const int nEvent = 10;
	const int minuteList[]{0, 5, 10, 20, 30, 35, 38, 40, 50, 55};	
	
	int maxEle, timeLimit;
	string name;
		
	GameControl& gc = GameControl::createObj();
	
Case:
	printf("Case %d:\n", T1++);
	cin >> maxEle >> nCity >> R >> K >> timeLimit;
	gc.reset(maxEle);
	
	for (int i = 0; i < N; ++i)
		cin >> init_hp[i];
	for (int i = 0; i < N; ++i)
		cin >> init_atk[i];
	
	for (Hour = 0; ; ++Hour){
		for (int j = 0; j < nEvent; ++j){
			Minute = minuteList[j];
			if (Hour*60+Minute > timeLimit || gc.game_over())
				goto EndCase;
			
			switch(Minute){
				case 0: gc.headquarterGenerate(); break;
				case 5: gc.lionRun(); break;
				case 10: gc.moveForward(); break;
				case 20: gc.generateEle(); break;
				case 30: gc.takeEle(); break;
				case 35: gc.shootArrow(); break;
				case 38: gc.kamikaze(); break;
				case 40: gc.warriorFight(); break;
				case 50: gc.headquarterReport(); break;
				case 55: gc.warriorReport(); break;
			}
		}
	}

EndCase:
	if (T1 <= T) goto Case;
}
