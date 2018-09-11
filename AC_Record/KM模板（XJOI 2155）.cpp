#include <cstdio>
#include <cstring>
#include <algorithm>

const int INF = 2147483647;
const int Maxn = 510, Maxm = 510, Maxk = 1000010;
int n, m, k;
int MinDelta;
int Map[Maxn][Maxm], ValueX[Maxn], ValueY[Maxm], VisitedX[Maxn], VisitedY[Maxm], LinkX[Maxn], LinkY[Maxm];

void clean() {
    memset(Map, 0, sizeof(Map));
    memset(ValueX, 0, sizeof(ValueX));
    memset(ValueY, 0, sizeof(ValueY));
    memset(VisitedX, 0, sizeof(VisitedX));
    memset(VisitedY, 0, sizeof(VisitedY));
    memset(LinkX, 0, sizeof(LinkX));
    memset(LinkY, 0, sizeof(LinkY));
    return;
}

bool dfs(int Y) {
    VisitedY[Y] = 1;
    for(int i = 1; i <= n; i++) {
        if(VisitedX[i] == 1) continue;
        int Delta = ValueX[i] + ValueY[Y] - Map[i][Y];
        if(Delta == 0) {
            VisitedX[i] = 1;
            if(LinkX[i] == 0 || dfs(LinkX[i])) {
                LinkX[i] = Y; LinkY[Y] = i;
                return true;
            }
        }
        if(Delta > 0) MinDelta = std::min(MinDelta, Delta);
    }
    return false;
}

bool dfs2(int X) {
    VisitedX[X] = 1;
    for(int i = 1; i <= m; i++) {
        if(VisitedY[i] == 1) continue;
        int Delta = ValueX[X] + ValueY[i] - Map[X][i];
        if(Delta == 0) {
            VisitedY[i] = 1;
            if(LinkY[i] == 0 || dfs2(LinkY[i])) {
                LinkX[X] = i; LinkY[i] = X;
                return true;
            }
        }
        if(Delta > 0) MinDelta = std::min(MinDelta, Delta);
    }
    return false;
}

int main() {
    clean();
    scanf("%d%d%d", &n, &m, &k);
    if(m <= n) {
        for(int i = 1; i <= k; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            Map[x][y] = std::max(Map[x][y], z);
            ValueY[y] = std::max(ValueY[y], z);
        }
        for(int i = 1; i <= m; i++) 
            while(1) {
                MinDelta = INF; 
                memset(VisitedX, 0, sizeof(VisitedX));
                memset(VisitedY, 0, sizeof(VisitedY));
                if(dfs(i)) break;
                for(int j = 1; j <= m; j++) 
                    if(VisitedY[j]) ValueY[j] -= MinDelta;
                for(int j = 1; j <= n; j++) 
                    if(VisitedX[j]) ValueX[j] += MinDelta;
            }
        int ans = 0;
        for(int i = 1; i <= m; i++) 
            ans += Map[LinkY[i]][i];
        printf("%d\n", ans);
        return 0;
    }
    if(m > n) {
        for(int i = 1; i <= k; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            Map[x][y] = std::max(Map[x][y], z);
            ValueX[x] = std::max(ValueX[x], z);
        }
        for(int i = 1; i <= n; i++) 
            while(1) {
                MinDelta = INF; 
                memset(VisitedX, 0, sizeof(VisitedX));
                memset(VisitedY, 0, sizeof(VisitedY));
                if(dfs2(i)) break;
                for(int j = 1; j <= m; j++) 
                    if(VisitedY[j]) ValueY[j] += MinDelta;
                for(int j = 1; j <= n; j++) 
                    if(VisitedX[j]) ValueX[j] -= MinDelta;
            }
        int ans = 0;
        for(int i = 1; i <= n; i++) 
            ans += Map[i][LinkX[i]];
        printf("%d\n", ans);
        return 0;
    }
    return 0;
}

