---
layout: post
mathjax: true
title: 1732 - Finding Borders
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
vi prefix_function(string s)
{
    int n = s.size();
    vi pi(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = pi[i - 1];
        while (j > 0 and s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}
void solve(string s)
{
    int i = s.size() - 1;
    vi pi = prefix_function(s), ans;
    while (pi[i])
    {
        ans.push_back(pi[i]);
        i = pi[i] - 1;
    }
    for_each(ans.rbegin(), ans.rend(), [](int x) { cout << x << " "; });
    cout << endl;
}
int main(void)
{
    string s;
    cin >> s;
    solve(s);
    return 0;
}

{% endraw %}
```
</details>

