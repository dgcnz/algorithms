---
layout: post
mathjax: true
title: 1630 Tasks Deadlines
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
using pll = pair<ll, ll>;
using vpll = vector<pll>;
int main(void)
{
    ll n;
    cin >> n;
    vpll tasks(n);
    for (auto &[a, d] : tasks)
        cin >> a >> d;
    sort(tasks.begin(), tasks.end());
    ll tim = 0, reward = 0;
    for (auto [a, d] : tasks)
    {
        tim += a;
        reward += d - tim;
    }
    cout << reward << endl;
    return 0;
}

{% endraw %}
```