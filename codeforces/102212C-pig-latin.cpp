#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int    t;
    string s;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        getline(cin, s);
        stringstream ss(s);
        string       word;

        while (ss >> word)
        {
            word += word[0];
            word += "ay";
            if (isupper(word[0]))
                cout << (char)toupper(word[1]);
            else
                cout << (char)tolower(word[1]);
            for_each(word.begin() + 2,
                     word.end(),
                     [](char c) { cout << (char)tolower(c); }),
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
