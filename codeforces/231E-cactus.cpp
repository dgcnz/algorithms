/** @file
 * @date                2021-01-26
 * @url                 https://codeforces.com/contest/231/problem/E
 * @tags           data_structures, lca, dp, trees, dfs, graph_transformation
 * @status              AC
 * @score               4
 * @difficulty          3
 * @editorial           no
 * @reading_time        1
 * @thinking_time       20
 * @coding_time         120
 * @time_complexity     O(n \log{n})
 * @memory_complexity   O(n \log{n})
 * @idea
 * Observations:
 * 1. Given two vertices $u$ and $v$, each cycle in their way multiplies the
 * number of paths by 2.
 *
 * So, the answer must be $2^{C(u, v)}$, where $C(u, v)$ denotes the number of
 * cycles in the way of $u, v$.
 *
 * Let's call $G_c$ the new graph that results from compressing each cycle in
 * the original graph into a node. We shall tag each node with color black if
 * they represent a cycle in the original graph and white otherwise.
 *
 * Note that $G_c$ is actually a tree, since all the cycles no longer remain.
 * The problem now becomes to count the number of black nodes in a path between
 * two nodes in a tree. This is a fairly standard problem, that can be solved
 * using dp and precomputing lca.
 * @endidea
 */

#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#else
#define dbg(...) ((void)0)
#endif
#include <atcoder/dsu>
#include <atcoder/modint>
#include <bits/stdc++.h>
#define all(c) begin(c), end(c)
#define isz(c) (int)(c).size()

using namespace std;
using ll   = long long;
using ii   = pair<int, int>;
using vi   = vector<int>;
using mint = atcoder::modint1000000007;

struct LCA
{
    using vi   = vector<int>;
    using Tree = vector<vi>;

    int        n;
    vector<vi> up;
    vi         tin, tout;

    LCA(const Tree &g) : n(g.size()), up(n, vi(log2(n) + 2)), tin(n), tout(n)
    {
        int timer = 0;
        preprocess(g, 0, 0, timer);
    }

    void preprocess(const Tree &g, int u, int p, int &timer)
    {
        tin[u]   = ++timer;
        up[u][0] = p;
        for (int i = 1, height = up[0].size(); i < height; ++i)
            up[u][i] = up[up[u][i - 1]][i - 1];

        for (int v : g[u])
            if (v != p)
                preprocess(g, v, u, timer);

        tout[u] = ++timer;
    }

    bool is_ancestor(int u, int v) const
    {
        return tin[u] <= tin[v] and tout[u] >= tout[v];
    }

    int ancestor(int u, int k) const
    {
        int i;
        while (k)
        {
            i = 8 * sizeof(k) - __builtin_clz(k) - 1;
            u = up[u][i];
            k ^= 1LL << i;
        }
        if (u == 0)
            return -1;
        return u;
    }

    int lca(int u, int v) const
    {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = up[0].size() - 1; i >= 0; --i)
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        return up[u][0];
    }
    int operator()(int u, int v) const { return lca(u, v); }
};

template <typename T>
using Graph = vector<vector<T>>;

tuple<Graph<int>, vector<int>, vector<bool>> compress_graph(Graph<int> g,
                                                            vector<ii> edges)
{
    using DSU = atcoder::dsu;
    int n     = g.size();
    DSU dsu(n);
    vi  parent(n), color(n, 0);

    function<void(int, int)> dfs = [&](int u, int p) {
        color[u]  = 1;
        parent[u] = p;
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            if (color[v] == 1)
                for (int i = u; i != parent[v]; i = parent[i])
                    dsu.merge(v, i);
            else if (color[v] == 0)
                dfs(v, u);
        }
        color[u] = 2;
    };
    dfs(0, 0);

    auto         components = dsu.groups();
    int          nc         = components.size();
    Graph<int>   gc(nc);
    vector<int>  id(n);
    vector<bool> in_cycle(nc, false);

    for (int i = 0; i < nc; ++i)
    {
        if (components[i].size() > 1)
            in_cycle[i] = true;
        for (auto u : components[i])
            id[u] = i;
    }

    // g.edges -> gc.edges
    transform(all(edges), begin(edges), [&id](ii uv) {
        return ii{id[uv.first], id[uv.second]};
    });
    edges.erase(
        remove_if(all(edges), [](ii uv) { return uv.first == uv.second; }),
        edges.end());
    sort(all(edges));
    edges.resize(distance(edges.begin(), unique(all(edges))));

    for (auto [u, v] : edges)
        gc[u].push_back(v), gc[v].push_back(u);

    return {gc, id, in_cycle};
}

vector<int> compute_dp(const Graph<int> g, vector<bool> black)
{
    vector<int> dp(all(black));

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : g[u])
        {
            if (v == p)
                continue;
            dp[v] += dp[u];
            dfs(v, u);
        }
    };
    dfs(0, 0);
    return dp;
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    Graph<int> g(n);
    vector<ii> edges(m);

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        edges[i] = {u, v};
    }

    auto [gc, id, black] = compress_graph(g, edges);
    auto dp              = compute_dp(gc, black);
    LCA  lca(gc);

    int k;
    cin >> k;
    while (k--)
    {
        int u, v;
        cin >> u >> v, u--, v--;
        u = id[u], v = id[v];

        int l = lca(u, v);

        int  cnt = dp[u] + dp[v] - 2 * dp[l] + black[l];
        auto ans = mint(2).pow(cnt).val();
        cout << ans << endl;
    }
    return 0;
}
