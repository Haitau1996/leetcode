/*
* time 100 mem 20 
* string 可以使用迭代器再collect 放到容器中， 这时候每个元素都是 char, 好调用相关的方法
*/
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let str: Vec<_> = s.chars().collect();
        let mut low:usize = 0;
        let mut high:usize = s.len() - 1;
        loop{ 
            loop{
                if low >= high || str[high].is_alphanumeric(){
                    break;
                }
                high = high - 1;
            }
            loop{
                if low >= high || str[low].is_alphanumeric(){
                    break;
                }
                low = low + 1;
            }            
            if low >= high{
                break;
            }   
            if str[low].to_ascii_lowercase() == str[high].to_ascii_lowercase(){
                low = low + 1;
                high = high -1;
            }
            else{
                return false;
            }
        }
        true
    }
}