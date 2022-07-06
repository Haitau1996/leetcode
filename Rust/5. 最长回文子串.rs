// dp[i][j] 表示 i..=j 的回文长度
impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let len = s.len();
        let sb = s.as_bytes().to_vec();
        let mut dp = vec![vec![0; len]; len];
        for i in 0..len {
            dp[i][i] = 1;
        }
        let mut curr_len = 1usize;
        let mut res = String::new();
        res.push(sb[0] as char);
        for j in 2..=len {
            for i in 0..=len - j {
                if sb[i] == sb[i + j - 1] {
                    if j == 2 {
                        dp[i][i + j - 1] = 2;
                    } else if dp[i + 1][i + j - 2] != 0 {
                        dp[i][i + j - 1] = dp[i + 1][i + j - 2] + 2;
                    }
                }
                if dp[i][i + j - 1] > curr_len {
                    curr_len = dp[i][i + j - 1];
                    res = (&s[i..(i + j)]).to_string();
                }
            }
        }
        res
    }
}
