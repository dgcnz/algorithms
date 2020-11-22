---
layout: post
mathjax: true
title: 1637 Removing Digits
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
    int n, num, x, ans;
    cin >> n;
    ans = 0;
    while (n != 0)
    {
        x = n;
        num = 0;
        while (x != 0)
        {
            num = max(num, x % 10);
            x /= 10;
        }
        n -= num;
        ans += 1;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```