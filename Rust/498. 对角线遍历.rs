// 找规律， 根据 i, j 的和的值判断向上还是向下

use std::cmp;
impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let m = mat.len();
        let n = mat[0].len();
        let mut curr: usize = 0;
        let mut res = Vec::new();
        while curr < m + n {
            if curr & 0x1 != 0 {
                let mut j = cmp::min(curr, n - 1);
                let mut i = curr - j;
                while i < m {
                    res.push(mat[i][j]);
                    if j == 0 {
                        break;
                    }
                    j = j - 1;
                    i = i + 1;
                }
            } else {
                let mut i = cmp::min(curr, m - 1);
                let mut j = curr - i;
                while j < n {
                    res.push(mat[i][j]);
                    if i == 0 {
                        break;
                    }
                    i = i - 1;
                    j = j + 1;
                }
            }
            curr = curr + 1;
        }
        res
    }
}
