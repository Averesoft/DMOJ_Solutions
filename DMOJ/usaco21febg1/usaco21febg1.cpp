#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6 + 2;
int N, psa[MM], M, tmp[MM]; ll ans;
int main(){
    cin >> N;
    for(int i=1, x; i<=N; i++){
        cin >> x; psa[x]++; M = max(M, x);
    }
    for(int i=1; i<=M; i++){
        psa[i] += psa[i-1];
    }
    for(int i=1; i<=M; i++){
        int odd = 0;
        for(int j=i; j<=M; j+=i){
            tmp[j] = psa[min(j+i-1, M)] - psa[j-1];
            if(tmp[j] & 1) odd++;
        }
        if(odd == 0 || odd > 2) continue;
        if(odd == 1 && (tmp[i]&1)) ans += tmp[i];
        else if(odd == 2){
            for(int j=i; j<=M; j+=i)
                if((tmp[j-i] & 1) && (tmp[j] & 1)) ans += tmp[j];
        }
    }
    cout << ans << endl;
}