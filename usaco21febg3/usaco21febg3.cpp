#include <bits/stdc++.h>
using namespace std;
#define cl(ar, val)  memset(ar, val, sizeof(ar))
typedef long long ll;
const int M = 40;
int Q, x[M], y[M], d[M]; ll xv, yv, dv, dp[M][2][2][2];
void f(ll n, int a[]){
    for(int p=0; n; p++, n/=3) a[p] = n % 3;
}
bool chk(int a, int b){
    if(a < 0 || b < 0 || a > 2 || b > 2) return false;
    return (a&1) == (b&1);
}
ll fun(int pos, int lmt, int xc, int yc){
    if(pos < 0) return (xc == 0) && (yc == 0);
    ll &ret = dp[pos][lmt][xc][yc];
    if(ret != -1) return ret;
    ret = 0; int up = lmt? d[pos]:2;
    for(int v=0; v<=up; v++){
        for(int c1=0; c1<=1; c1++){
            for(int c2 =0; c2 <=1; c2++){
                if(chk(x[pos]+v-3*xc+c1, y[pos]+v-3*yc+c2)){
                    ret += fun(pos-1, lmt && v==d[pos], c1, c2);
                }
            }
        }
    }
    return ret;
}
int main(){
    for(cin >> Q; Q--; ){
        cin >> dv >> xv >> yv;
        cl(x, 0); cl(y, 0); cl(d, 0);  cl(dp, -1);
        f(xv, x); f(yv, y); f(dv, d);
        cout << fun(M-1, 1, 0, 0) << "\n";
    }
}