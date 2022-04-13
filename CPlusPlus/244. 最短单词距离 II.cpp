class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for(int i = 0; i < wordsDict.size();++i){
            strToIndex.emplace(wordsDict[i],i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto range1 = strToIndex.equal_range(word1);
        auto range2 = strToIndex.equal_range(word2);
        auto res = numeric_limits<int>::max();
        for(auto iter1 = range1.first; iter1!= range1.second; ++iter1){
            for(auto iter2= range2.first;iter2!=range2.second; ++iter2){
                if(abs(iter1->second - iter2->second) < res)
                    res = abs(iter1->second - iter2->second);
                    if(res == 1) return res;
            }
        }
        return res;
    }
private:
    unordered_multimap<string, int> strToIndex{};
};
