#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

int main(void)
{
    int    ans = 0;
    vi     cost(4, 0);
    string s;

    for (auto &x : cost)
        cin >> x;

    cin >> s;
    for (auto c : s)
        ans += cost[c - '0' - 1];
    cout << ans << endl;

    return 0;
}
