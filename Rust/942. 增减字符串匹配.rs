pub fn di_string_match(s: String) -> Vec<i32> {
    let mut low = 0;
    let mut high = s.len() as i32;
    let mut res = Vec::new();
    for c in s.chars() {
        if c == 'I' {
            res.push(low);
            low = low + 1;
        } else {
            res.push(high);
            high = high - 1;
        }
    }
    res.push(low);
    res
}
