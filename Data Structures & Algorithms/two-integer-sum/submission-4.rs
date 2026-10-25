impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut found: HashMap<i32, usize> = HashMap::new();

        for (i, &n) in nums.iter().enumerate() {
            
            let required: i32 = target - n;

            if let Some(&index) = found.get(&required) {
                return vec![index as i32, i as i32]
            }

            found.insert(n, i);
        }

        return vec![];
    }
}
