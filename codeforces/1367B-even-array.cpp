#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t, n, x;
    int diff[2];
    cin >> t;

    while (t--)
    {
        diff[0] = diff[1] = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> x;
            if (x % 2 != i % 2)
                diff[i % 2] += 1;
        }

        if (diff[0] != diff[1])
            cout << -1 << endl;
        else
            cout << diff[0] << endl;
    }
    return 0;
}
