#include<bits/stdc++.h>
using namespace std;
char ch[50000];
int nxt[50000], casenum, i, j, len, last, deep, cas, in;
inline void tab(int x){
	printf("\n");
	for(int i = 0; i < x; i++) printf(" ");
	return;
}
int main(){
	scanf("%d", &casenum);
	len = 0; 
	while(gets(ch + len) != NULL){
		 if(!ch[0]) continue;
		 len = strlen(ch);
		 ch[len] = ' ';
		 len++;
	}
	in = 0;
	for(i = 0; i < len; i++){
		if(ch[i] == '<') in = 1;
		else if(ch[i] == '>') in = 0;
		else if(!in && ch[i] == '\t') ch[i] = ' ';
		nxt[i] = i + 1;
	}
	last = 0;
	in = 0;
	for(i = 1; i < len; i++){
		if(ch[i] == '<') in = 1;
		else if(ch[i] == '>') in = 0;
		if(ch[i] == ' '){
			if((in == 0 && ch[last] == ' ') || ch[last] == '>') nxt[last] = nxt[i]; else last = i;
		}
		else last = i;
	}
	for(i = 0; i < len; i = nxt[i]){
		if(ch[i] == ' ' && ch[nxt[i]] == '<') nxt[last] = nxt[i];
		last = i;
	}
	deep = 0;
	cas = 2;
	printf("Case #1:\n");
	for(i = 0; i < len;){
		if(ch[i] == '<' && ch[nxt[i]] == '/' && ch[nxt[nxt[i]]] == '>'){
			if(deep) tab(deep);
			printf("</>");
			i = nxt[nxt[nxt[i]]];
		} else 
		if(ch[i] == '<' && ch[i + 1] == '/'){
			deep--;
			tab(deep);
			for(j = i; j < len; j = nxt[j]){
				printf("%c",ch[j]);
				if(ch[j] == '>') break;
			}
			i = nxt[j];
			if(deep == 0){
				if(cas > casenum){
					printf("\n");
					return 0;
				}
				printf("\nCase #%d:\n", cas++);
			}
		} else 
		if(ch[i] == '<' && ch[i + 1] != '/'){
			if(deep) tab(deep);
			for(j = i; j < len; j = nxt[j]){
				printf("%c", ch[j]);
				if(ch[j] == '>') break; else 
				if(ch[j] == '/' && ch[j + 1] == '>') deep--;
			}
			i = nxt[j];
			deep++;
		} else {
			tab(deep);
			for(j = i; j < len; j = nxt[j]){
				if(ch[j] == '<') break;
				printf("%c", ch[j]);
			}
			i = j;
		}
	}
	return 0;
}
