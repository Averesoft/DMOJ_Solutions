#include <bits/stdc++.h>
using namespace std;
#define lc (2*id)
#define rc (2*id+1)
typedef long long ll;
const int MM = 1e5 + 3;
struct node { int l, r; ll pre, suf, sum, ans; } seg[3*MM];
int N, Q; char op;
void push_up(int id){
    seg[id].pre = max(seg[lc].pre, seg[lc].sum + seg[rc].pre);
    seg[id].suf = max(seg[rc].suf, seg[rc].sum + seg[lc].suf);
    seg[id].sum = seg[lc].sum + seg[rc].sum;
    seg[id].ans = max(seg[lc].suf+seg[rc].pre, max(seg[lc].ans, seg[rc].ans));
}
void build(int l, int r, int id){
    seg[id].l = l; seg[id].r = r;
    if(l == r){cin>>seg[id].sum; seg[id].pre = seg[id].suf = seg[id].ans = seg[id].sum; return; }
    int mid = (seg[id].l + seg[id].r)/2;
    build(l, mid, lc); build(mid+1, r, rc);  push_up(id);
}
void update(int pos, int val, int id){
    if(seg[id].l == seg[id].r){seg[id].pre = seg[id].suf = seg[id].ans =seg[id].sum=val; return;}
    int mid = (seg[id].l + seg[id].r)/2;
    if(pos <= mid) update(pos, val, lc);
    else update(pos, val, rc);
    push_up(id);
}
node query(int l, int r, int id) {
    if(seg[id].l==l && seg[id].r==r) return seg[id];
    int mid = (seg[id].l + seg[id].r)/2;
    if(r <= mid) return query(l, r, lc);
    else if(l > mid) return query(l, r, rc);
    else {
        node lv = query(l, mid, lc), rv = query(mid+1, r, rc), ret;
        ret.pre = max(lv.pre, lv.sum + rv.pre);
        ret.suf = max(rv.suf, rv.sum + lv.suf);
        ret.sum = lv.sum + rv.sum;
        ret.ans = max(lv.suf+rv.pre, max(lv.ans, rv.ans));
        return ret;
    }
}
int main(){
    cin >> N >> Q; build(1, N, 1);
    for(int i=1, x, y; i<= Q; i++){
        cin >> op >> x >> y;
        if(op == 'S') update(x, y, 1);
        else cout << query(x, y, 1).ans << "\n";
    }
}