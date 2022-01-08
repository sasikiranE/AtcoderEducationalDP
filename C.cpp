#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<vector<ll>> v(n, vector<ll>(3));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    vector<vector<ll>> dp(n, vector<ll>(3));
    for (int i = 0; i < 3; i++) {
        dp[0][i] = v[0][i];
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = v[i][0] + max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = v[i][1] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = v[i][2] + max(dp[i - 1][0], dp[i - 1][1]);
    }
    ll ans = -1;
    for (int i = 0; i < 3; i++) {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << "\n";
    return 0;
}