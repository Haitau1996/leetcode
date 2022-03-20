use std::cmp;
impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let m:usize = matrix.len();
        let n:usize = matrix[0].len();
        let mut dp:Vec<Vec<i32>> = vec![vec![0; n];2];
        let mut i:usize = 0;
        let mut result: i32 = 0;
        while i < m {
            let mut j: usize = 0;
            while j < n{
                if matrix[i][j] == '0'{
                    dp[i%2][j] = 0;
                } else {
                    if i == 0 || j == 0 {
                        dp[i%2][j] = 1;
                    }else {
                        dp[i%2][j] = cmp::min(dp[i%2][j-1], cmp::min(dp[(i-1)%2][j],dp[(i-1)%2][j-1])) + 1;
                    }
                    if dp[i%2][j] > result{
                        result = dp[i%2][j];
                    }
                }
                j = j+1;
            }
            i = i + 1;
        }
        result * result
    }
}