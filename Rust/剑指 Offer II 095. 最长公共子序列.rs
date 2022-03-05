use std::cmp;
impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let vec1:Vec<char> = text1.chars().collect();
        let vec2:Vec<char> = text2.chars().collect();
        let mut result= vec![vec![0;vec2.len()+1];2];
        let mut i: usize = 0;
        
        while i < vec1.len(){
            let mut j:usize = 0;
            while j < vec2.len(){
                if vec1[i] == vec2[j]{
                    result[(i+1)%2][j+1] = result[i%2][j] + 1;
                }else{
                    result[(i+1)%2][j+1] = cmp::max(result[(i+1)%2][j], result[i%2][j+1]);
                }
                j = j+1;
            }
            i = i + 1;
        }
        result[vec1.len()%2][vec2.len()]
    }
}