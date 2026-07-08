class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> states;
        int n = pairs.size();
        
        for (int i = 0; i < n; i++) {
            int j = i;
            
            while (j > 0 && pairs[j].key < pairs[j - 1].key) {
                Pair temp = pairs[j];
                pairs[j] = pairs[j - 1];
                pairs[j - 1] = temp;
                
                j--;
            }
            states.push_back(pairs);
        }
        return states;
    }
};