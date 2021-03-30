#include <bits/stdc++.h>
using namespace std;
#define lc (2*rt)
#define rc (2*rt+1)
const int MM = 1e5+5;
typedef vector<int> vi;
struct node { int l, r, lz; vi f;} seg[3*MM];
int N, M, K, x;
vi join(vi &l, vi &r){
    vi ret(K+1, 0);
    for(int i=1; i<=K; i++) ret[i] = l[i] + r[i];
    return ret;
}
void down(int rt){
    vi &lv = seg[lc].f, &rv = seg[rc].f; int lz = seg[rt].lz;
    fill(lv.begin(), lv.end(), 0); fill(rv.begin(), rv. end(), 0);
    lv[lz] = seg[lc].r - seg[lc].l + 1;  rv[lz] = seg[rc].r - seg[rc].l + 1;
    seg[lc].lz = lz;  seg[rc].lz = lz;  seg[rt].lz = 0;
}
void build(int l, int r, int rt){
    seg[rt].l = l; seg[rt].r = r;  seg[rt].f.resize(K+1);
    if(l == r){ cin>>x; seg[rt].f[x]=1; return; }
    int mid = (l + r)/2;
    build(l, mid, lc); build(mid+1, r, rc); seg[rt].f = join(seg[lc].f, seg[rc].f);
}
void update(int l, int r, int val, int rt){
    if(seg[rt].l == l && seg[rt].r == r) {
        fill(seg[rt].f.begin(), seg[rt].f.end(), 0); seg[rt].f[val]=r-l+1; seg[rt].lz=val; return;
    }
    if(seg[rt].lz) down(rt);
    int mid = (seg[rt].l + seg[rt].r)/2;
    if(r <= mid) update(l, r, val, lc);
    else if(l > mid) update(l, r, val, rc);
    else { update(l, mid, val, lc); update(mid+1, r, val, rc); }
    seg[rt].f = join(seg[lc].f, seg[rc].f);
}
vi query(int l, int r, int rt){
    if(seg[rt].l == l && seg[rt].r == r) return seg[rt].f;
    if(seg[rt].lz) down(rt);
    int mid = (seg[rt].l + seg[rt].r)/2;
    if(r <= mid) return query(l, r, lc);
    if(l > mid) return query(l, r, rc);
    vi ql = query(l, mid, lc), qr = query(mid+1, r, rc);  return join(ql, qr);
}
void print(int l, int r, int rt){
    if(l == r){
        for(int i=1; i<=K; i++)
            if(seg[rt].f[i] > 0) { cout << i << " "; return; }
    }
    if(seg[rt].lz) down(rt);
    int mid = (l + r)/2; print(l, mid, lc); print(mid+1, r, rc);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;  build(1, N, 1);
    for(int i=1, l, r; i<=M; i++){
        cin >> l >> r; vi tmp = query(l, r, 1);
        for(int j=1, p; j<=K; j++){
            cin >> p;
            if(tmp[p]>0) { update(l, l+tmp[p]-1, p, 1); l+=tmp[p]; }
        }
    }
    print(1, N, 1);  cout << endl;
}