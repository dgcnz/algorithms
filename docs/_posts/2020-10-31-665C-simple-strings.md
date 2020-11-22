---
layout: post
mathjax: true
title: 665C Simple Strings
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
string s;
char anything_but(char c, char d)
{
    for (char x = 'a'; x <= 'z'; ++x)
        if (x != c and x != d)
            return x;
    return 0;
}
string solve(void)
{
    int n = s.size();
    char last = s[0];
    for (int i = 1; i < n - 1; ++i)
    {
        if (s[i] == last)
            s[i] = anything_but(last, s[i + 1]);
        last = s[i];
    }
    if (n != 1 and s[n - 1] == last)
        s[n - 1] = anything_but(last, last);
    return s;
}
int main(void)
{
    cin >> s;
    cout << solve() << endl;
    return 0;
}

{% endraw %}
```