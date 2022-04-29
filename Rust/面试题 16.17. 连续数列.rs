impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let max_value = nums.iter().max();
        match max_value {
            None => println!("Min value was not found"),
            Some(i) => {
                if *i <= 0 {
                    return *i;
                }
            }
        }
        let mut res: i32 = 0;
        let mut curr: i32 = 0;
        for i in nums.iter() {
            if curr < 0 {
                curr = 0;
            }
            curr = curr + i;
            if curr > res {
                res = curr;
            }
        }
        res
    }
}
