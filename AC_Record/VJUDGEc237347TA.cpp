#include<bits/stdc++.h>
using namespace std;
int casenum, l, nxt[100010], last[100010], in;
char ch[100010], c;
void del(int x){
    nxt[last[x]] = nxt[x];
    last[nxt[x]] = last[x];
    return;
}
void tab(int x){
    printf("\n");
    for(int i = 1; i <= x; i++) printf(" ");
    return;
}
int main(){
    scanf("%d", &casenum);
    while(scanf("%c", &c) == 1){
        if(c == '\n') c = ' ';
        l++;
        ch[l] = c;
    }
    for(int i = 1; i <= l; i++){
        nxt[i] = i + 1;
        last[i] = i - 1;
    }
    nxt[0] = 1;
    in = 0;
    for(int i = 1; i <= l; i++){
        if(ch[i] == '<') in = 1;
        if(ch[i] == '>') in = 0;
        if(!in && (ch[i] == '\t')) ch[i] = ' ';
    }
    in = 0;
    for(int i = 1; i <= l; i++){
        if(ch[i] == '<') in = 1;
        if(ch[i] == '>') in = 0;
        if(in != 1 && ch[i] == ' '){
            if(ch[last[i]] == '>') del(i); else
            if(ch[last[i]] == ' ') del(i);
        } else
        if(ch[i] == '<'){
            if(ch[last[i]] == ' ') del(last[i]);
        }
    }
 //   for(int i = nxt[0]; i <= l; i = nxt[i]) printf("%c", ch[i]); printf("\n");
    in = 0;
    printf("Case #1:\n");
    int ll = nxt[0], deep = 0, cas = 1;
    while(ll <= l){
        if(ch[ll] == '<' && ch[nxt[ll]] == '/' && ch[nxt[nxt[ll]]] == '>'){
            if(deep) tab(deep);
            printf("</>");
            ll = nxt[nxt[nxt[ll]]];
        } else
        if(ch[ll] == '<' && ch[nxt[ll]] == '/'){
            deep--;
            tab(deep);
            int l1 = ll;
            while(1){
                printf("%c", ch[l1]);
                if(ch[l1] == '>') break;
                l1 = nxt[l1];
            }
            ll = nxt[l1];
            if(deep == 0){
                if(cas == casenum){
                    printf("\n");
                    return 0;
                }
                printf("\nCase #%d:\n", ++cas);
            }
        } else
        if(ch[ll] == '<' && ch[nxt[ll]] != '/'){
            if(deep) tab(deep);
            int l1 = ll;
            while(1){
                printf("%c", ch[l1]);
                if(ch[l1] == '>') break;
                if(ch[l1] == '/' && ch[nxt[l1]] == '>') deep--;
                l1 = nxt[l1];
            }
            deep++;
            ll = nxt[l1];
        } else{
            tab(deep);
            int l1 = ll;
            while(1){
                if(ch[l1] == '<') break;
                printf("%c", ch[l1]);
                l1 = nxt[l1];
            }
            ll = l1;
        }
    }
    return 0;
}
