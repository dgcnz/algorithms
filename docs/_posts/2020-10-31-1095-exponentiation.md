---
layout: post
mathjax: true
title: 1095 Exponentiation
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

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int const MOD = 1e9 + 7;
ll modpow(ll a, ll b)
{
    a %= MOD;
    ll ans = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << modpow(a, b) << endl;
    }
    return 0;
}

{% endraw %}
```