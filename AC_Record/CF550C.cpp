#include<bits/stdc++.h>
using namespace std;
char ch[110];
int l;
int main(){
	scanf("%s", ch + 1);
	l = strlen(ch + 1);
	if(l == 1){
		if(ch[1] == '8' || ch[1] == '0'){
			printf("YES\n%c\n", ch[1]);
			return 0;
		} else{
			printf("NO\n");
			return 0;
		}
	}
	if(l == 2){
		if(((ch[1] - '0') * 10 + (ch[2] - '0')) % 8 == 0){
			printf("YES\n%c%c\n", ch[1], ch[2]);
			return 0;
		}
		if(ch[1] == '0' || ch[1] == '8'){
			printf("YES\n%c\n", ch[1]);
			return 0;
		}
		if(ch[2] == '0' || ch[2] == '8'){
			printf("YES\n%c\n", ch[2]);
			return 0;
		}
		printf("NO\n");
		return 0;
	}
	for(int i = 1; i * 2 <= l; i++) swap(ch[i], ch[l - i + 1]);
	for(int i = 1; i <= l; i++)
		if(ch[i] == '0' || ch[i] == '8'){
			printf("YES\n%c\n", ch[i]);
			return 0;
		}
	for(int i = 1; i <= l - 1; i++)
		for(int j = i + 1; j <= l; j++)
			if(((ch[j] - '0') * 10 + (ch[i] - '0')) % 8 == 0){
				printf("YES\n%c%c\n", ch[j], ch[i]);
				return 0;
			}
	for(int i = 1; i <= l - 2; i++)
		for(int j = i + 1; j <= l - 1; j++)
			for(int k = j + 1; k <= l; k++){
				if(((ch[k] - '0') * 100 + (ch[j] - '0') * 10 + (ch[i] - '0')) % 8 == 0){
					printf("YES\n");
					for(int ll = l; ll > k; ll--) printf("%c", ch[ll]);
					printf("%d\n", ((ch[k] - '0') * 100 + (ch[j] - '0') * 10 + (ch[i] - '0')));
					return 0;
				}
			}
	printf("NO\n");
	return 0;
}
