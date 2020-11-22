---
layout: post
mathjax: true
title: Dpm Candies
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

```cpp
{% raw %}
using namespace std;
const int NMAX = 1e2 + 11;
const int KMAX = 1e5 + 11;
const int MOD = 1e9 + 7;
int n, k, a[NMAX], acc[KMAX], dp[NMAX][KMAX];
int solve(void)
{
    dp[0][0] = 1;
    for (int s = 1; s <= k; ++s)
        dp[0][s] = 0;
    for (int i = 1; i <= n; ++i)
    {
        acc[0] = dp[i - 1][0];
        for (int s = 1; s <= k; ++s)
            acc[s] = (acc[s - 1] + dp[i - 1][s]) % MOD;
        for (int s = 0; s <= k; ++s)
            dp[i][s] =
                (acc[s] - (s - a[i] - 1 >= 0 ? acc[s - a[i] - 1] : 0) + MOD) %
                MOD;
    }
    return dp[n][k];
}
int main(void)
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```