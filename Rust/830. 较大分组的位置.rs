pub fn large_group_positions(s: String) -> Vec<Vec<i32>> {
    let mut res = Vec::new();
    let vs: Vec<char> = s.chars().collect();
    let mut low = 0;
    let mut high = 0;
    while low < s.len() {
        while high < s.len() && vs[low] == vs[high] {
            high = high + 1;
        }
        if high - low > 2 {
            res.push(vec![low as i32, (high - 1) as i32]);
        }
        low = high;
    }
    res
}
