#include <bits/stdc++.h>

using namespace std;
using vi  = vector<int>;
using vvi = vector<vi>;

const int MOD = 1e9 + 7;

int main(void)
{
    int  n;
    char x;
    cin >> n;

    vvi free_cell(n, vi(n, 0));
    vvi dp(n + 1, vi(n + 1, 0));

    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < n; ++c)
        {
            cin >> x;
            free_cell[r][c] = (x != '*');
        }
    }

    dp[1][1] = (free_cell[0][0]);
    for (int r = 1; r <= n; ++r)
    {
        for (int c = 1; c <= n; ++c)
        {
            if ((r == 1 and c == 1) or not free_cell[r - 1][c - 1])
                continue;
            dp[r][c] = (dp[r - 1][c] + dp[r][c - 1]) % MOD;
        }
    }

    cout << dp[n][n] << endl;

    return 0;
}
