#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void read_n(InputIterator it, int n)
{
    copy_n(istream_iterator<T>(cin), n, it);
}

template <typename InputIterator,
          typename T = typename iterator_traits<InputIterator>::value_type>
void write(InputIterator first, InputIterator last, const char *delim = "\n")
{
    copy(first, last, ostream_iterator<T>(cout, delim));
}

int const NMAX = 2e5 + 11;

int n, dp1[NMAX], dp2[NMAX];
vi  g[NMAX];

void solve(int u, int p = 0)
{
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        solve(v, u);
        dp2[u] += max(dp1[v], dp2[v]);
    }
    for (auto v : g[u])
    {
        if (v == p)
            continue;
        auto v_choice = max(dp1[v], dp2[v]);
        dp1[u]        = max(dp1[u], 1 + dp2[u] - v_choice + dp2[v]);
    }
}

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int root = 1;
    solve(root);

    cout << max(dp1[root], dp2[root]) << endl;

    return 0;
}
