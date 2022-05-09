#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        if (turnedOn >= 9)
            return vector<string>();
        dfs(0, turnedOn);
        return res;
    }

private:
    int hour {};
    int minits {};
    vector<string> res {};
    vector<int> lookup { 8, 4, 2, 1, 32, 16, 8, 4, 2, 1 };
    void dfs(int cursor, int turnedOn)
    {
        if (hour >= 12 || minits >= 60)
            return;
        if (turnedOn == 0) {
            constructTime();
            return;
        }
        if (cursor >= lookup.size())
            return;
        // case 1: select curr
        if (cursor <= 3) {
            hour += lookup[cursor];
        } else
            minits += lookup[cursor];
        dfs(cursor + 1, turnedOn - 1);
        if (cursor <= 3) {
            hour -= lookup[cursor];
        } else
            minits -= lookup[cursor];

        dfs(cursor + 1, turnedOn);
    }
    void constructTime()
    {
        string hour_str = to_string(hour);
        string min_str = to_string(minits);
        if (min_str.size() < 2) {
            min_str = "0" + min_str;
        }
        res.push_back(hour_str + ":" + min_str);
    }
};
