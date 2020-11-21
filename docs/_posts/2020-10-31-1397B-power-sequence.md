---
layout: post
title: 1397B Power Sequence
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using vi = vector<int>;
using predicate = function<bool(int)>;
int const NMAX = 1e5 + 11;
int n, a[NMAX];
ll cost(int c)
{
    ll ans = 0;
    ll x = 1;
    for (int i = 0; i < n; ++i)
    {
        ans += abs((ll)a[i] - x);
        x *= (ll)c;
    }
    return ans;
}
bool worthit(ll last, int c)
{
    ll ans = 0;
    ll x = 1;
    for (int i = 0; i < n; ++i)
    {
        ans += abs((ll)a[i] - x);
        if (ans > last)
            return false;
        x *= (ll)c;
    }
    return true;
}
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    ll last = cost(1);
    int c = 2;
    while (worthit(last, c))
    {
        last = cost(c);
        ++c;
    }
    cout << last << endl;
    return 0;
}

{% endraw %}
```
