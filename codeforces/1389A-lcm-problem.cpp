#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

ii solve(int l, int r)
{
    if (2 * l <= r)
        return {l, 2 * l};
    else
        return {-1, -1};
}

int main(void)
{
    int t, l, r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        auto [a, b] = solve(l, r);
        cout << a << " " << b << endl;
    }
    return 0;
}
