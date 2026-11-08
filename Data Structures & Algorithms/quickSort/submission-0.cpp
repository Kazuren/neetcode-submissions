// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<Pair> quickSort(vector<Pair>& pairs) {
        quickSortInternal(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void quickSortInternal(vector<Pair>& pairs, int startIndex, int endIndex) {
        if (endIndex - startIndex + 1 <= 1) {
            return;
        }

        Pair& pivot = pairs[endIndex];

        int insertionIndex = startIndex;
        int leftIndex = startIndex;

        while (leftIndex <= endIndex)
        {
            if (pairs[leftIndex].key < pivot.key)
            {
                swap(pairs[insertionIndex], pairs[leftIndex]);
                insertionIndex++;
            }

            leftIndex++;
        }

        swap(pairs[insertionIndex], pivot);
        quickSortInternal(pairs, startIndex, insertionIndex - 1);
        quickSortInternal(pairs, insertionIndex + 1, endIndex);
    }
};
