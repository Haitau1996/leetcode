/*
* 需要注意一点， 就是 rust 的类型系统非常严格
*/
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut left = 0;
        let mut right = nums.len()-1;
        while left <= right{
            let mid = (left + right)/2;
            if nums[mid] >= target{
                if mid == 0 || nums[mid-1] < target{
                    return mid as i32;
                }
                right = mid -1;
            } else{
                left = mid + 1;
            }
        }
        nums.len() as i32
    }
}