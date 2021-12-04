#include <bits/stdc++.h>
using namespace std;
string a[] = {"甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"}, b[] = {"子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"};
int main() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int y; cin >> y; 
        if (y <= 0) {
            y--;
        }
        y = abs(y - 1984); 
        y %= 60;
        int cnt = 0, x = 0, z = 0;
        while (1) {
            if (cnt == y) {
                cout << a[x] + b[z] << '\n';
                break;
            }
            x++; z++;
            if (x >= 10) {
                x = 0;
            }
            if (z >= 12) {
                z = 0; 
            }
            cnt++;
        }
    }
}