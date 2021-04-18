#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int sum = 0;
    switch (a){
        case 1: sum += 461;
        break;
        case 2: sum += 431;
        break;
        case 3: sum += 420;
        break;
    }
    switch (c){
        case 1: sum += 130;
        break;
        case 2: sum += 160;
        break;
        case 3: sum += 118;
        break;
    }
    switch (b){
        case 1: sum += 100;
        break;
        case 2: sum += 57;
        break;
        case 3: sum += 70;
        break;
    }
    switch (d){
        case 1: sum += 167;
        break;
        case 2: sum += 266;
        break;
        case 3: sum += 75;
        break;
    }
    cout << "Your total Calorie count is " << sum << '.';
}