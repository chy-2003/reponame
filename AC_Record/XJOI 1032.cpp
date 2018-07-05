//XJOI 1032
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int a, b, c;
};
int A, B, C, rec[160][160][160];
int l, r, k;
Node q[3442960], t;
int qq[3442960];
int finished(Node x){
    int cnt = 0;
    if(x.a == A / 2) cnt++;
    if(x.b == A / 2) cnt++;
    if(x.c == A / 2) cnt++;
    return (cnt == 2) ? 1 : 0;
}
int main(){
    cin >> A >> B >> C;
    memset(rec, 0, sizeof(rec));
    rec[A][0][0] = 1;
    l = 0; r = 1;
    q[1].a = A; q[1].b = 0; q[1].c = 0; qq[1] = 0;
    while(l < r){
        l++;
        //A->B
        t = q[l];
        k = min(t.a, B - t.b);
        t.b += k; t.a -= k;
        if(rec[t.a][t.b][t.c] == 0){
            rec[t.a][t.b][t.c] = 1;
            r++;
            q[r] = t;
            qq[r] = qq[l] + 1;
            if(finished(t)){
                cout << qq[r];
                return 0;
            }
        }
        //A->C
        t = q[l];
        k = min(t.a, C - t.c);
        t.c += k; t.a -= k;
        if(rec[t.a][t.b][t.c] == 0){
            rec[t.a][t.b][t.c] = 1;
            r++;
            q[r] = t;
            qq[r] = qq[l] + 1;
            if(finished(t)){
                cout << qq[r];
                return 0;
            }
        }
        //B->A
        t = q[l];
        k = min(t.b, A - t.a);
        t.a += k; t.b -= k;
        if(rec[t.a][t.b][t.c] == 0){
            rec[t.a][t.b][t.c] = 1;
            r++;
            q[r] = t;
            qq[r] = qq[l] + 1;
            if(finished(t)){
                cout << qq[r];
                return 0;
            }
        }
        //B->C
        t = q[l];
        k = min(t.b, C - t.c);
        t.c += k; t.b -= k;
        if(rec[t.a][t.b][t.c] == 0){
            rec[t.a][t.b][t.c] = 1;
            r++;
            q[r] = t;
            qq[r] = qq[l] + 1;
            if(finished(t)){
                cout << qq[r];
                return 0;
            }
        }
        //C->A
        t = q[l];
        k = min(t.c, A - t.a);
        t.a += k; t.c -= k;
        if(rec[t.a][t.b][t.c] == 0){
            rec[t.a][t.b][t.c] = 1;
            r++;
            q[r] = t;
            qq[r] = qq[l] + 1;
            if(finished(t)){
                cout << qq[r];
                return 0;
            }
        }
        //C->B
        t = q[l];
        k = min(t.c, B - t.b);
        t.b += k; t.c -= k;
        if(rec[t.a][t.b][t.c] == 0){
            rec[t.a][t.b][t.c] = 1;
            r++;
            q[r] = t;
            qq[r] = qq[l] + 1;
            if(finished(t)){
                cout << qq[r];
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}