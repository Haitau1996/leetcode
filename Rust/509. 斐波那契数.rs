impl Solution {
    pub fn fib(n: i32) -> i32 {
        let mut dp = vec![0,1];
        if n >= 2{
            for i in 2..(n+1){
                dp[(i%2) as usize] = dp[(i%2) as usize] + dp[((i+1)%2) as usize];
            }
        }
        dp[(n%2) as usize] as i32
    }
}