#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef pair<int, int> pii;
struct pp {
    int x, y;
    bool operator<(const pp&b) const {
        if (y < 0) {
            if (b.y < 0) {
                return x > b.x;
            } else {
                return false;
            }
        } else if (b.y < 0) {
            if (y < 0) {
                return x > b.x;
            } else {
                return true;
            }
        } else {
            return x < b.x;
        }
    }
};
int n;
set<pp> st;
int main() {
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        if (abs(x % 4) != 0 && abs(y % 4) / abs(x % 4) == 1) {
            st.insert({x, y});
            st.insert({x + 1, y});
            st.insert({x, y + 1});
            st.insert({x + 1, y + 1});
        } else {
            st.insert({x - 1, y});
            st.insert({x - 1, y + 1});
            st.insert({x, y + 2});
            st.insert({x + 1, y + 2});
            st.insert({x + 2, y + 1});
            st.insert({x + 2, y});
            st.insert({x + 1, y - 1});
            st.insert({x, y - 1});
        }
    }
    cout << st.size() << '\n';
    for (pp u : st) {
        cout << u.x << ' ' << u.y << '\n';
    }
}