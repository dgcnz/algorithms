#include <iostream>

using namespace std;

int a, b, c, d;
int x, y, z;

int main(void)
{
    int t;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> c >> d;
        x = b;
        y = c;
        z = c;

        cout << x << " " << y << " " << z << endl;
    }

    return 0;
}
