/*
没有特别的东西， 就是使用两个队列对矩阵做 bfs
* 写 Rust的 while loop 不要忘记在结尾递增标识符
* Rust 的代码检测工具真好吗, 把 index 写成 i 马上提示 unused variable
* Rustfmt 也非常好用
*/
use std::collections::VecDeque;
pub fn update_matrix(mut mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut current: VecDeque<Vec<usize>> = VecDeque::new();
    let mut nextque: VecDeque<Vec<usize>> = VecDeque::new();
    let mut dist: i32 = 1;
    let m: usize = mat.len();
    let n: usize = mat[0].len();
    let mut checked: Vec<Vec<bool>> = vec![vec![false; n]; m];
    let mut i: usize = 0;
    while i < m {
        let mut j: usize = 0;
        while j < n {
            if mat[i][j] == 0 {
                current.push_back(vec![i, j]);
                checked[i][j] = true;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    let neighbors: Vec<Vec<i32>> = vec![vec![-1, 0], vec![1, 0], vec![0, -1], vec![0, 1]];
    'outter: while !current.is_empty() {
        'inner: while !current.is_empty() {
            match current.pop_front() {
                Some(x) => {
                    for index in 0..4 {
                        let new_x: usize = neighbors[index][0] as usize + x[0];
                        let new_y: usize = neighbors[index][1] as usize + x[1];
                        if new_x < m && new_y < n && !checked[new_x][new_y] {
                            mat[new_x][new_y] = dist;
                            checked[new_x][new_y] = true;
                            nextque.push_back(vec![new_x, new_y]);
                        }
                    }
                }
                None => break 'inner,
            }
        }
        dist = dist + 1;
        std::mem::swap(&mut current, &mut nextque);
    }
    mat
}
