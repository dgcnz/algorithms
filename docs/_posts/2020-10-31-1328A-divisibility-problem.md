---
layout: post
mathjax: true
title: 1328A Divisibility Problem
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
int main(void)
{
    int t, a, b, mod;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        mod = a % b;
        cout << (b - mod) % b << endl;
    }
}

{% endraw %}
```
</details>

