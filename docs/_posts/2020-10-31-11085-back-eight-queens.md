---
layout: post
mathjax: true
title: 11085 Back Eight Queens
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
using ss = stringstream;
int initial[8];
int board[8];
bool valid(int nrow, int ncol)
{
    for (int col = 0; col < ncol; ++col)
    {
        if (board[col] == nrow)
            return false;
        if ((ncol - col) == (int)abs(nrow - board[col]))
            return false;
    }
    return true;
}
int current_score(void)
{
    int score = 0;
    for (int col = 0; col < 8; ++col)
        score += (board[col] - initial[col]) != 0;
    return score;
}
int backtrack(int col)
{
    int ans = INT_MAX;
    for (int row = 0; row < 8; ++row)
    {
        if (valid(row, col))
        {
            int last = board[col];
            board[col] = row;
            if (col < 7)
                ans = min(ans, backtrack(col + 1));
            else
                ans = min(ans, current_score());
            board[col] = last;
        }
    }
    return ans;
}
int main(void)
{
    string line;
    int t = 0;
    while (getline(cin, line) and line != "")
    {
        ++t;
        int row;
        ss rows(line);
        for (int i = 0; i < 8; ++i)
        {
            rows >> row;
            board[i] = initial[i] = row - 1;
        }
        cout << "Case " << t << ": " << backtrack(0) << endl;
        line = "";
    }
    return 0;
}

{% endraw %}
```
</details>

