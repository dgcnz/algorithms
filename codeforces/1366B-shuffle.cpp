#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, n, x, m, li, ri, i, maxl, maxr;
    cin >> t;
    while (t--)
    {
        maxl = maxr = 0;
        cin >> n >> x >> m;
        for (i = 0; i < m; ++i)
        {
            cin >> li >> ri;
            if (li <= x and x <= ri)
            {
                maxl = li;
                maxr = ri;
                break;
            }
        }
        i += 1;
        for (; i < m; ++i)
        {
            cin >> li >> ri;
            if (maxl <= ri)
                maxl = min(maxl, li);
            if (li <= maxr)
                maxr = max(maxr, ri);
        }
        cout << maxr - maxl + 1 << endl;
    }
    return 0;
}
