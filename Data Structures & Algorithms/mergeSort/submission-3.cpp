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
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        mergeSortInternal(pairs, 0, pairs.size() - 1);
        return pairs;
    }


    void mergeSortInternal(vector<Pair>& pairs, int startIndex, int endIndex) {
        int len = endIndex - startIndex + 1;
        if (len <= 1)
        {
            return;
        }

        // avoids overflow by subtracting first
        int middleIndex = startIndex + (endIndex - startIndex) / 2;
        mergeSortInternal(pairs, startIndex, middleIndex);
        mergeSortInternal(pairs, middleIndex + 1, endIndex);

        merge(pairs, startIndex, middleIndex, endIndex);
    }

    void merge(vector<Pair>& pairs, int startIndex, int middleIndex, int endIndex) {
        vector<Pair> tempPairs;

        int p1 = startIndex;
        int p2 = middleIndex + 1;

        for (int i = 0; i <= endIndex; i++)
        {
            tempPairs.push_back(pairs[i]);
        }

        int i = startIndex;
        while (p1 <= middleIndex && p2 <= endIndex)
        {
            if (tempPairs[p1].key <= tempPairs[p2].key)
            {
                pairs[i] = tempPairs[p1];
                p1++;
            } else
            {
                pairs[i] = tempPairs[p2];
                p2++;
            }
            i++;
        }

        while (p1 <= middleIndex)
        {
            pairs[i] = tempPairs[p1];
            p1++;
            i++;
        }

        while (p2 <= endIndex)
        {
            pairs[i] = tempPairs[p2];
            p2++;
            i++;
        }
    }
};
