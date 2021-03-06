#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using vi = vector<int>;

int solve(vi a, int k)
{
    int n = isz(a), ans = 1e9;
    vi  cnt(2 * k + 2, 0), pre(2 * k + 2, 0);

    for (int i = 0; i < n / 2; ++i)
    {
        int l = a[i], r = a[n - i - 1];
        int ll = l + 1, lr = l + k;
        int rl = r + 1, rr = r + k;

        ++cnt[l + r];
        ++pre[min(ll, rl)];
        --pre[max(lr, rr) + 1];
    }

    for (int i = 1; i <= 2 * k + 1; ++i)
        pre[i] += pre[i - 1];

    // cnt[sum] : how many need 0 to get to sum
    // pre[sum] : how many need <= 1 to get sum

    // ans[x]  : how many need 1 and 2 exactly
    for (int sum = 2; sum <= 2 * k; ++sum)
        ans = min(ans, (pre[sum] - cnt[sum]) + (n / 2 - pre[sum]) * 2);
    return ans;
}
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;

        cin >> n >> k;

        vi a(n);
        for (auto &ai : a)
            cin >> ai;
        cout << solve(a, k) << endl;
    }
    return 0;
}
