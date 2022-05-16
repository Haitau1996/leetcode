// 滑动窗口求解
// 使用 left,right 窗口， 记录其中的 true/false 个数， 如果其较小值不超过 k， 说明区间是合理的。
// 而我们要的是窗口的最大值， 因此 right 可以在每个循环中都向右滑（每个循环下窗口 size 要么加一要么不变）
use std::cmp;
impl Solution {
    pub fn max_consecutive_answers(answer_key: String, k: i32) -> i32 {
        let vs: Vec<char> = answer_key.chars().collect();
        let mut left: usize = 0;
        let mut right: usize = 0;
        let mut tc = 0;
        let mut fc = 0;
        let mut res = 0;
        while right < vs.len() {
            if vs[right] == 'T' {
                tc = tc + 1;
            } else {
                fc = fc + 1;
            }
            right = right + 1;
            if cmp::min(tc, fc) <= k {
                res = cmp::max((right - left) as i32, res);
            } else {
                if vs[left] == 'T' {
                    tc = tc - 1;
                } else {
                    fc = fc - 1;
                }
                left = left + 1;
            }
        }
        res
    }
}
