class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;
        vector<bool> used(baskets.size(), false);

        for (int fruit : fruits) {
            bool isPlaced = false;
            for (int j = 0; j < baskets.size(); ++j) {
                if (fruit <= baskets[j] && !used[j]) {
                    isPlaced = true;
                    used[j] = true;
                    break;
                }
            }

            if (!isPlaced) {
                unplaced += 1;
            }
        }

        return unplaced;
    }
};