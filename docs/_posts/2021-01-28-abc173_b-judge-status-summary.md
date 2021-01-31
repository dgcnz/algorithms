---
layout: post
mathjax: true
title: abc173_b - Judge Status Summary
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---



{% if page.time_complexity != "None" %}
Time complexity: ${{ page.time_complexity }}$
{% endif %}

{% if page.memory_complexity != "None" %}
Memory complexity: ${{ page.memory_complexity }}$
{% endif %}

<details>
<summary>
<p style="display:inline">Click to show code.</p>
</summary>
```cpp
{% raw %}
using namespace std;
int main(void)
{
    int n;
    string stat;
    map<string, int> counter;
    cin >> n;
    while (n--)
    {
        cin >> stat;
        counter[stat]++;
    }
    cout << "AC x " << counter["AC"] << endl;
    cout << "WA x " << counter["WA"] << endl;
    cout << "TLE x " << counter["TLE"] << endl;
    cout << "RE x " << counter["RE"] << endl;
    return 0;
}

{% endraw %}
```
</details>

