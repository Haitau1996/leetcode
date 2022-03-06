use std::cmp;
impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let mut dp:Vec<i32> = vec![cost[0],cost[1]];
        let mut index:usize = 2;
        let len = cost.len();
        while index < len{
            dp[index%2] = cmp::min(dp[index%2], dp[(index-1)%2]) + cost[index];
            index = index + 1;
        }
        if dp[0] < dp[1]{
            return dp[0];
        }
        dp[1]
    }
}