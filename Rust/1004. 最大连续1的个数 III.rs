use std::cmp;
impl Solution {
    pub fn longest_ones(nums: Vec<i32>, k: i32) -> i32 {
        let mut left = 0usize;
        let mut right = 0usize;
        let mut cnt = 0i32;
        let mut res = 0usize;
        while right < nums.len() {
            if cnt <= k {
                if nums[right] == 0 {
                    cnt = cnt + 1;
                }
                right = right + 1;
            } else {
                if left < right && nums[left] == 0 {
                    cnt = cnt - 1;
                }
                left = left + 1;
            }
            if cnt <= k {
                res = cmp::max(res, right - left);
            }
        }
        res as i32
    }
}
