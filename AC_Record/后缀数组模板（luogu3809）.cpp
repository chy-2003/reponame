#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000010;
int n;
char ch[MAXN];
int rank[MAXN], reflact[MAXN], bin[MAXN], binsize, temporary[MAXN];
void BinSort(int step) {
//	printf("temporary before sorting : "); for(int i = 1; i <= n; i++) printf("%4d", temporary[i]); printf("\n");
	memset(bin, 0, sizeof(bin));
	for(int i = 1; i <= n; i++) bin[rank[i]]++;
	for(int i = 1; i <= binsize; i++) bin[i] += bin[i - 1];
	for(int i = 1; i <= n; i++) reflact[bin[rank[temporary[i]]]] = temporary[i], bin[rank[temporary[i]]]--;
	for(int i = 1; i <= n; i++) temporary[i] = rank[i];
	rank[reflact[1]] = binsize = 1;
	for(int i = 2; i <= n; i++) 
		if(temporary[reflact[i]] == temporary[reflact[i - 1]] && temporary[reflact[i] + step] == temporary[reflact[i - 1] + step])
			rank[reflact[i]] = binsize;
		else
			rank[reflact[i]] = ++binsize;
	return;
}
void Debug() {
	printf("====================Debug===================\n");
	printf("Possition : "); for(int i = 1; i <= n; i++) printf("%4d", i); printf("\n");
	printf("Charactor : "); for(int i = 1; i <= n; i++) printf("%4c", ch[i]); printf("\n");
	printf("Rank      : "); for(int i = 1; i <= n; i++) printf("%4d", rank[i]); printf("\n");
	printf("reflact   : "); for(int i = 1; i <= n; i++) printf("%4d", reflact[i]); printf("\n");
	printf("====================END=====================\n\n");
	return;
}
int main() {
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	for(int i = 1; i <= n; i++) rank[i] = ch[i];
	for(int i = 1; i <= n; i++) reflact[i] = i;
	for(int i = 1; i <= n; i++) temporary[i] = i;
	binsize = 128;
//	Debug();
	BinSort(0);
//	Debug();
	for(int StepWidth = 1; StepWidth <= n && binsize < n; StepWidth <<= 1) {
		int counter = 0;
		for(int i = n; i >= 1; i--) if(reflact[i] > StepWidth) temporary[++counter] = reflact[i] - StepWidth;
		for(int i = 1; i <= StepWidth; i++) temporary[++counter] = n - i + 1;
		BinSort(StepWidth);
//		Debug();
	}
	for(int i = 1; i <= n; i++) printf("%d ", reflact[i]); printf("\n");
	return 0;
}
