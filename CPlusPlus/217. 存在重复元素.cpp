class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet{nums.begin(),nums.end()};
        if(numsSet.size() < nums.size()) return true;
        return false;
    }
};