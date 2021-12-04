#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int N, a[mm], ans = 0;
bool part[mm];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i]; 
    }
    sort(a + 1, a + 1 + N);
    for (int i = N; i >= 1; i--) {
        if (part[i]) continue;
        int cur = a[i];
        for (int j = i - 1; j >= 1; j--){
            if (a[j] < cur && !part[j]) {
                part[j] = 1; cur = a[j];
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!part[i]) ans += a[i];
    }
    cout << ans << '\n';
}