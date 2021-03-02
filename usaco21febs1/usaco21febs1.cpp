#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int mm = 1e4 + 5;
int n;
short grid[mm][mm];
vector<pii> cows;
int main() {
    memset(grid, 0, sizeof grid);
    cin >> n;
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y; x++; y++;
        grid[x][y] = 1;
        cows.push_back({x, y});
        int times = 0;
        for (int j = 0; j < cows.size(); j++) {
            pii u = cows[j];
            if (grid[u.first][u.second] > 0) {
                int count = 0;
                if (grid[u.first-1][u.second] > 0) {
                    count++; 
                } 
                if (grid[u.first+1][u.second] > 0) {
                    count++;
                } 
                if (grid[u.first][u.second-1] > 0) {
                    count++;
                } 
                if (grid[u.first][u.second+1] > 0) {
                    count++;
                }
                if (count == 3) {
                    if (!grid[u.first-1][u.second]) {
                        grid[u.first-1][u.second] = 2;
                        cows.push_back({u.first-1, u.second}); 
                    } else if (!grid[u.first+1][u.second]) {
                        grid[u.first+1][u.second] = 2;
                        cows.push_back({u.first+1, u.second}); 
                    } else if (!grid[u.first][u.second-1]) {
                        grid[u.first][u.second-1] = 2;
                        cows.push_back({u.first, u.second-1}); 
                    } else if (!grid[u.first][u.second+1]) {
                        grid[u.first][u.second+1] = 2;
                        cows.push_back({u.first, u.second+1}); 
                    }
                    times++;
                    j = 0;
                }
            }
        }
        for (int j = 0; j < cows.size(); j++) {
            pii u = cows[j];
            if (grid[u.first-1][u.second] == 2) {
                grid[u.first-1][u.second] = 0;
            } 
            if (grid[u.first+1][u.second] == 2) {
                grid[u.first+1][u.second] = 0;
            } 
            if (grid[u.first][u.second-1] == 2) {
                grid[u.first][u.second-1] = 0;
            } 
            if (grid[u.first][u.second+1] == 2) {
                grid[u.first][u.second+1] = 0;
            }
        }
        cout << times << '\n';
    }
}

/*
        int times = 0;
        for (int j = 0; j < cows.size(); j++) {
            pii u = cows[j];
            int count = 0;
            if (grid[u.first-1][u.second]) {
                count++; 
            } 
            if (grid[u.first+1][u.second]) {
                count++;
            } 
            if (grid[u.first][u.second-1]) {
                count++;
            } 
            if (grid[u.first][u.second+1]) {
                count++;
            }
            if (count == 3) {
                if (!grid[u.first-1][u.second]) {
                     grid[u.first-1][u.second] = true;
                } else if (!grid[u.first+1][u.second]) {
                    grid[u.first+1][u.second] = true;
                } else if (!grid[u.first][u.second-1]) {
                    grid[u.first][u.second-1] = true;
                } else if (!grid[u.first][u.second+1]) {
                    grid[u.first][u.second+1] = true;
                }
                times++;
            }
        }
        cout << times << '\n';
        */