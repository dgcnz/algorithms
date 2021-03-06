#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define isz(c) (int)c.size()

using namespace std;
using ll = long long;
using vi = vector<int>;

int main(void)
{
    int n;
    while (cin >> n and n != 0)
    {
        int pi;
        while (cin >> pi and pi != 0)
        {
            try
            {
                vector<bool> visited(n + 1, false);
                stack<int>   s;
                for (int i = 0; i < n; ++i)
                {
                    if (i > 0)
                        cin >> pi;
                    if (not visited[pi])
                    {
                        for (int x = 1; x <= pi; ++x)
                        {
                            if (not visited[x])
                            {
                                s.push(x);
                                visited[x] = true;
                            }
                        }
                    }
                    else
                    {
                        if (isz(s) == 0 or s.top() != pi)
                        {
                            for (; i < n - 1; ++i)
                                cin >> pi;
                            // cin.ignore();
                            throw -1;
                        }
                    }
                    s.pop();
                }
                cout << "Yes" << endl;
            }
            catch (int e)
            {
                cout << "No" << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
