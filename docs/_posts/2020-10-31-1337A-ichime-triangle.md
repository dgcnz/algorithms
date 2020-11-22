---
layout: post
mathjax: true
title: 1337A Ichime Triangle
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
int a, b, c, d;
int x, y, z;
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c >> d;
        x = b;
        y = c;
        z = c;
        cout << x << " " << y << " " << z << endl;
    }
    return 0;
}

{% endraw %}
```