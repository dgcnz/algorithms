---
layout: post
mathjax: true
title: 1466A - Bovine Dilemma
problem_url: https://codeforces.com/contest/1466/problem/A
tags: math, brute_force
memory_complexity: O(n)
time_complexity: O(n^2)
---

In the formula $A = \frac{h_b b}{2}$, the only variable that changes is the
base length, $b$. List all pairs, of points on the x axis and count the
unique distances.


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
using ii = pair<int, int>;
using vi = vector<int>;
int solve(vi a)
{
    int n = (int)(a).size(), ans = 0;
    vector<bool> vis(100, 0);
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int b = abs(a[i] - a[j]);
            if (vis[b])
                continue;
            vis[b] = true;
            ans++;
        }
    }
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        for (auto &x : a)
            cin >> x;
        cout << solve(a) << endl;
    }
    return 0;
}

{% endraw %}
```
</details>

