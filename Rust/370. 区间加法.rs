// 暴力解法： 居然可以通过
// 优化解法： 先在 res[i] 中记录和前一个位置的差值， 然后做前缀和即为某处的正确结果
impl BruteForceSolution {
    pub fn get_modified_array(length: i32, updates: Vec<Vec<i32>>) -> Vec<i32> {
        let mut res = vec![0; length as usize];
        for i in 0..updates.len() {
            let beg = updates[i][0] as usize;
            let end = updates[i][1] as usize;
            let incr = updates[i][2];
            for j in beg..=end {
                res[j] = res[j] + incr;
            }
        }
        res
    }
}
impl BetterSolution {
    pub fn get_modified_array(length: i32, updates: Vec<Vec<i32>>) -> Vec<i32> {
        let mut res: Vec<i32> = vec![0; length as usize];
        for elem in updates {
            res[elem[0] as usize] = res[elem[0] as usize] + elem[2];
            if elem[1] + 1 < length as i32 {
                res[(elem[1] + 1) as usize] = res[(elem[1] + 1) as usize] - elem[2];
            }
        }
        for i in 1..res.len() {
            res[i] = res[i - 1] + res[i];
        }
        res
    }
}
