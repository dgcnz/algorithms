---
layout: post
mathjax: true
title: agc002_b - Box And Ball
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
    int n, m, xi, yi;
    vi red, cnt;
    cin >> n >> m;
    cnt.resize(n, 1), red.resize(n, false);
    red[0] = true;
    for (int i = 0; i < m; ++i)
    {
        cin >> xi >> yi, xi--, yi--;
        red[yi] |= red[xi];
        cnt[xi] -= 1;
        cnt[yi] += 1;
        if (cnt[xi] == 0)
            red[xi] = false;
    }
    cout << accumulate(red.begin(), red.end(), 0) << endl;
    return 0;
}

{% endraw %}
```
</details>

