#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
int main() {
    cin >> N >> M;
    cout << (N + 100000 * M) % M;
}