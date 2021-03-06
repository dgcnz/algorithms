#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int NMAX = 1e5 + 11;

int  n, h[NMAX], mem[NMAX];
bool vis[NMAX];

inline int dh(int i, int j) { return (int)abs(h[i] - h[j]); }

int dp(int i)
{
    int &ans = mem[i];

    if (i == n - 1)
        return 0;
    if (vis[i])
        return ans;
    vis[i] = true;
    ans    = dp(i + 1) + dh(i, i + 1);
    if (i + 2 < n)
        ans = min(ans, dp(i + 2) + dh(i, i + 2));
    return ans;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    cout << dp(0) << endl;

    return 0;
}
