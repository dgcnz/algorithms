---
layout: post
title: 791A Bear Big Brother
url: None
tags: None
time_complexity: None
memory_complexity: None
---

None

```cpp
{% raw %}
using namespace std;
int main(void)
{
    int a, b, ans = 0;
    cin >> a >> b;
    while (a <= b)
    {
        a *= 3;
        b *= 2;
        ++ans;
    }
    cout << ans << endl;
    return 0;
}

{% endraw %}
```
