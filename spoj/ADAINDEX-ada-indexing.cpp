#include <bits/stdc++.h>

using namespace std;

const int CMAX = 26;

struct node
{
    int   cnt;
    node *children[CMAX];
};

struct trie
{
    node *root;
    trie() { root = new node(); }
    void insert(string s)
    {
        node *cur = root;
        for (auto c : s)
        {
            int j = c - 'a';
            if (cur->children[j] == nullptr)
                cur->children[j] = new node();

            cur = cur->children[j];
            cur->cnt += 1;
        }
    }
    int query(string prefix)
    {
        node *cur = root;
        for (auto c : prefix)
        {
            int j = c - 'a';
            if (cur->children[j] == nullptr)
                return 0;
            cur = cur->children[j];
        }
        return cur->cnt;
    }
};

int main(void)
{
    int    n, q;
    string s;
    trie   t;

    cin >> n >> q;

    while (n--)
    {
        cin >> s;
        t.insert(s);
    }

    while (q--)
    {
        cin >> s;
        cout << t.query(s) << endl;
    }

    return 0;
}
