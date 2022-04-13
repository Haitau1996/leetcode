class Solution {
public:
    string reorganizeString(string s) {
        vector<int> hash(26,0);
        int length = s.size();
        for(const auto& ca : s){
            ++hash[ca-'a'];
        }
        int max_count = *max_element(hash.begin(), hash.end());
        if(max_count > (s.size()+1)/2) return string("");
        string reorganizeArray(s.size(),'a');
        int evenIndex = 0, oddIndex = 1;
        int halfLength = length / 2;
        for (int i = 0; i < 26; i++) {
            char c = (char) ('a' + i);
            while (hash[i] > 0 && hash[i] <= halfLength && oddIndex < length) {
                reorganizeArray[oddIndex] = c;
                hash[i]--;
                oddIndex += 2;
            }
            while (hash[i] > 0) {
                reorganizeArray[evenIndex] = c;
                hash[i]--;
                evenIndex += 2;
            }
        }
        return reorganizeArray;
    }
};
