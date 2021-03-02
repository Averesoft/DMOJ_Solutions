#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> pi;
const int MM = 100005;
struct node{ int l, r, val, lzy; } seg[6*MM];
int T, N; pi a[MM]; vector<int> lft[2*MM], rit[2*MM], p;
void push_down(int rt){
    seg[2*rt].lzy += seg[rt].lzy; seg[2*rt].val += seg[rt].lzy;
    seg[2*rt+1].lzy += seg[rt].lzy; seg[2*rt+1].val += seg[rt].lzy;
    seg[rt].lzy = 0;
}
void build(int l, int r, int rt){
    seg[rt].l = l; seg[rt].r = r;
    if(l == r) {lft[l].clear(); rit[l].clear(); return;}
    int mid = (l + r)/2;
    build(l, mid, 2*rt); build(mid+1, r, 2*rt+1);
}
void upd(int l, int r, int val, int rt){
    if(seg[rt].l == l && seg[rt].r == r){
        seg[rt].val += val; seg[rt].lzy += val; return;
    }
    if(seg[rt].lzy) push_down(rt);
    int mid = (seg[rt].l + seg[rt].r)/2;
    if(r <= mid) upd(l, r, val, 2*rt);
    else if(l > mid) upd(l, r, val, 2*rt+1);
    else{ upd(l, mid, val, 2*rt); upd(mid+1, r, val, 2*rt+1); }
    seg[rt].val = max(seg[2*rt].val, seg[2*rt+1].val);
}
int main(){
    //freopen("test.txt", "r", stdin);
    scanf("%d", &T);
    for(int tt=1; tt<=T; tt++){
        memset(seg, 0, sizeof(seg)); p.clear();
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf("%d %d", &a[i].x, &a[i].y);
            p.push_back(a[i].x); p.push_back(a[i].y);
        }
        sort(p.begin(), p.end()); p.resize(unique(p.begin(), p.end()) - p.begin());
        build(0, p.size()-1, 1);
        for(int i=0; i<N; i++){
            a[i].x = lower_bound(p.begin(), p.end(), a[i].x) - p.begin();
            a[i].y = lower_bound(p.begin(), p.end(), a[i].y) - p.begin();
            upd(a[i].x, a[i].y, 1, 1); lft[a[i].x].push_back(i); rit[a[i].y].push_back(i);
        }
        int ans = 0, cnt = 0;
        for(int t=0; t<p.size(); t++){
            for(int i: lft[t]){
                cnt++; upd(a[i].x, a[i].y, -1, 1);
            }
            ans = max(ans, cnt+seg[1].val);
            for(int i: rit[t]){
                cnt--; upd(a[i].x, a[i].y, 1, 1);
            }
        }
        printf("Case %d: %d\n", tt, ans);
    }
}