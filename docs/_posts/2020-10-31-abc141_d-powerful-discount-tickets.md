---
layout: post
mathjax: true
title: abc141_d - Powerful Discount Tickets
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
    int n, m, ai;
    multiset<int, greater<int>> s;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> ai, s.insert(ai);
    while (m--)
    {
        int biggest = *s.begin();
        if (biggest == 0)
            break;
        s.erase(s.begin());
        s.insert(biggest / 2);
    }
    cout << accumulate(s.begin(), s.end(), (ll)0) << endl;
    return 0;
}

{% endraw %}
```
</details>

