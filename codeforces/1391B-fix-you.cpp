#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int  t, n, m, ans;
    char cij;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> cij;
                if (i == n - 1 and j == m - 1)
                    continue;
                if (j == m - 1 and cij != 'D')
                    ++ans;
                else if (i == n - 1 and cij != 'R')
                    ++ans;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
