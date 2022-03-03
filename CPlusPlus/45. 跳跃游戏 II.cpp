/*
执行用时：208 ms, 在所有 C++ 提交中击败了15.39% 的用户
内存消耗：17.1 MB, 在所有 C++ 提交中击败了5.29% 的用户
*/

public:
    int jump(vector<int>& nums) {
        vector<int> record;
        record.push_back(0);
        for(int i = nums.size()-2; i >= 0; --i){
            if(i + nums[i] >= (nums.size()-1))
                record.push_back(1);
            else{
                int temp = std::numeric_limits<int>::max()-1;
                for(int j = 1; j <= nums[i]; ++j){
                    if(record[record.size()-j] < temp)
                        temp = record[record.size()-j];
                }
                record.push_back(temp+1);
            }
        }
        return record[record.size()-1];
    }
};