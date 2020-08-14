#include <bits/stdc++.h>

using namespace std;
using predicate = function<bool(int)>;

int const NMAX = 2e5 + 11;

int n, m, a[NMAX];

bool ok(int n_convinced)
{
    int reviews = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > reviews and n_convinced > 0)
        {
            n_convinced--;
            reviews++;
        }
        else if (a[i] <= reviews)
            reviews++;
    }
    return reviews >= m;
}

int bs(int l, int r, predicate p)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (p(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << bs(0, n, ok) << endl;

    return 0;
}
