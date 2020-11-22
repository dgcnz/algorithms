---
layout: post
mathjax: true
title: 1392B Omkar Infinity Clock
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
using ll = long long;
using vi = vector<int>;
int const NMAX = 2e5 + 11;
int n, a[NMAX];
ll k;
bool cyclic(void)
{
    bool zero = false;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < 0)
            return false;
        if (a[i] == 0)
            zero = true;
    }
    if (zero)
        return true;
    else
        return false;
}
void op(void)
{
    int d = *max_element(a, a + n);
    for (int i = 0; i < n; ++i)
        a[i] = d - a[i];
}
int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        ll ki = 0;
        while (ki != k and not cyclic())
        {
            op();
            ++ki;
        }
        if ((k - ki) % 2 == 1)
            op();
        for (int i = 0; i < n; ++i)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}

{% endraw %}
```