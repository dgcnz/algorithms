#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int n, ans = 0;
    cin >> n;
    vi h(n), a(n);

    for (int i = 0; i < n; ++i)
        cin >> h[i] >> a[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                continue;
            ans += (h[i] == a[j]);
        }
    }

    cout << ans << endl;

    return 0;
}
