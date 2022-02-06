/*
* 需要特别注意， 两个单词相等的时候返回的应该是 true
*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> hash_pos(order.size(),0);
        for(int i =0; i<order.size(); ++i){
            hash_pos[order[i] - 'a'] = i;
        }
        auto cmp = [&hash_pos](const string& first, const string& second){
            int i = 0;
            while(i < first.size() && i< second.size()){
                if(first[i] != second[i])
                    return hash_pos[first[i]-'a'] < hash_pos[second[i]-'a'];
                else ++i;
            }
            return i == first.size() && i!= second.size();
        };
        return is_sorted(words.begin(), words.end(), cmp);
    }

};