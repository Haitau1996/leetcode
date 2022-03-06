impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        let mut dp:Vec<i32> = vec![2,1];
        let mut i:usize= 3;
        while i as i32 <= n{
            dp[i%2] = dp[(i-1)%2] + dp[i%2];
            i = i + 1;
        }
        dp[(n as usize)%2]
    }
}