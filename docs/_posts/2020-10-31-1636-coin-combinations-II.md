---
layout: post
title: 1636 Coin Combinations Ii
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
const int MOD = 1e9 + 7;
int solve(int n, int x, const vi &c)
{
    vvi dp(n + 1, vi(x + 1, 0));
    for (int i = 1; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int s = 1; s <= x; ++s)
        {
            int &ans = dp[i][s];
            ans = dp[i - 1][s];
            if (s - c[i - 1] >= 0)
                ans = (ans + dp[i][s - c[i - 1]]) % MOD;
        }
    }
    return dp[n][x];
}
int main(void)
{
    int n, x;
    cin >> n >> x;
    vi c(n);
    for (auto &ci : c)
        cin >> ci;
    sort(c.begin(), c.end());
    cout << solve(n, x, c) << endl;
    return 0;
}

```
