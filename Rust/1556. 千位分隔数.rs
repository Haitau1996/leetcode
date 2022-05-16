use std::char;
impl Solution {
    pub fn thousand_separator(mut n: i32) -> String {
        if n == 0 {
            return String::from("0");
        }
        let mut res = String::new();
        let mut curr = 0;
        while n != 0 {
            if curr != 0 && curr % 3 == 0 {
                res.push('.');
            }
            let c = char::from_digit((n % 10) as u32, 10);
            match c {
                Some(x) => res.push(x),
                None => println!("failed"),
            };
            curr = curr + 1;
            n = n / 10;
        }
        res.chars().rev().collect::<String>()
    }
}
