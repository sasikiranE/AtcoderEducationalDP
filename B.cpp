#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;
const long long inf = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &e : v) cin >> e;
    vector<ll> dp(n, inf);
    dp[0] = 0LL;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i < j) continue;
            dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i - j]));
        }
    }
    cout << dp[n - 1] << "\n";
    return 0;
}