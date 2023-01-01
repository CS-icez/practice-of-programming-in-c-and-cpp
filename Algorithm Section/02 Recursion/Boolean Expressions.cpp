#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

char str[110];

void eval(stack<char>& op, stack<bool>& b){
    bool t1, t2;
    t1 = b.top(); b.pop();
    t2 = b.top(); b.pop();
    b.push(op.top() == '&'? t1&&t2: t1||t2);
    op.pop();
}

pair<bool, int> solve(int beg){
    stack<char> op;
    stack<bool> b;
    pair<bool, int> t;
    
    int len = strlen(str);
    int flag = 0;
    
    for (int i = beg; i < len; ++i)
        switch (str[i]){
            case ' ': break;
            case 'V': b.push(1^flag); flag = 0; break;
            case 'F': b.push(0^flag); flag = 0; break;
            case '&': 
                while (!op.empty() && op.top() == '&')
                    eval(op, b);
                op.push('&');
                break;
            case '!': flag ^= 1; break;
            case '|':
                while (!op.empty()) eval(op, b);
                op.push('|');
                break;
            case '(':
                t = solve(i+1);
                b.push(t.first^flag);
                flag = 0;
                i = t.second;
                break;
            case ')':
                while (!op.empty()) eval(op, b);
                return {b.top(), i};
        }
    return {b.top(), 0};
}

int main(){    
    int cnt = 0;
    while (cin.getline(str+1, 110)){
        int len = strlen(str+1);
        str[0] = '(', str[len+1] = ')', str[len+2] = '\0';
        cout << "Expression " << (++cnt) << ": ";
        cout << (solve(0).first? "V": "F") << endl;
    }
}
