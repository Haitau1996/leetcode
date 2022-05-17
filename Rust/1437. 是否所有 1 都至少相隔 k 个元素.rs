// 题目不难， 但是我第一次写只考虑了右边界没有考虑左边界导致有个 case failed
// 写简单题时候还是要小心边界的情况
// 左边界不为 0 && 右边界不超过 len && 左右之差小于 k 才返回 false
pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
    let mut left: usize = 0;
    let mut right: usize = 1;
    let len = nums.len();
    while right < len {
        while right < len && nums[right] == 0 {
            right = right + 1;
        }
        if nums[left] == 1 && right < len && ((right - left - 1) as i32) < k {
            return false;
        }
        left = right;
        right = left + 1;
    }
    true
}
