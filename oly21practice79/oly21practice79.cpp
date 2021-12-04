#include <bits/stdc++.h>
using namespace std;
const int mm = 100000 + 5;
int N, a[mm];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + N);
    int pre = a[1]; int ma = 1; int maval = a[1]; int cnt = 1;
    for (int i = 2; i <= N; i++) {
        if (a[i] != pre) {
            if (cnt > ma) {
                ma = cnt;
                maval = pre;
            }
            cnt = 0; pre = a[i];
        }        
        cnt++;
    }
    cout << maval;
}