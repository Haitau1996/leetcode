// 贪心
pub fn max_number_of_apples(mut weight: Vec<i32>) -> i32 {
    weight.sort();
    let mut total = 0;
    let mut i: usize = 0;
    while total <= 5000 && i < weight.len() {
        total = total + weight[i];
        i = i + 1;
    }
    if total <= 5000 {
        i as i32
    } else {
        (i - 1) as i32
    }
}
