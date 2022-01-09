#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n, W;
    cin >> n >> W;
    vector<ll> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(W + 1, 0LL));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < w[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
        }
    }
    cout << dp[n][W] << "\n";
    return 0;
}