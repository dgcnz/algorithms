---
layout: post
mathjax: true
title: 276D - Little Girl Maximum Xor
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
using ll = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
inline bool different_bits(ll x, ll y, int i)
{
    return ((x >> i) ^ (y >> i)) & 1LL;
}
ll solve(ll l, ll r)
{
    ll ans = 0, bit_period = 1, diff = r - l;
    int i = 0;
    while (diff >= bit_period)
    {
        ans += bit_period;
        bit_period *= 2;
        i++;
    }
    while (r >= bit_period)
    {
        if (different_bits(l, r, i))
            ans += bit_period;
        bit_period *= 2;
        i++;
    }
    return ans;
}
int main(void)
{
    ll l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;
    return 0;
}

{% endraw %}
```
</details>

