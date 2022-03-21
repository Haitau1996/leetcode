/*
  我们使用了一个前缀和和一个后缀和， 思路是， 如果前一个数字不为 0， 就累加，为 0 就重置
  然后求结果的扫描 nums， 如果当下值是0, 结果就是前缀和后缀的和加一，如果不是， 就是两者的较大值，当下结果大于全局就更新
todo: 动态规划实现
*/
use std::cmp;
impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let lenth = nums.len();
        let mut prefix: Vec<i32> = vec![0; lenth];
        let mut postfix: Vec<i32> = vec![0; lenth];
        prefix[0] = nums[0];
        postfix[lenth - 1] = nums[lenth - 1];
        for index in 1..lenth {
            if nums[index - 1] == 0 {
                prefix[index] = nums[index];
            } else {
                prefix[index] = nums[index] + prefix[index - 1];
            }
            if nums[lenth - index] == 0 {
                postfix[lenth - index - 1] = nums[lenth - index - 1];
            } else {
                postfix[lenth - index - 1] = nums[lenth - index - 1] + postfix[lenth - index];
            }
        }
        let mut result: i32 = 0;
        for index in 0..lenth {
            let local_result = if nums[index] == 0 {
                prefix[index] + postfix[index] + 1
            } else {
                cmp::max(prefix[index], postfix[index])
            };
            if local_result > result {
                result = local_result;
            }
        }
        result
    }
}
