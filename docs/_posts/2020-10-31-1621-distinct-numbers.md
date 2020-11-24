---
layout: post
mathjax: true
title: 1621 - Distinct Numbers
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
using vi = vector<int>;
int main(void)
{
    int n;
    cin >> n;
    vi x(n);
    for (auto &xi : x)
        cin >> xi;
    sort(x.begin(), x.end());
    cout << distance(x.begin(), unique(x.begin(), x.end())) << endl;
    return 0;
}

{% endraw %}
```
</details>

