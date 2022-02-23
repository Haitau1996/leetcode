/*
* 问题主要是对 Rust 的语法不熟， 注意所有权的问题
*/
use std::collections::HashMap;
impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut sum_counts = HashMap::new();
        sum_counts.insert(0,1);
        let mut current_sum:i32 = 0;
        let mut result:i32 = 0;
        for elem in &nums{
            current_sum = current_sum + elem;
            match sum_counts.get(&(current_sum - k)){
                Some(val) => result = result + val,
                None => result = result
            };
            match sum_counts.get(&current_sum){
                Some(val) => sum_counts.insert(current_sum,val+1),
                Node => sum_counts.insert(current_sum,1)
            };
        }
        result
    }
}