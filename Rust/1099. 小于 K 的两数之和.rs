pub fn two_sum_less_than_k(nums: Vec<i32>, k: i32) -> i32 {
    let mut res: i32 = -1;
    let mut i: usize = 0;
    while i < nums.len() - 1 {
        let mut j = i + 1;
        while j < nums.len() {
            if nums[i] + nums[j] < k && nums[i] + nums[j] > res {
                res = nums[i] + nums[j];
            }
            j = j + 1;
        }
        i = i + 1;
    }
    res
}
