#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

bool solve(int n, vi a)
{
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i)
    {
        if (a[i] - a[i - 1] > 1)
            return false;
    }
    return true;
}

int main(void)
{
    int t, n;
    vi  a;

    cin >> t;
    while (t--)
    {
        cin >> n;
        a.assign(n, 0);

        for (auto &ai : a)
            cin >> ai;

        cout << (solve(n, a) ? "YES" : "NO") << endl;
    }
    return 0;
}
