---
layout: post
mathjax: true
title: 1401A Distance Axis
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
int solve(int n, int k)
{
    if (n < k)
        return k - n;
    else
        return n % 2 != k % 2;
}
int main(void)
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

