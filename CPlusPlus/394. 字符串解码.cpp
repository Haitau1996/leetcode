// 使用递归对 low, high 范围内求解
// 需要注意：这里的low high 是闭区间, 在做 substr 时候要加一
#include <string>

using std::string;
class Solution {
public:
    string decodeString(string s)
    {
        return decode_in_range(s, 0, s.size() - 1);
    }

private:
    string decode_in_range(string& s, int low, int high)
    {
        if (low > high)
            return string {};
        int numleft = low;
        while (numleft <= high && isalpha(s[numleft])) {
            ++numleft;
        }
        if (numleft == high + 1)
            return s.substr(low, high - low + 1);
        int numright = numleft;
        while (numright <= high && isdigit(s[numright])) {
            ++numright;
        }
        int mul = stoi(s.substr(numleft, numright - numleft));
        int brac_count = 0;
        if (s[numright] == '[') {
            ++brac_count;
        }
        int base = numright + 1;
        while (base <= high && brac_count != 0) {
            if (base <= high && s[base] == '[')
                ++brac_count;
            else if (base <= high && s[base] == ']')
                --brac_count;
            ++base;
        }
        string res {};
        if (numleft > low)
            res += s.substr(low, numleft - low);
        auto temp = decode_in_range(s, numright + 1, base - 2);
        for (int i = 0; i < mul; ++i) {
            res += temp;
        }
        res += decode_in_range(s, base, high);
        return res;
    }
};
