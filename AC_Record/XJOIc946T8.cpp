#include<bits/stdc++.h>
using namespace std;
 
int l, dep[110], t_dep = 0;
string s;
int l2, c[110], cntt, recc[110];
 
double get_num(int l, int r){
    double num = 0;
    while(l <= r && s[l] != '.'){
        num = num * 10 + s[l] - '0';
        l++;
    }
    double k = 1;
    l++;
    while(l <= r){
        k = k * 0.1;
        num = num + (s[l] - '0') * k;
        l++;
    }
    return num;
}
 
double go(double x, double y, char ch){
    if(ch == '+') return x + y;
    if(ch == '-') return x - y;
    if(ch == '*') return x * y;
    if(ch == '/') return x / y;
    if(ch == '^') return pow(x, y);
}
 
double work(int l, int r){
    while(s[l] == '(' && s[r] == ')' && recc[l] == recc[r]){ l++; r--; };
//    printf("%d %d\n", l, r);
    int t = 10010, id;
    for(int i = l; i <= r; i++)
        if(dep[i] > 0)
        if(dep[i] <= t){
            t = dep[i];
            id = i;
        }
    double tt;
    if(t == 10010){
        tt = get_num(l, r);
//      printf("%d %d %.2lf\n", l, r, tt);
        return tt;
    }
    double t1, t2;
    t1 = work(l, id - 1);
    t2 = work(id + 1, r);
    tt = go(t1, t2, s[id]);
 //   printf("%d %d %.2lf %.2lf %.2lf", l, r, t1, t2, tt);
    return tt;
}
 
int main(){
    cin >> s;
    l = s.size();
    memset(dep, 0, sizeof(dep));
    for(int i = 0; i < l; i++){
        if(s[i] == '+') dep[i] = t_dep + 1;
        if(s[i] == '-') dep[i] = t_dep + 1;
        if(s[i] == '*') dep[i] = t_dep + 2;
        if(s[i] == '/') dep[i] = t_dep + 2;
        if(s[i] == '^') dep[i] = t_dep + 3;
        if(s[i] == '(') t_dep += 4;
        if(s[i] == ')') t_dep -= 4;
    }
    cntt = 0;
    l2 = 0;
    memset(recc, 0, sizeof(recc));
    for(int i = 0; i < l; i++)
    	if(s[i] == '('){
    		cntt++;
    		l2++;
    		c[l2] = cntt;
    		recc[i] = cntt;
    	} else
    	if(s[i] == ')'){
    		recc[i] = c[l2];
    		l2--;
    	}
    printf("%.2lf", work(0, l - 1));
    return 0;
}
