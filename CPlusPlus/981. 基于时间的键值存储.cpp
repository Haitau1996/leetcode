//  哈希表 + 二分查找， 使用 string-> vector<pair<int, string>> 存放数据， 超时
//  发现超时是因为访问 vector 的时候没有使用引用，导致 vector 拷贝带来额外的开销
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
class TimeMap {
    using my_pair = pair<int, string>;

private:
    unordered_map<string, vector<my_pair>> lookup;

public:
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        lookup[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        auto vec = lookup[key];
        string temp;
        temp.push_back((char)127);
        auto val = my_pair(timestamp, temp);
        auto iter = upper_bound(vec.begin(), vec.end(), val);
        if (iter == vec.begin())
            return string("");
        else
            return (--iter)->second;
    }
};
