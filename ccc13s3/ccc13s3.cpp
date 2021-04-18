#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n = 0, x, played;
set<pair<int,int> > st;
map<int,int> score;
void solve(map<int,int> score, set<pii> st){
    if (st.size() == 0){
        int m = 0;
        for(int i = 1; i <= 4; i++){
            if(i == x) continue;
            m = max(m, score[i]);
        }
        if (score[x] > m ) {
            n++;
        }
    } else{
        map<int,int> aw(score.begin(), score.end()), bw(score.begin(), score.end()), t(score.begin(), score.end()); 
        pii game = *st.begin(); st.erase(st.begin()); 
        int A = game.first, B = game.second; aw[A]+=3; bw[B]+=3;
        t[A]++; t[B]++;
        solve(aw, st); solve(bw, st); solve(t, st);
    }
}

int main(){
    for(int i = 1; i < 4; i++){
        for(int j = i+1; j <= 4; j++){
            st.insert({i,j});
        }
    }
    cin >> x >> played;
    for(int i = 0; i < played; i++){
        int A, B, C, D;
        cin >> A >> B >> C >> D; st.erase(st.find({A, B}));
        if(C > D) {
            score[A] += 3;
        }
        else if(C < D) {
            score[B] += 3;
        }
        else {
            score[A]++; score[B]++;
        }
    }
    solve(score, st);
    cout << n << '\n';
}