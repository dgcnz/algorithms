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

// O(n^3)
int solve1(vi a)
{
    int n = isz(a), ans = 0;

    for (int l = 0; l < n - 1; ++l)
        for (int r = l + 1; r < n; ++r)
            if (accumulate(a.begin() + l, a.begin() + r + 1, 0) == 0)
                ans = max(ans, (r - l + 1));

    return ans;
}

vi prefix_sum(vi a)
{
    int n = isz(a);
    vi  pa(n);
    for (int i = 0; i < n; ++i)
        pa[i] = a[i] + (i == 0 ? 0 : pa[i - 1]);
    return pa;
}

// O(n^2)
int solve2(vi a)
{
    int  n = isz(a), ans = 0;
    vi   pa  = prefix_sum(a);
    auto sum = [&pa](int l, int r) { return pa[r] - (l == 0 ? 0 : pa[l - 1]); };

    for (int l = 0; l < n - 1; ++l)
        for (int r = l + 1; r < n; ++r)
            if (sum(l, r) == 0) // O(1)
                ans = max(ans, (r - l + 1));
    return ans;
}

// O(nlogn)
int solve3(vi a)
{
    int           n = isz(a), ans = 0;
    map<int, int> sum_ix;
    sum_ix[0] = -1;

    int ps = 0;
    for (int i = 0; i < n; ++i)
    {
        ps += a[i];
        if (sum_ix.find(ps) == sum_ix.end()) // O(logn)
            sum_ix[ps] = i;
        else
            ans = max(ans, i - sum_ix[ps]); // O(logn)
    }
    return ans;
}

int main(void)
{
    int    n;
    string s;

    cin >> n >> s;

    vi a(n);
    transform(all(s), a.begin(), [](char c) { return c == '0' ? -1 : +1; });
    cout << solve3(a) << endl;

    return 0;
}
