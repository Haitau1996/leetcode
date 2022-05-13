pub fn kth_grammar(n: i32, k: i32) -> i32 {
    if n == 1 {
        return 0;
    } else {
        let half = (k - 1) / 2;
        let offset = (k - 1) % 2;
        if offset == 0 {
            return Self::kth_grammar(n - 1, half + 1);
        }
        return 1 - Self::kth_grammar(n - 1, half + 1);
    }
}
