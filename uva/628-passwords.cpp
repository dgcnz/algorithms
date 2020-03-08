#include <iostream>
#include <string>
#include <vector>

using namespace std;
using vs = vector<string>;

int    n, m;
vs     dictionary;
string cpattern;

void match(int pos, string ans)
{
    if (pos == cpattern.size())
    {
        cout << ans << endl;
        return;
    }
    if (cpattern[pos] == '0')
    {
        for (int i = 0; i < 10; ++i)
            match(pos + 1, ans + to_string(i));
    }
    else
    {
        for (int i = 0; i < n; ++i)
            match(pos + 1, ans + dictionary[i]);
    }
}

int main(void)
{
    string word;
    string pattern;

    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> word;
            dictionary.push_back(word);
        }
        cin >> m;

        cout << "--" << endl;
        for (int j = 0; j < m; ++j)
        {
            cin >> pattern;
            cpattern = pattern;
            match(0, "");
        }
        dictionary = vs();
    }

    return 0;
}
