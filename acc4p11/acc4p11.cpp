#include <bits/stdc++.h>
using namespace std;
bool f(int n) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            for (int k = 0; k < 100; k++) {
                if (pow(i, 3) + pow(j, 3) + pow(k, 3) == n) {
                    return 1;
                }
            }
        }
    }
    return 0;
}