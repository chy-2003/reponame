#include<cstdio>
#include<cstring>
char s1[1000010], s2[1000010];
int l1, l2;
int p[1000010];
int i, j;

int main(){
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	l1 = strlen(s1 + 1);
	l2 = strlen(s2 + 1);
	j = 0;
	for(i = 1; i < l2; i++){
		while(j > 0 && s2[j + 1] != s2[i + 1]) j = p[j];
		if(s2[j + 1] == s2[i + 1]) j++;
		p[i + 1] = j;
	}
	j = 0;
	for(i = 1; i <= l1; i++){
		while(j > 0 && s2[j + 1] != s1[i]) j = p[j];
		if(s2[j + 1] == s1[i]) j++;
		if(j == l2){
			printf("%d\n", i - l2 + 1);
			j = p[j];
		}
	}
	for(i = 1; i <= l2; i++) printf("%d ", p[i]); printf("\n");
}
