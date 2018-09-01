#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize(2) 
#pragma GCC optimize("-fdelete-null-pointer-checks,inline-functions-called-once,-funsafe-loop-optimizations,-fexpensive-optimizations,-foptimize-sibling-calls,-ftree-switch-conversion,-finline-small-functions,inline-small-functions,-frerun-cse-after-loop,-fhoist-adjacent-loads,-findirect-inlining,-freorder-functions,no-stack-protector,-fpartial-inlining,-fsched-interblock,-fcse-follow-jumps,-fcse-skip-blocks,-falign-functions,-fstrict-overflow,-fstrict-aliasing,-fschedule-insns2,-ftree-tail-merge,inline-functions,-fschedule-insns,-freorder-blocks,-fwhole-program,-funroll-loops,-fthread-jumps,-fcrossjumping,-fcaller-saves,-fdevirtualize,-falign-labels,-falign-loops,-falign-jumps,unroll-loops,-fsched-spec,-ffast-math,Ofast,inline,-fgcse,-fgcse-lm,-fipa-sra,-ftree-pre,-ftree-vrp,-fpeephole2",3)
#pragma GCC target("avx","sse2")
#include <cstdio>
#include <cstring>
using namespace std;
const int bz[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int n, m, ans;
char map[60][60];
int endx, endy;
int l, r, q[5100][2];
int key, door;
int touch[50][2];
char map2[60][60];
void pre_bfs() {
    l = 0;
    r = 1;
    q[1][0] = endx;
    q[1][1] = endy;
    while(l < r) {
        l++;
        for(int i = 0; i < 4; ++i) {
            endx = q[l][0] + bz[i][0];
            endy = q[l][1] + bz[i][1];
            if(map[endx][endy] == '#' || map[endx][endy] == '*') continue;
            if(map[endx][endy] >= 'A' && map[endx][endy] <= 'Z') continue;
            map[endx][endy] = '*';
            r++;
            q[r][0] = endx; q[r][1] = endy;
        }
    }
    return;
}
inline void clone() {
    for(int i = 0; i <= n + 1; ++i) 
        for(int j = 0; j <= m + 1; ++j) 
            map2[i][j] = map[i][j];
    return;
}
bool bfs(int x, int y) {
    clone();
    map2[x][y] = '#';
    l = r = 0;
    key = door = 0;
    r = 1;
    q[1][0] = x; q[1][1] = y;
    while(l < r) {
        l++;
        for(int i = 0; i < 4; ++i) {
            x = q[l][0] + bz[i][0];
            y = q[l][1] + bz[i][1];
            if(map2[x][y] == '#') continue; else
            if(map2[x][y] == '*') return true; else
            if(map2[x][y] >= 'a' && map2[x][y] <= 'z') {
                key |= 1 << (map2[x][y] - 'a');
                if(door & (1 << (map2[x][y] - 'a'))) {
                    door ^= (1 << (map2[x][y] - 'a'));
                    ++r;
                    q[r][0] = touch[map2[x][y] - 'a'][0];
                    q[r][1] = touch[map2[x][y] - 'a'][1];
                }
                ++r;
                q[r][0] = x; q[r][1] = y;
                map2[x][y] = '#';
            } else
            if(map2[x][y] >= 'A' && map2[x][y] <= 'Z') {
                if(key & (1 << (map2[x][y] - 'A'))) {
            	    ++r;
                	q[r][0] = x; q[r][1] = y;
                	map2[x][y] = '#';
                } else {
                    door |= (1 << (map2[x][y] - 'A'));
                    touch[map2[x][y] - 'A'][0] = x; touch[map[x][y] - 'A'][1] = y;
                    map2[x][y] = '#';
                }
            } else
            if(map2[x][y] == '.') {
                ++r;
                q[r][0] = x; q[r][1] = y;
                map2[x][y] = '#';
            }
        }
    }
    return false;
}
void init() {
    for(int i = 1; i <= n; ++i)
    	for(int j = 1; j <= m; ++j)
    		if(map[i][j] == '*') {
    			endx = i;
    			endy = j;
    			return;
    		}
    return;
}
int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) {
    	scanf("%s", map[i] + 1);
    	map[i][m + 1] = '#';
    	map[i][0] = '#';
    }
    for(int i = 1; i <= m; ++i) {
        map[0][i] = '#';
        map[n + 1][i] = '#';
    }
    map[0][0] = map[n + 1][0] = map[0][m + 1] = map[n + 1][m + 1] = '#';
    init();
//    for(int i = 0; i <= n + 1; ++i) {
//    	for(int j = 0; j <= m + 1; j++) printf("%c", map[i][j]); printf("\n");
//    }
    pre_bfs();
//    printf("*\n");
    ans = 0;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j) {
            if(map[i][j] != '.') continue;
            if(bfs(i, j)) ans++;
//            printf("%d %d finish\n", i, j);
        }
    printf("%d\n", ans);
    return 0;
}
