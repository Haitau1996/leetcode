// 使用指针挪动，固定 low, 然后挪动 mid 和 high
// 这里需要注意的是， mid 和 high 往一个方向挪动， 时间复杂度依旧是是 O(n)
// 因为 mid 最多挪动 n 次， high 也最多挪动 n 次， 并且两者的挪动不是 nested
pub fn triangle_number(mut nums: Vec<i32>) -> i32 {
    if nums.len() < 3 {
        return 0;
    }
    nums.sort();
    let mut low: usize = 0;
    let mut res: i32 = 0;
    while low < nums.len() - 2 {
        let mut mid = low + 1;
        let mut high = mid + 1;
        while mid < high || high < nums.len() {
            while high < nums.len() && (high <= mid || nums[low] + nums[mid] > nums[high]) {
                high = high + 1;
            }
            res = res + (high - mid - 1) as i32;
            mid = mid + 1;
        }
        low = low + 1;
    }
    res
}
