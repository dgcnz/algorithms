#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int    n, a, d;
    string s;

    (void)n;
    a = d = 0;
    cin >> n;
    cin >> s;
    for (auto c : s)
    {
        if (c == 'A')
            ++a;
        else
            ++d;
    }

    if (a == d)
        cout << "Friendship" << endl;
    else if (a > d)
        cout << "Anton" << endl;
    else
        cout << "Danik" << endl;
    return 0;
}
