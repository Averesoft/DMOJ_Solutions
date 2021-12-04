#include <bits/stdc++.h>
using namespace std;
const int mm = 1000 + 5;
int D; double dimes[mm], Q, quarters[mm];
double mid = INT_MAX, mad = INT_MIN, miq = INT_MAX, maq = INT_MIN;
int main() {
    cin >> D;
    for (int i = 0; i < D; i++) {
        cin >> dimes[i];
        mid = min(mid, dimes[i]);
        mad = max(mad, dimes[i]);
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> quarters[i];
        miq = min(miq, quarters[i]);
        maq = max(maq, quarters[i]);
    }
    mid /= 10; mad /= 10; miq /= 25; maq /= 25; 
    if (mad > miq) {
        cout << "Dimes are better";
    } else if (maq > mid) {
        cout << "Quarters are better";
    } else {
        cout << "Neither coin is better";
    }
}