pub fn find_max_consecutive_ones(mut nums: Vec<i32>) -> i32 {
    let mut result: i32 = 0;
    let sz: usize = nums.len();
    for index in 0..sz {
        if index == 0 || nums[index] == 0 {
            if nums[index] > result {
                result = nums[index];
            }
            continue;
        } else {
            nums[index] = nums[index - 1] + nums[index];
            if nums[index] > result {
                result = nums[index];
            }
        }
    }
    result
}
