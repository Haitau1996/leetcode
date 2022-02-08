class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> result;
        int i = 1;
        while(n > log10(i)){
            result.push_back(i);
            ++i;
        }
        return result;    
    }
};