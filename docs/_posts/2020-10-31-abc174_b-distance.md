---
layout: post
mathjax: true
title: Abc174_B Distance
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
using ll = long long;
int main(void)
{
    ll n, x, y, ans = 0;
    double d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        double cur_dist = sqrt(x * x + y * y);
        if (cur_dist <= d)
            ans++;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
</details>

