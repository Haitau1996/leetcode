class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> dict{'a','A','e','E','i','I','o','O','u','U'};
        int low = 0;
        int high = s.size() - 1;
        while(low < high){
            while(low < high && dict.find(s[low]) == dict.end()){
                ++low;
            }
            while(low < high && dict.find(s[high]) == dict.end()){
                --high;
            }
            if(low < high){
                swap(s[low],s[high]);
                ++low;
                --high;
            }
        }
        return s;
    }
};