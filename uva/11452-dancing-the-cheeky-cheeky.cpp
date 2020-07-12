// In the name of God
#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

vi prefix_function(string s)
{
    int n = (int)s.length();
    vi  pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(NULL);

    int    t, n, ix, maxp;
    string s;

    cin >> t;
    while (t--)
    {
        cin >> s;
        n       = s.size();
        auto pi = prefix_function(s);

        ix = maxp = 0;
        for (int i = 0; i < n; ++i)
        {
            if (pi[i] > maxp and 2 * pi[i] == i + 1)
            {
                ix   = i;
                maxp = pi[i];
            }
        }
        string ans(ix + 1, ' ');
        for (int i = 0; i <= ix; ++i)
            ans[i] = s[i];

        for (int j = (n - ix - 1); j < n - ix + 8 - 1; ++j)
            cout << s[j % (ix + 1)];
        cout << "..." << endl;
    }

    return 0;
}
