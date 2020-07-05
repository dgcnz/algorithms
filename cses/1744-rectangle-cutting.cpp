#include <bits/stdc++.h>

using namespace std;
using vi  = vector<int>;
using vvi = vector<vi>;

const int INF = 1e9;

int main(void)
{
    int a, b;
    cin >> a >> b;

    if (a < b)
        swap(a, b);
    vvi dp(a + 1, vi(b + 1, 0));

    for (int r = 1; r <= a; ++r)
    {
        for (int c = 1; c <= b; ++c)
        {
            if (r == c)
                continue;
            int &ans = dp[r][c] = INF;

            for (int k = 1; k < r; ++k) // cutting vertically
                ans = min(ans, dp[k][c] + dp[r - k][c] + 1);
            for (int k = 1; k < c; ++k) // cutting horizontally
                ans = min(ans, dp[r][k] + dp[r][c - k] + 1);
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}
