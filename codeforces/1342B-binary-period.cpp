#include <bits/stdc++.h>

using namespace std;

int    n;
string s;

bool is_k1(void)
{
    char start = s[0];
    for (int i = 1; i < n; ++i)
    {
        if (s[i] != start)
            return false;
    }
    return true;
}

void solve(void)
{
    // need to be period or 1 or 2
    if (is_k1())
    {
        for (int i = 0; i < n; ++i)
            cout << s[i];
        return;
    }

    char last = s[0];
    cout << last;

    for (int i = 1; i < n; ++i)
    {
        if (s[i] != last)
        {
            cout << s[i];
        }
        else
        {
            cout << (last == '0' ? '1' : '0');
            cout << s[i];
            last = s[i];
        }

        last = s[i];
    }
}

int main(void)
{
    int t;

    cin >> t;

    while (t--)
    {
        cin >> s;
        n = s.size();
        solve();
        cout << endl;
    }
    return 0;
}
