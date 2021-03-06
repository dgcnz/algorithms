#ifdef DBG_MACRO_NO_WARNING
#include <dbg.h>
#endif
#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()

using namespace std;

int    n;
string s;

int cost(int l, int r, char c)
{
    return count_if(
        s.begin() + l, s.begin() + r + 1, [c](char d) { return d != c; });
}

int solve(int l, int r, char c)
{
    if (r - l == 0)
        return c != s[l];
    else
    {
        int m = l + (r - l) / 2;
        return min(cost(l, m, c) + solve(m + 1, r, c + 1),
                   solve(l, m, c + 1) + cost(m + 1, r, c));
    }
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        cout << solve(0, n - 1, 'a') << endl;
    }
    return 0;
}
