#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

const int NMAX = 1e5 + 11;

int  n, k, h[NMAX], mem[NMAX];
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
    ans    = INT_MAX;
    for (int j = i + 1; j <= i + k; ++j)
        if (j < n)
            ans = min(ans, dp(j) + dh(i, j));

    return ans;
}

int main(void)
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    cout << dp(0) << endl;
    return 0;
}
