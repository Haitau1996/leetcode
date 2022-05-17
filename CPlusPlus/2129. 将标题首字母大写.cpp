#include <string>

using namespace std;
class Solution {
public:
    string capitalizeTitle(string title)
    {
        int low = 0;
        int high = 0;
        while (low < title.size()) {
            while (high < title.size() && title[high] != ' ') {
                ++high;
            }
            format_in_range(title, low, high);
            low = high + 1;
            high = low;
        }
        return title;
    }

private:
    void format_in_range(string& s, int low, int high)
    {
        for (int i = low; i < high; ++i) {
            s[i] = tolower(s[i]);
        }
        if (high - low > 2) {
            s[low] = toupper(s[low]);
        }
    }
};
