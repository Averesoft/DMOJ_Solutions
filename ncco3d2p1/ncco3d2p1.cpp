#include <bits/stdc++.h>
using namespace std;
const int mm = 5 * 1e4;
int a[mm], mini[mm * 2], maxi[mm*2];
int n, q;
void construct() {
    for (int i = 1; i <= n; i++) {
        mini[i + n] = a[i];
        maxi[i + n] = a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        mini[i] = min(mini[i * 2], mini[2 * i + 1]);
        maxi[i] = max(maxi[i * 2], maxi[2 * i + 1]);
    }
}
int range(int a, int b) {
    int l = a, r = b;
    int minimum = INT_MAX, maximum = -INT_MAX;
    l += n; r += n;
    while (l < r) {
        if (l % 2 == 1) {
            minimum = min(minimum, mini[l]);
            maximum = max(maximum, maxi[l]);
            l++;
        }
        if (r % 2 == 1) {
            r--;
            minimum = min(minimum, mini[r]);
            maximum = max(maximum, maxi[r]);
        }
        l /= 2, r /= 2;
    }
    return maximum - minimum;
}
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    construct();
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;
        cout << range(a, b+1) << '\n';
    }
}