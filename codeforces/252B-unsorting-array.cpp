#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;

ii const EMPTY = {-1, -1};

ii solve(int n, vi &a)
{
    if (n <= 2)
        return EMPTY;

    if (all_of(a.begin(), a.end(), [&a](int x) { return x == a[0]; }))
        return EMPTY;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] != a[j])
            {
                swap(a[i], a[j]);
                if (not is_sorted(a.begin(), a.end()) and
                    not is_sorted(a.begin(), a.end(), greater<int>()))
                    return {i + 1, j + 1};

                swap(a[i], a[j]);
            }
        }
    }
    return EMPTY;
}

int main(void)
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n;
    vi  a;
    cin >> n;

    a.resize(n);
    for (auto &ai : a)
        cin >> ai;

    if (auto ans = solve(n, a); ans != EMPTY)
        cout << ans.first << " " << ans.second << endl;
    else
        cout << "-1" << endl;

    return 0;
}
