#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000010, MAXLEN = 2000010, alpha_size = 26;
int n;
char ch, st1[MAXLEN], st2[MAXLEN];
int usedlen1, usedlen2, rec1[MAXN], rec2[MAXN], num1, num2;
int trie[MAXLEN][alpha_size], note[MAXLEN], usedspace, isleaf[MAXLEN];

int ansnum;
string ansrec[MAXN];
int fail;

void get_ans(int pos, string s);

int main() {
	usedlen1 = usedlen2 = 0;
	num1 = num2 = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		ch = getchar();
		while(ch != '+' && ch != '-') ch = getchar();
		if(ch == '-') { rec1[++num1] = usedlen1; scanf("%s", st1 + usedlen1); usedlen1 += strlen(st1 + usedlen1); }
		if(ch == '+') { rec2[++num2] = usedlen2; scanf("%s", st2 + usedlen2); usedlen2 += strlen(st2 + usedlen2); }
	}
	rec1[num1 + 1] = usedlen1;
	rec2[num2 + 1] = usedlen2;

	usedspace = 1;
	for(int i = 1; i <= num1; i++) {
		int pos = 1;
		for(int j = rec1[i]; j < rec1[i + 1]; j++) {
			if(trie[pos][st1[j] - 'a'] == 0) trie[pos][st1[j] - 'a'] = ++usedspace;
			pos = trie[pos][st1[j] - 'a'];
		}
		isleaf[pos] = 1;
	}

	note[1] = 1;
	for(int i = 1; i <= num2; i++) {
		int pos = 1;
		for(int j = rec2[i]; j < rec2[i + 1]; j++) {
			if(trie[pos][st2[j] - 'a'] == 0) break;
			pos = trie[pos][st2[j] - 'a'];
			note[pos] = 1;
		}
	}

	ansnum = 0;
	fail = 0;
	get_ans(1, "");

	if(fail) { cout << "-1" << endl; return 0; }
	cout << ansnum << endl;
	for(int i = 1; i <= ansnum; i++) cout << ansrec[i] << endl;
	return 0;
}

void get_ans(int pos, string s) {
	if(note[pos] == 0) {
		ansrec[++ansnum] = s;
		return;
	}
	if(isleaf[pos]) {
		fail = 1;
		return;
	}
	for(int i = 0; i < alpha_size; i++) {
		if(trie[pos][i] == 0) continue;
		get_ans(trie[pos][i], s + string(1, 'a' + i));
		if(fail) return;
	}
	return;
}
