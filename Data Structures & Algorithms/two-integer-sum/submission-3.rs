impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        // target 7, current = 3, index = 0 -> required = 4, store 3 -> 0

        let mut found: HashMap<i32, usize> = HashMap::new();

        for (i, n) in nums.iter().enumerate() {
            
            let required: i32 = target - n;
            if found.contains_key(&required)
            {
               return Vec::from([found[&required] as i32, i as i32]);
            }

            found.entry(*n).or_insert(i);
        }

        return Vec::new();
    }
}
