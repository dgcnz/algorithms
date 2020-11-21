---
layout: post
mathjax: true
title: 1407C Chocolate Bunny
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
int main(void)
{
    int n;
    cin >> n;
    queue<int> qix;
    vi ans(n);
    for (int i = 1; i <= n; ++i)
        qix.push(i);
    while ((int)qix.size() > 1)
    {
        int ans0, ans1;
        int ix0 = qix.front();
        qix.pop();
        int ix1 = qix.front();
        qix.pop();
        cout << "? " << ix0 << " " << ix1 << endl;
        cout.flush();
        cin >> ans0;
        cout << "? " << ix1 << " " << ix0 << endl;
        cout.flush();
        cin >> ans1;
        if (ans0 > ans1)
        {
            ans[ix0 - 1] = ans0;
            qix.push(ix1);
        }
        else
        {
            ans[ix1 - 1] = ans1;
            qix.push(ix0);
        }
    }
    ans[qix.front() - 1] = n;
    cout << "! ";
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}

{% endraw %}
```
