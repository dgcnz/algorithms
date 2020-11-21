---
layout: post
title: Dpn Slimes
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using ll = long long;
const int NMAX = 4e2 + 11;
int n, a[NMAX];
ll acc[NMAX];
ll dp[NMAX][NMAX];
inline ll sum(int l, int r) { return acc[r] - (l > 0 ? acc[l - 1] : 0); }
ll solve(void)
{
    for (int l = n - 1; l >= 0; --l)
    {
        for (int r = l; r < n; ++r)
        {
            if (l == r)
                dp[l][r] = 0;
            else
            {
                dp[l][r] = LLONG_MAX;
                for (int i = l; i <= r - 1; ++i)
                    dp[l][r] =
                        min(dp[l][r], dp[l][i] + dp[i + 1][r] + sum(l, r));
            }
        }
    }
    return dp[0][n - 1];
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        acc[i] = a[i];
        if (i != 0)
            acc[i] += acc[i - 1];
    }
    cout << solve() << endl;
    return 0;
}

```
