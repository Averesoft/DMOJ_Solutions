/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll K, D;
ll mi = 10;
int main() {
    cin >> K >> D;
    bool zero = 0;
    for (ll i = 0, num; i < D; i++) {
        cin >> num;
        if (mi > num && num != 0) {
            mi = num;
        }
        if (num == 0) {
            zero = 1;
        }
    }
    if (mi == 10) {
        cout << -1;
    } else {
        if (zero) {
            cout << mi;
            for (int i = 1; i < K - 1; i++) {
                cout << 0;
            }
            if (K != 1) {   
                cout << mi;
            }
        } else {
            for (ll i = 0; i < K; i++) {
                cout << mi;
            }
        }
    }
}
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    if (A < B && C < D) {
        cout << "Go to the department store";
    } else if (A < B) {
        cout << "Go to the grocery store";
    } else if (C < D) {
        cout << "Go to the pharmacy";
    } else {
        cout << "Stay home";
    }
    cout << "\n";
}