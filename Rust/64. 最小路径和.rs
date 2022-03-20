use std::cmp;
impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m: usize = grid.len();
        let n: usize = grid[0].len();
        let mut dp:Vec<Vec<i32>> = vec![vec![0;n]; 2];
        let mut i:usize = 0;
        while i < m {
            let mut j = 0;
            while j < n {
                if i==0 && j == 0{
                    dp[i][j] = grid[i][j];
                }else if i == 0{
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }else if j == 0 {
                    dp[i%2][j] = dp[(i-1)%2][j] + grid[i][j];
                }else{
                    dp[i%2][j] = cmp::min(dp[(i-1)%2][j], dp[i%2][j-1]) + grid[i][j];
                }
                j = j+1;
            }
            i = i + 1;
        }
        dp[(m-1)%2][n-1]
    }
}
// dp 还可以缩成 one-D array
use std::cmp;
impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m: usize = grid.len();
        let n: usize = grid[0].len();
        let mut dp:Vec<i32> = vec![0;n];
        let mut i:usize = 0;
        while i< m {
            let mut j: usize = 0;
            while j < n{
                if i == 0 && j == 0{
                    dp[j] = grid[i][j];
                }else if i == 0{
                    dp[j] = grid[i][j] + dp[j-1];
                }else if j == 0{
                    dp[j] = dp[j] + grid[i][j];
                }else{
                    dp[j] = cmp::min(dp[j-1], dp[j]) + grid[i][j];
                }
                j = j+1;
            }
            i = i + 1;
        }
        dp[n-1]
    }
}