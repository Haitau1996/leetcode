// 做法1： 将所有的单词-下标 映射放到一个 unordered_multimap 中，然后遍历
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class WordDistance {
public:
    WordDistance(vector<string>& wordsDict)
    {
        for (int i = 0; i < wordsDict.size(); ++i) {
            strToIndex.emplace(wordsDict[i], i);
        }
    }

    int shortest(string word1, string word2)
    {
        auto range1 = strToIndex.equal_range(word1);
        auto range2 = strToIndex.equal_range(word2);
        auto res = numeric_limits<int>::max();
        for (auto iter1 = range1.first; iter1 != range1.second; ++iter1) {
            for (auto iter2 = range2.first; iter2 != range2.second; ++iter2) {
                if (abs(iter1->second - iter2->second) < res)
                    res = abs(iter1->second - iter2->second);
                if (res == 1)
                    return res;
            }
        }
        return res;
    }

private:
    unordered_multimap<string, int> strToIndex {};
};
// 改进做法： word-> index 的映射， 在线查找
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2)
    {
        unordered_map<string, int> buffer;
        int res = numeric_limits<int>::max();
        for (int i = 0; i < words.size(); ++i) {
            if (word1 == words[i] && buffer.find(word2) != buffer.end()) {
                res = min(res, i - buffer[word2]);
            } else if (word2 == words[i] && buffer.find(word1) != buffer.end()) {
                res = min(res, i - buffer[word1]);
            }
            buffer[words[i]] = i;
        }
        return res;
    }
};
