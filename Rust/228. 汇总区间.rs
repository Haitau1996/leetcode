pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
    let mut res = Vec::new();
    let mut low: usize = 0;
    let mut high: usize = low + 1;
    while low < nums.len() {
        while high < nums.len() && nums[high] == nums[high - 1] + 1 {
            high = high + 1;
        }
        if high == low + 1 {
            res.push(nums[low].to_string());
        } else {
            res.push(nums[low].to_string() + "->" + nums[high - 1].to_string().as_str());
        }
        low = high;
        high = low + 1;
    }
    res
}
