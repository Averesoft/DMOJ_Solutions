#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm =  2 * 1e5 + 5;
int n, m, k;
pii arr[mm];
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        arr[i].first = arr[i].second = -1;
    }
    for (int i = 0, a, b, c; i < k; i++) {
        cin >> a >> b >> c;
        if (arr[b].second < c) {
            arr[b].first = a; arr[b].second = c;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i].first << ' ';
    }
}