impl Solution {
    pub fn longest_diverse_string(a: i32, b: i32, c: i32) -> String {
        let mut buffer = vec!['a', 'b', 'c'];
        let mut res = String::new();
        let mut arr = vec![a, b, c];
        let mut max_i = Self::max_index(&arr);
        let mut min_i = Self::min_index(&arr);
        let mut mid_i = 3 - max_i - min_i;
        while arr[min_i] >= 0 && arr[max_i] > 0 {
            if res.len() < 2
                || res.as_bytes()[res.len() - 2] != buffer[max_i] as u8
                || res.as_bytes()[res.len() - 1] != buffer[max_i] as u8
            {
                res.push(buffer[max_i]);
                arr[max_i] = arr[max_i] - 1;
            } else if arr[mid_i] > 0 {
                res.push(buffer[mid_i]);
                arr[mid_i] = arr[mid_i] - 1;
            } else {
                break;
            }
            max_i = Self::max_index(&arr);
            min_i = Self::min_index(&arr);
            mid_i = 3 - max_i - min_i;
        }
        res
    }
    pub fn max_index(arr: &Vec<i32>) -> usize {
        let mut i: usize = 2;
        let mut max: i32 = arr[2];
        for (index, &x) in arr.iter().enumerate() {
            if x > max {
                max = x;
                i = index;
            }
        }
        i
    }
    pub fn min_index(arr: &Vec<i32>) -> usize {
        let mut i: usize = 0;
        let mut min: i32 = arr[0];
        for (index, &x) in arr.iter().enumerate() {
            if x < min {
                min = x;
                i = index;
            }
        }
        i
    }
}
