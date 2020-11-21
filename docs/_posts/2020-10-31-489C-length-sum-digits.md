---
layout: post
mathjax: true
title: 489C Length Sum Digits
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int clamp(int x) { return max(0, min(x, 9)); }
int main(void)
{
    int m, s;
    cin >> m >> s;
    int minv[m];
    int maxv[m];
    int temp_sum = s;
    int v;
    for (int i = 0; i < m; ++i)
    {
        v = clamp(temp_sum);
        temp_sum -= v;
        maxv[i] = v;
    }
    temp_sum = s - 1;
    for (int i = m - 1; i > 0; --i)
    {
        v = clamp(temp_sum);
        temp_sum -= v;
        minv[i] = v;
    }
    minv[0] = temp_sum + 1;
    if ((minv[0] == 0 and not(s == 0 and m == 1)) or minv[0] > 9)
        cout << "-1 -1\n";
    else
    {
        for (int i = 0; i < m; ++i)
            cout << minv[i];
        cout << " ";
        for (int i = 0; i < m; ++i)
            cout << maxv[i];
        cout << endl;
    }
    return 0;
}

{% endraw %}
```
