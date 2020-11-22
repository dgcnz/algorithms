---
layout: post
mathjax: true
title: 1649 Range Minimum Queries Ii
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
using ii = pair<int, int>;
using vi = vector<int>;
ll INF = 1e17;
struct segment_tree
{
    int n;
    vector<ll> t;
    segment_tree(vi const &a)
    {
        n = (int)a.size();
        t.resize(4 * (int)a.size());
        build(a, 1, 0, n - 1);
    }
    ll merge(ll a, ll b) { return min(a, b); }
    void build(vi const &a, int v, int tl, int tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }
    void update(int v, int tl, int tr, int ix, int new_val)
    {
        if (tl == tr and tl == ix)
            t[v] = new_val;
        else if (tl <= ix and ix <= tr)
        {
            int tm = (tl + tr) / 2;
            update(2 * v, tl, tm, ix, new_val);
            update(2 * v + 1, tm + 1, tr, ix, new_val);
            t[v] = merge(t[2 * v], t[2 * v + 1]);
        }
    }
    auto query(int v, int tl, int tr, int ql, int qr)
    {
        if (tl == ql and tr == qr)
            return t[v];
        else if (ql > qr)
            return INF;
        else
        {
            int tm = (tl + tr) / 2;
            return merge(query(2 * v, tl, tm, ql, min(tm, qr)),
                         query(2 * v + 1, tm + 1, tr, max(tm + 1, ql), qr));
        }
    }
};
int main(void)
{
    int n, q;
    cin >> n >> q;
    vi a(n);
    for (auto &ai : a)
        cin >> ai;
    segment_tree st(a);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int ix, new_val;
            cin >> ix >> new_val, ix--;
            st.update(1, 0, n - 1, ix, new_val);
        }
        else
        {
            int ql, qr;
            cin >> ql >> qr, ql--, qr--;
            cout << st.query(1, 0, n - 1, ql, qr) << endl;
        }
    }
    return 0;
}

{% endraw %}
```