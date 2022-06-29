/*
 * 思路很简单， 就是使用一个整数作为短的 url, 然后使用哈希表存放短 url 到长 url 的映射
 */
#include <unordered_map>
#include <string>

using namespace std;
class Solution {
    unordered_map<int, string> lookup{};
    int id{0};
    string prev{"http://tinyurl.com/"};
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        lookup[id] = longUrl;
        return prev+to_string(id++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string id_str = shortUrl.substr(prev.size(), shortUrl.size() - prev.size());
        return lookup[stoi(id_str)];
    }
};
