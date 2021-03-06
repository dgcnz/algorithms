#include <bits/stdc++.h>

// source:
// https://github.com/iamprayush/cses-problemset-solutions/blob/master/solutions/Sorting%20and%20Searching/room-allocation.cpp
// i did this with sets but this is a way more elegant solution

using namespace std;
using iii  = tuple<int, int, int>;
using vi   = vector<int>;
using viii = vector<iii>;

int main(void)
{
    int  n, x, y;
    viii events;
    vi   ans, rooms;

    cin >> n;
    ans = vi(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        events.push_back({x, -1, i}); // comes in
        events.push_back({y, 1, i});  // goes out
    }
    sort(events.begin(), events.end());

    int occupied = 0, max_rooms = 0;

    for (auto [t, sign, i] : events)
    {
        if (sign == 1) // going out, so add that room number to rooms
            rooms.push_back(ans[i]);
        else if (occupied == (int)rooms.size()) // no more vacant rooms, so
                                                // increase number of rooms
            ans[i] = ++max_rooms;
        else // give a room and increase occupancy count
            ans[i] = rooms[occupied++];
    }
    cout << max_rooms << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    cout << endl;

    return 0;
}
