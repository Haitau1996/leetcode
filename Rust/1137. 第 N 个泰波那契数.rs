impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let mut dp = vec![0,1,1];
        let mut i:usize = 3;
        let sz:usize = 3;
        let un:usize = n as usize;
        while i <= un{
            dp[i%sz] = dp[i%sz] + dp[(i+1)%sz] + dp[(i+2)%sz];
            i = i + 1;
        }
        dp[un%sz]
    }
}