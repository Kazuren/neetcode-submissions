impl Solution {


    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut frequencies: [(i32, i32); 2001] = [(0, 0); 2001];

        for n in nums {
            frequencies[(n + 1000) as usize].0 = n;
            frequencies[(n + 1000) as usize].1 += 1;
        }

        frequencies.sort_by(|a, b| b.1.cmp(&a.1));

        return frequencies.into_iter().map(|x| x.0).take(k as usize).collect();
    }
}
