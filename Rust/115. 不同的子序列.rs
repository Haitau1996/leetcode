impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let m = s.len();
        let n = t.len();
        let mut dp: Vec<Vec<usize>> = vec![vec![0; n + 1]; m + 1];
        let mut i: usize = 0;
        while i <= m {
            dp[i][0] = 1;
            i = i + 1;
        }
        i = 0;
        while i < m {
            let mut j: usize = 0;
            while j < n && j <= i {
                dp[i + 1][j + 1] = dp[i][j + 1];
                if s.as_bytes()[i] == t.as_bytes()[j] {
                    dp[i + 1][j + 1] = dp[i + 1][j + 1] + dp[i][j];
                }
                j = j + 1;
            }
            i = i + 1;
        }
        dp[m][n] as i32
    }
}
impl BetterSolution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        let m = s.len();
        let n = t.len();
        let mut dp: Vec<Vec<usize>> = vec![vec![0; n + 1]; 2];
        let mut i: usize = 0;
        while i < 2 {
            dp[i][0] = 1;
            i = i + 1;
        }
        i = 0;
        while i < m {
            let mut j: usize = 0;
            while j < n && j <= i {
                dp[(i + 1) % 2][j + 1] = dp[i % 2][j + 1];
                if s.as_bytes()[i] == t.as_bytes()[j] {
                    dp[(i + 1) % 2][j + 1] = dp[(i + 1) % 2][j + 1] + dp[i % 2][j];
                }
                j = j + 1;
            }
            i = i + 1;
        }
        dp[m % 2][n] as i32
    }
}
