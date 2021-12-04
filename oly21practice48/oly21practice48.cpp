#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mm = 1e5 + 5;
ll N, Q, K;
int main() { 
    ios::sync_with_stdio(0);
    cin >> N >> Q;
    vector<ll> v;
    for (ll i = 0, tmp; i < N; i++) {
        cin >> tmp; 
        if (tmp > 0) {
            v.push_back(tmp);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 1; i < v.size(); i++) {
        v[i] += v[i - 1];
    }
    for (int i = 0; i < Q; i++) {
        cin >> K;
        if (K >= v.size()) {
            cout << v[v.size() - 1] << '\n';
        } else {
            cout << v[K - 1] << '\n';
        }
    }
}