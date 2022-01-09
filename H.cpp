#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(a) a.begin(), a.end()
const int Mod = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];
        }
    }

    auto inside = [&] (int x, int y) {
        return x >= 0 and y >= 0 and x < H and y < W;
    };

    vector<vector<ll>> dp(H, vector<ll>(W, 0LL));
    dp[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '#') dp[i][j] = 0;
            else {
                if (inside(i - 1, j)) dp[i][j] = (dp[i][j] +  dp[i - 1][j]) % Mod;
                if (inside(i, j - 1)) dp[i][j] = (dp[i][j] +  dp[i][j - 1]) % Mod;
            }
        }
    }
    cout << dp[H - 1][W - 1] << "\n";
    return 0;
}