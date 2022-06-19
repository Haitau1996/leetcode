// 动态规划， 记录左边&右边的最大值
use std::cmp;
impl Solution {
    pub fn trap(height: Vec<i32>) -> i32 {
        let n = height.len();
        let mut prefix: Vec<i32> = vec![0; n];
        let mut postfix = vec![0; n];
        prefix[0] = height[0];
        for i in 1..n {
            prefix[i] = cmp::max(prefix[i - 1], height[i]);
        }
        postfix[n - 1] = height[n - 1];
        for i in (0..(n - 1)).rev() {
            postfix[i] = cmp::max(postfix[i + 1], height[i]);
        }
        let mut res = 0i32;
        for i in 1..n - 1 {
            let curr = cmp::min(prefix[i - 1], postfix[i + 1]);
            if curr > height[i] {
                res = res + (curr - height[i]);
            }
        }
        res
    }
}
