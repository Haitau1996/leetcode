/*
 * 双指针， 从后向前拷贝
 */
#include <string>
using std::string;
class Solution {
public:
    string defangIPaddr(string address)
    {
        int cursor = address.size() - 1;
        address += "666666";
        int new_cursor = address.size() - 1;
        while (cursor != new_cursor) {
            if (address[cursor] != '.') {
                address[new_cursor--] = address[cursor--];

            } else {
                address[new_cursor--] = ']';
                address[new_cursor--] = '.';
                address[new_cursor--] = '[';
                cursor--;
            }
        }
        return address;
    }
};
