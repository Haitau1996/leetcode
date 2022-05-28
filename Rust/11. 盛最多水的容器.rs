// 指针向中间挪， 在宽度降低时只有高度变大的情况才能导致面积变大
// 而增加高度的情况就是让短板更长，所以挪动较小值的那个指针是对的
use std::cmp;
impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut high = height.len() - 1;
        let mut low: usize = 0;
        let mut res = 0;
        while low < high {
            res = cmp::max(
                res,
                ((high - low) as i32) * cmp::min(height[low], height[high]),
            );
            if height[low] < height[high] {
                low = low + 1;
            } else {
                high = high - 1;
            }
        }
        res
    }
}
