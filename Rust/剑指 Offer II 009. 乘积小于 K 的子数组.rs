/*
 * 没有特别的， 典型的双指针
 * 就是要想清楚， 每次计数都是按照右端点开始数就不会出错
*/
impl Solution {
    pub fn num_subarray_product_less_than_k(nums: Vec<i32>, k: i32) -> i32 {
        if k == 0{
            return 0
        }
        let mut beg:usize = 0;
        let mut end:usize = 0;
        let mut count:i32 = 0;
        let mut current_product:i32 = nums[beg];
        while end < nums.len(){
            if current_product < k{
                count = count + end as i32 + 1 - beg as i32;
                end = end + 1;
                if end < nums.len(){
                    current_product = current_product * nums[end];
                }
            }
            else{
                if beg != end{
                    current_product = current_product/ nums[beg];
                    beg = beg + 1;
                }
                else{
                    beg = beg + 1;
                    end = end + 1;
                    if beg < nums.len(){
                        current_product = nums[beg];
                    }
                }
            }
        }
        count
    }
}