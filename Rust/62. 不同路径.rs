/*
太邪门了，如果里面的 i128 换成 u64,usize， 有个 test case 100,2 在自己测的时候返回结果是正确的但是提交就无法通过，每步跟踪都没发现有哪里会溢出
在测试时候运行结果的值都是对的， 结果提交时候就变了
test case : 100,2, 在运行时返回 100, accepted, 提交时候返回 
*/
impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        // return C_(m-1+n-1)^(n-1)
        let bigger:i128 = if m > n{(m-1) as i128} else {(n-1) as i128};
        let smaller:i128 = if m > n {(n-1) as i128} else {(m-1) as i128};
        (Self::product(bigger+1, bigger+smaller)/Self::product(1,smaller)) as i32
    }
    pub fn product(from:i128, to:i128)->i128{
        let mut result:i128 = 1;
        let mut cursor:i128 = from;
        while cursor <= to{
            result = result * cursor;
            cursor = cursor + 1;
        }
        result
    }
}