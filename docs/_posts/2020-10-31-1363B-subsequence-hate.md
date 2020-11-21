---
layout: post
title: 1363B Subsequence Hate
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
using vi = vector<int>;
int solve(string s)
{
    int n = s.size();
    vi acc(n, 0);
    for (int i = 0; i < n; ++i)
    {
        acc[i] = (s[i] == '1');
        if (i != 0)
            acc[i] += acc[i - 1];
    }
    auto ones = [=](int l, int r) -> int {
        int ans = acc[r];
        if (l != 0)
            ans -= acc[l - 1];
        return ans;
    };
    auto zeros = [=](int l, int r) -> int {
        int ans = (r - l + 1) - ones(l, r);
        return ans;
    };
    int ans = INT_MAX;
    ans = min(ans, acc[n - 1]);
    ans = min(ans, n - acc[n - 1]);
    for (int i = 0; i < n - 1; ++i)
    {
        ans = min(ans, ones(0, i) + zeros(i + 1, n - 1));
        ans = min(ans, zeros(0, i) + ones(i + 1, n - 1));
    }
    return ans;
}
int main(void)
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}

```
