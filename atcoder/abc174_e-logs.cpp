#include <bits/stdc++.h>

using namespace std;
using ll        = long long;
using vi        = vector<int>;
using predicate = function<bool(int)>;

const int AMAX = 1e9 + 11;

int n, k;
vi  a;

bool is_possible(int l)
{
    ll c = 0;
    for (int x : a)
        c += (x - 1) / l;
    return c <= k;
}

ll bsearch(ll l, ll r, predicate p)
{
    while (l < r)
    {
        ll m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(void)
{
    cin >> n >> k;
    a.resize(n);
    for (auto &x : a)
        cin >> x;

    cout << bsearch(1, AMAX, is_possible) << endl;

    return 0;
}
