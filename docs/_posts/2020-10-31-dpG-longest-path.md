---
layout: post
mathjax: true
title: Dpg Longest Path
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
using vi = vector<int>;
const int NMAX = 1e5 + 11;
int n, m, mem[NMAX];
bool vis[NMAX];
vi g[NMAX];
int dp(int u)
{
    int ans = 0;
    if (vis[u])
        return mem[u];
    vis[u] = true;
    for (auto v : g[u])
        ans = max(dp(v) + 1, ans);
    return (mem[u] = ans);
}
int main(void)
{
    int u, v, ans;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    ans = 0;
    for (int i = 0; i <= n; ++i)
        ans = max(ans, dp(i));
    cout << ans << endl;
    return 0;
}

{% endraw %}
```