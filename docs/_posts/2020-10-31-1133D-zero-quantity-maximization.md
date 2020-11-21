---
layout: post
mathjax: true
title: 1133D Zero Quantity Maximization
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using lld = long double;
using mdi = map<lld, int>;
const int NMAX = 2 * 10e5 + 11;
int n;
lld a[NMAX], b[NMAX];
mdi counter;
bool comp(const pair<lld, int> &l, const pair<lld, int> &r)
{
    return l.second < r.second;
}
int main(void)
{
    int zeros = 0;
    lld frac;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0 and b[i] == 0)
            ++zeros;
        if (a[i] == 0)
            continue;
        else
        {
            frac = b[i] / a[i];
            ++counter[frac];
        }
    }
    cout << zeros + max_element(counter.begin(), counter.end(), comp)->second
         << endl;
}

{% endraw %}
```
