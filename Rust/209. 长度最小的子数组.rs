// 使用双指针即可， 需要注意， rust 中的类型系统十分严格， 
// usize 和 i32 之间需要有类型转换， 否则会报错
impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut low:usize = 0;
        let mut high:usize = 0;
        let mut res:i32 = 0;
        let mut curr_sum:i32 = 0;
        while high <= nums.len(){
            if curr_sum < target {
                if high != nums.len(){
                    curr_sum = curr_sum + nums[high];
                }
                high = high + 1;
            } else{
                if res == 0 || (res!= 0 && res> (high-low) as i32){
                    res = (high - low) as i32;
                }
                curr_sum = curr_sum - nums[low];
                low = low + 1;
            }
        }
        res
    }
}
