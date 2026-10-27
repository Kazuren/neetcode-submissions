impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut anagram_groups: HashMap<[u32; 26], Vec<String>> = HashMap::new();

        // key = [0, 26] array

        for anagram in strs.iter() {
            let mut charFrequency: [u32; 26] = [0; 26];
            for c in anagram.chars() {
                charFrequency[c as usize - 'a' as usize] += 1;
            }

            anagram_groups.entry(charFrequency).or_insert(vec![]).push(anagram.to_owned());
        }

        let mut groups = vec![];
        for (_freq, group) in anagram_groups.iter() {
            groups.push(group.to_owned());
        }
        return groups;
    }
}
