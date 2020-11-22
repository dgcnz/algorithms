---
layout: post
mathjax: true
title: Abc179_B Go To Jail
problem_url: None
tags: None
memory_complexity: None
time_complexity: None
---

None


{% if page.time_complexity != "None" %}
- Time complexity: ${{ page.time_complexity }}$
{% endif %}
{% if page.memory_complexity != "None" %}
- Memory complexity: ${{ page.memory_complexity }}$
{% endif %}
{% if page.tags != "None" %}
- Tags: {{ page.tags }}
{% endif %}

{% if page.problem_url != "None" %}
- [URL]({{ page.problem_url }})
{% endif %}

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
    vector<ii> d(n);
    for (auto &[f, s] : d)
        cin >> f >> s;
    int cnt = 0;
    for (auto [f, s] : d)
    {
        if (f == s)
        {
            cnt++;
        }
        else
        {
            if (cnt >= 3)
            {
                cout << "Yes" << endl;
                return 0;
            }
            cnt = 0;
        }
    }
    if (cnt >= 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

{% endraw %}
```