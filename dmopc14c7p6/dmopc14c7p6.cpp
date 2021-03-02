#include <bits/stdc++.h>
using namespace std;
const int maxN=100002; int N, ans, val[maxN];
struct node{int l, r, pre, s;}tr[3*maxN];
void build(int l, int r, int rt){
    tr[rt].l=l; tr[rt].r=r;
    if(l==r) return;
    build(l, (l+r)/2, rt<<1);
    build((l+r)/2+1, r, rt<<1|1);
}
void update(int x, int val, int rt){
    if(tr[rt].l==tr[rt].r && tr[rt].l==x){
        tr[rt].s=val; tr[rt].pre=val; return;
    }
    int mid=(tr[rt].l+tr[rt].r)/2;
    if(x<=mid) update(x, val, rt<<1);
    else update(x, val, rt<<1|1);
    tr[rt].s = tr[rt<<1].s+tr[rt<<1|1].s;
    tr[rt].pre = min(tr[rt<<1].pre, tr[rt<<1].s+tr[rt<<1|1].pre);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d", &N);
    build(1, N, 1);
    for(int i=1; i<=N; i++)
        scanf("%d", &val[i]);
    for(int i=1; i<=N/2; i++){
        update(val[2*i-1], 1, 1);
        update(val[2*i], 1, 1);
        update(val[i], -1, 1);
        if(!tr[1].pre) ans = i;
    }
    printf("%d\n", ans);
}