---
layout: post
mathjax: true
title: 1666 Building Roads
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using vi = vector<int>;
const int NMAX = 1e5 + 11;
int n, m, parent[NMAX], sz[NMAX];
void make_set(int u)
{
    parent[u] = u;
    sz[u] = 1;
}
int find_set(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find_set(parent[u]);
}
void union_set(int u, int v)
{
    u = find_set(u);
    v = find_set(v);
    if (u != v)
    {
        if (sz[u] < sz[v])
            swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
    }
}
int main(void)
{
    int u, v;
    cin >> n >> m;
    for (int u = 1; u <= n; ++u)
        make_set(u);
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v;
        union_set(u, v);
    }
    vi heads;
    for (int u = 1; u <= n; ++u)
        if (find_set(u) == u)
            heads.push_back(u);
    int reps = heads.size();
    cout << reps - 1 << endl;
    if (reps == 1)
        return 0;
    for (int i = 1; i < reps; ++i)
        cout << heads[i - 1] << " " << heads[i] << endl;
    return 0;
}

{% endraw %}
```
