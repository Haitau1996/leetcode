// 双指针

impl Solution {
    pub fn sort_array_by_parity(mut nums: Vec<i32>) -> Vec<i32> {
        let mut low: usize = 0;
        let mut high: usize = nums.len() - 1;
        while low < high {
            while low < high && (nums[low] % 2 == 0) {
                low = low + 1;
            }
            while low < high && nums[high] % 2 == 1 {
                high = high - 1;
            }
            if low < high {
                nums.swap(low, high);
            }
        }
        nums
    }
}
