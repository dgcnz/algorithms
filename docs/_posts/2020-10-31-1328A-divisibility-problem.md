---
layout: post
mathjax: true
title: 1328A Divisibility Problem
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