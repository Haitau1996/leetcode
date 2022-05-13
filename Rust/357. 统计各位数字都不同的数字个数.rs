impl Solution {
    pub fn count_numbers_with_unique_digits(n: i32) -> i32 {
        if n == 0 {
            return 1;
        } else {
            return Self::n_bit(n) + Self::count_numbers_with_unique_digits(n - 1);
        }
    }
    pub fn n_bit(n: i32) -> i32 {
        let mut res = 9;
        let mut i = 1;
        while i < n {
            res = res * (10 - i);
            i = i + 1;
        }
        res
    }
}
