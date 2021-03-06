#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;

int main(void)
{
    int n;
    ll  sum, ans;
    cin >> n;
    vi t(n);

    for (auto &ti : t)
        cin >> ti;

    sort(t.begin(), t.end(), greater<int>());

    sum = accumulate(t.begin() + 1, t.end(), (ll)0);
    ans = sum + max((ll)0, t[0] - sum) + t[0];

    cout << ans << endl;

    return 0;
}
