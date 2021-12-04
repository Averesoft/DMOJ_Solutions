#include <bits/stdc++.h>
using namespace std;
const int mm = 1e6 + 5;
int N, a[mm];
deque<int> dq;
queue<char> ch;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i]; dq.push_back(a[i]);
    }
    sort(dq.begin(), dq.end());
    while(!dq.empty()) {
        if (dq.size() == 1) {
            cout << dq[0]; ch.push('E');
            break;
        }
        cout << dq[0] << ' ' << dq[dq.size() - 1];
        dq.pop_front(); dq.pop_back();
        ch.push('B'); ch.push('S');
        if (!dq.empty()) {
            cout << ' ';
        }
    }
    cout << '\n';
    while(!ch.empty()) {
        cout << ch.front(); ch.pop();
    }
    cout << '\n';
}