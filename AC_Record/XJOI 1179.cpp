//XJOI 1179
#includebitsstdc++.h
#define LL long long
using namespace std;
int main(){
    int x, y, z;
    scanf(%d%d%d, &x, &y, &z);
    x = abs(x) + abs(y);
    if(z  x){
        printf(No);
        return 0;
    }
    if((z - x) % 2){
        printf(No);
        return 0;
    }
    printf(Yes);
    return 0;
}