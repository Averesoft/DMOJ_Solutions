#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    double num = 180 - 180.0 * (N - 2) / N;
    printf("%.6f", num);
}