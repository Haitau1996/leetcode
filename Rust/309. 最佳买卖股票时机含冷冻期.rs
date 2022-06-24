use std::cmp;
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let len = prices.len();
        let mut dp = vec![vec![0; 3]; len];
        dp[0][0] = -prices[0];
        for i in 1..len {
            dp[i][0] = cmp::max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = cmp::max(dp[i - 1][1], dp[i - 1][2]);
            dp[i][2] = dp[i - 1][0] + prices[i];
        }
        cmp::max(dp[len - 1][1], dp[len - 1][2])
    }
}
