#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mm = 2 * 1e3 + 5;
ll n, s[mm], psa[mm];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i]; psa[i] += psa[i - 1] + s[i];
    }
    for (int l = 1; l <= n; l++) {
        
    }
}