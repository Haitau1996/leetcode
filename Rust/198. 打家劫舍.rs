use std::cmp;
impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let sz:usize = nums.len();
        if sz == 1 {
            return nums[0];
        }else{
            let mut dp = vec![0;2];
            dp[0] = nums[0]; 
            dp[1] = cmp::max(nums[0],nums[1]);
            let mut index:usize = 2;
            while index < sz{
                dp[index%2] = cmp::max(dp[index%2]+nums[index],dp[(index-1)%2]);
                index = index + 1;
            }
            cmp::max(dp[0],dp[1])
        }
    }
}