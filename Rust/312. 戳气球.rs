use std::cmp;
impl Solution {
    pub fn max_coins(nums: Vec<i32>) -> i32 {
        let n: usize = nums.len();
        let mut val = vec![0; n + 2];
        val[0] = 1;
        val[n + 1] = 1;
        for i in 0..n {
            val[i + 1] = nums[i];
        }
        let mut dp = vec![vec![0; n + 2]; n + 2];
        for i in (0..n).rev() {
            for j in (i + 2)..(n + 2) {
                for k in (i + 1)..j {
                    let sum = val[i] * val[k] * val[j];
                    dp[i][j] = cmp::max(dp[i][j], sum + dp[i][k] + dp[k][j]);
                }
            }
        }
        dp[0][n + 1]
    }
}
