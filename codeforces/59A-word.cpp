#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int    n, lowcnt = 0;
    string s;
    cin >> s;
    n = s.size();

    for (char &c : s)
    {
        if (islower(c))
            lowcnt += 1;
        c = (char)tolower(c);
    }

    if (lowcnt >= n - lowcnt)
        cout << s << endl;
    else
    {
        for (auto c : s)
            cout << (char)toupper(c);
        cout << endl;
    }

    return 0;
}
