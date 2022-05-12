// 为了利用缓存的 locality, 我们逐行访问元素
pub fn min_deletion_size(strs: Vec<String>) -> i32 {
    let mut s: Vec<&[u8]> = Vec::new();
    let m = strs.len();
    let n = strs[0].len();
    for i in 0..strs.len() {
        s.push(strs[i].as_bytes());
    }
    let mut buffer = vec![false; n];
    let mut res = 0;
    for i in 1..m {
        for j in 0..n {
            if !buffer[j] && s[i][j] < s[i - 1][j] {
                buffer[j] = true;
                res = res + 1;
            }
        }
    }
    res
}
