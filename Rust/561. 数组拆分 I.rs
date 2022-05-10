pub fn array_pair_sum(mut nums: Vec<i32>) -> i32 {
    let mut res = 0;
    let mut i: usize = 0;
    nums.sort();
    while i < nums.len() {
        res = res + nums[i];
        i = i + 2;
    }
    res
}
