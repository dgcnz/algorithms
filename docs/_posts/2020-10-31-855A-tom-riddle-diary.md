---
layout: post
title: 855A Tom Riddle Diary
url: None
tags: None

time_complexity: None
memory_complexity: None
---

None

```cpp
using namespace std;
map<string, bool> exists;
int main(void)
{
    int n;
    string s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (exists[s])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        exists[s] = true;
    }
    return 0;
}

```
