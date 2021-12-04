#include <bits/stdc++.h>

#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int MN = (int) 1e5 + 6;

int n, q;

int sieve[MN], arr[MN];
vector<int> primes;
vector<int> pfactor[MN], segtree[4 * MN];

void siev() {
    for(int i = 2; i <= MN; ++i) {
        for(int j = i; j < MN; j += i) {
            ++sieve[j];
        }
        if(sieve[i] == 1) primes.push_back(i);
    }
}

void build(int node, int cl, int cr) {
    if(cl == cr) {
        segtree[node - 1] = pfactor[cl];
        return;
    }
    int mid = (cl + cr) / 2;
    build(2 * node, cl, mid);
    build(2 * node + 1, mid + 1, cr);
    int pt1 = 0;
    int pt2 = 0;
    vector<int> v1 = segtree[2 * node - 1];
    vector<int> v2 = segtree[2 * node];
    while(pt1 < v1.size() && pt2 < v2.size()) {
        int a = v1[pt1];
        int b = v2[pt2];
        if(a == b) {
            ++pt1;
            ++pt2;
        } else if(a < b) {
            segtree[node - 1].push_back(a);
            ++pt1;
        } else if(a > b) {
            segtree[node - 1].push_back(b);
            ++pt2;
        }
    }
    while(pt1 < v1.size()) {
        segtree[node - 1].push_back(v1[pt1]);
        ++pt1;
    }
    while(pt2 < v2.size()) {
        segtree[node - 1].push_back(v2[pt2]);
        ++pt2;
    }
}

vector<int> query(int l, int r, int node, int cl, int cr) {
    if(cl == cr) {
        return segtree[node - 1];
    }
    int mid = (cl + cr) / 2;
    vector<int> v1, v2;
    if(l <= cl && cr < r) {
        return segtree[node - 1];
    }
    if(l <= mid) {
        v1 = query(l, r, 2 * node, cl, mid);
    }
    if(r > mid) {
        v2 = query(l, r, 2 * node + 1, mid + 1, cr);
    }
    if(v1.size() == 0 && v2.size() == 0) return v1;
    if(v1.size() > 0 && v2.size() == 0) return v1;
    if(v1.size() == 0 && v2.size() > 0) return v2;
    vector<int> x;
    int pt1 = 0; int pt2 = 0;
    while(pt1 < v1.size() && pt2 < v2.size()) {
        int a = v1[pt1];
        int b = v2[pt2];
        if(a == b) {
            ++pt1;
            ++pt2;
        } else if(a < b) {
            x.push_back(a);
            ++pt1;
        } else if(a > b) {
            x.push_back(b);
            ++pt2;
        }
    }
    while(pt1 < v1.size()) {
        x.push_back(v1[pt1]);
        ++pt1;
    }
    while(pt2 < v2.size()) {
        x.push_back(v2[pt2]);
        ++pt2;
    }
    return x;
}

void _main() {
    cin >> n >> q;
    siev();
    for(int i = 0; i < n; ++i) cin >> arr[i];
    for(int i = 0; i < n; ++i) {
        int x = arr[i];
        for(int j : primes) {
            int cnt = 0;
            while(x % j == 0) {
                x /= j;
                ++cnt;
            }
            if(cnt % 2 == 1) pfactor[i].push_back(j);
        }
    }
    build(1, 0, n - 1);
    for(int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        vector<int> x = query(l, r, 1, 0, n - 1);
        cout << ((x.size() == 0) ? "yes" : "no") << endl;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    _main();
    return 0;
}