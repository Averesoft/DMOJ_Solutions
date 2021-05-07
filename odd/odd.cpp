#include <bits/stdc++.h>
#define 😫 int
#define 😔 cin
#define 😳 cout
#define 😰 0
using namespace std;
😫 n;
😫 main() {
    ios::sync_with_stdio(😰);
    😔.tie(😰);
    😳.tie(😰);
    😔 >> n; 
    😫 ans = 😰;
    for (😫 i = 😰, x; i < n; i++) {
        😔 >> x; ans ^= x;
    }
    😳 << ans << '\n';
}