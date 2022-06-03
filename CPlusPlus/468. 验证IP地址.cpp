/*
 * 模拟给模拟吐了， 需要注意很多细节：
    1. 记得先对 ‘.’ 和 ‘：’ 计数， 如果不符合就肯定不是 IP 地址
    2. 对于 V4 和 V6， 都注意要检查low,high 之间的距离， 超过要求 || 长度为 0 都是不合法的
    3. 记得记录已经检查过了多少个数字， v4 最后应该为 4， v6 最后应该为 8
    5. 可以借助 getline 和 isxdigit 等库函数， 可以更加简洁的写代码
 */
#include <sstream>
#include <string>

using namespace std;
class Solution {
public:
    string validIPAddress(string queryIP)
    {
        if (valid_V4(queryIP))
            return string("IPv4");
        if (valid_V6(queryIP))
            return string("IPv6");
        return string("Neither");
    }

private:
    bool valid_V4(string& ip)
    {
        if (count(ip.begin(), ip.end(), '.') != 3)
            return false;
        int curr = 0;
        int low = 0;
        int high = 0;
        while (curr < 4 && high < ip.size()) {
            while (isdigit(ip[high])) {
                ++high;
            }
            if ((ip[low] == '0' && high - low != 1) || low == high || high - low > 3) {
                return false;
            } else if (stoi(ip.substr(low, high - low)) > 255) {
                return false;
            } else if (curr < 4 && high < ip.size() && ip[high] == '.') {
                ++curr;
                low = high + 1;
                high = low;
            } else if (high == ip.size() && high > low) {
                ++curr;
            } else
                return false;
        }
        return curr == 4 && high == ip.size();
    }
    bool valid_V6(string& ip)
    {
        if (count(ip.begin(), ip.end(), ':') != 7)
            return false;
        istringstream ss(ip);
        string temp {};
        int curr { 0 };
        while (getline(ss, temp, ':')) {
            if (temp.size() > 4 || temp.size() == 0)
                return false;
            for (const auto& c : temp) {
                if (!isxdigit(c))
                    return false;
            }
            ++curr;
        }
        return curr == 8;
    }
};