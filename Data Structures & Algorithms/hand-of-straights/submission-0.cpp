class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }
        
        vector<int> uniqueCards;
        for (auto& pair : count) {
            uniqueCards.push_back(pair.first);
        }
        sort(uniqueCards.begin(), uniqueCards.end());
        
        for (int card : uniqueCards) {
            int neededGroups = count[card];
            
            if (neededGroups > 0) {
                for (int i = 0; i < groupSize; i++) {
                    int currentCard = card + i;
                    
                    if (count[currentCard] < neededGroups) {
                        return false;
                    }
                    
                    count[currentCard] -= neededGroups;
                }
            }
        }
        
        return true;
    }
};