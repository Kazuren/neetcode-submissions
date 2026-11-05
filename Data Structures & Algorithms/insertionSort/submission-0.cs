// Definition for a pair
// public class Pair {
//     public int Key;
//     public string Value;
//
//     public Pair(int key, string value) {
//         Key = key;
//         Value = value;
//     }
// }
public class Solution {
    public List<List<Pair>> InsertionSort(List<Pair> pairs) {

        List<List<Pair>> arrayState = new List<List<Pair>>();

        for (int i = 0; i < pairs.Count; i++)
        {
            int curr = i;
            int prev = curr - 1;
            while(curr > 0 && pairs[curr].Key < pairs[prev].Key)
            {
                Pair tmp = pairs[prev];
                pairs[prev] = pairs[curr];
                pairs[curr] = tmp;
                curr--;
                prev = curr - 1;
            }

            arrayState.Add(pairs.ToList());
        }

        return arrayState;
    }
}
