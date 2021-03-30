#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lc (rt<<1)
#define rc (rt<<1|1)
#define pb push_back
#define cl(a, b) memset(a, b, sizeof(a))
#define mp(a, b) make_pair((a), (b))
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<pi, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vii;
typedef vector<pl> vll;
typedef vector<pii> viii;
const int inf = 0x3F3F3F3F;
const ll infl = 0x3F3F3F3F3F3F3F3FLL;
const int mod = 1e9 + 7, MM = 2.5e4+4;
int T, N, dp[MM], ans, a[102];
int main(){
    //freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(cin >> T; T--; ){
        cin >> N; ans = N; cl(dp, 0); dp[0]=1;
        for(int i=1; i<=N; i++) cin >> a[i];
        sort(a+1, a+N+1);
        for(int i=1; i<=N; i++){
            if(dp[a[i]]) { ans--; continue; }
            for(int j=a[i]; j<=a[N]; j++)
                dp[j] = dp[j] | dp[j-a[i]];
        }
        cout << ans << "\n";
    }

}