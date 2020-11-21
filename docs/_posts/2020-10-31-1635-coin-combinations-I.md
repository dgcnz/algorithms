---
layout: post
mathjax: true
title: 1635 Coin Combinations I
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
using ll = long long;
const int MOD = 1e9 + 7;
int solve(int x, const vi &c)
{
    vi dp(x + 1, 0);
    dp[0] = 1;
    for (int s = 1; s <= x; ++s)
    {
        for (auto ci : c)
        {
            if (s - ci < 0)
                break;
            dp[s] = (dp[s] + dp[s - ci]) % MOD;
        }
    }
    return dp[x];
}
int main(void)
{
    int n, x;
    cin >> n >> x;
    vi c(n);
    for (auto &ci : c)
        cin >> ci;
    sort(c.begin(), c.end());
    cout << solve(x, c) << endl;
    return 0;
}

{% endraw %}
```
