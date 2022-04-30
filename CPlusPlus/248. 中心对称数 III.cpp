#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    int strobogrammaticInRange(string low, string high)
    {
        int res = 0;
        int lowsz = low.size();
        int highsz = high.size();
        if (lowsz == highsz) {
            auto temp = findStrobogrammatic(lowsz);
            for (const auto& elem : temp) {
                if (elem >= low && elem <= high) {
                    ++res;
                }
            }
            return res;
        } else {
            for (int i = lowsz + 1; i < highsz; ++i) {
                res += get_all_int(i);
            }
            auto temp = findStrobogrammatic(lowsz);
            for (const auto& elem : temp) {
                if (elem >= low)
                    ++res;
            }
            temp = findStrobogrammatic(highsz);
            for (const auto& elem : temp) {
                if (elem <= high)
                    ++res;
            }
            return res;
        }
    }

private:
    int get_all_int(int i)
    {
        int times = i / 2;
        int res = 4 * pow(5, times - 1);
        if (i & 0x1)
            res *= 3;
        return res;
    }
    vector<string> findStrobogrammatic(int n)
    {
        constructHalf(0, n / 2);
        vector<string> res;
        for (const auto& elem : halfPart) {
            auto revelem = reverseElement(elem);
            if (n % 2 == 0) {
                res.push_back(elem + revelem);
            } else {
                for (const auto& mid : center) {
                    res.push_back(elem + mid + revelem);
                }
            }
        }
        halfPart.clear();
        current = string("");
        return res;
    }
    vector<char> total { '1', '8', '6', '9' };
    vector<string> center { "0", "1", "8" };
    string current {};
    vector<string> halfPart;
    void constructHalf(int cursor, int half)
    {
        if (cursor == half) {
            halfPart.push_back(current);
            return;
        } else {
            for (const auto& ca : total) {
                current.push_back(ca);
                constructHalf(cursor + 1, half);
                current.pop_back();
            }
            if (cursor != 0) {
                current.push_back('0');
                constructHalf(cursor + 1, half);
                current.pop_back();
            }
        }
    }
    string reverseElement(const string& elem)
    {
        string revelem(elem);
        reverse(revelem.begin(), revelem.end());
        for (int i = 0; i < revelem.size(); ++i) {
            if (revelem[i] == '6')
                revelem[i] = '9';
            else if (revelem[i] == '9')
                revelem[i] = '6';
        }
        return revelem;
    }
};
