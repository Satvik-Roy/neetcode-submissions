class Solution {
private:
    // Helper function to calculate squared Euclidean distance
    int getDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    // Standard Quick Sort Partition function
    int partition(vector<vector<int>>& points, int left, int right) {
        int pivotDist = getDistance(points[right]);
        int swapIndex = left;

        for (int i = left; i < right; i++) {
            if (getDistance(points[i]) < pivotDist) {
                swap(points[swapIndex], points[i]);
                swapIndex++;
            }
        }
        // Move the pivot to its final correct position
        swap(points[swapIndex], points[right]);
        return swapIndex;
    }

    void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
        if (left >= right) return;

        // Partition the array and get the pivot's final index
        int pivotIndex = partition(points, left, right);

        // If the pivot is exactly at k, the first k elements are our answer!
        if (pivotIndex == k) {
            return; 
        } 
        // If pivot is less than k, the k closest points extend into the right half
        else if (pivotIndex < k) {
            quickSelect(points, pivotIndex + 1, right, k);
        } 
        // If pivot is greater than k, the k closest points are trapped in the left half
        else {
            quickSelect(points, left, pivotIndex - 1, k);
        }
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Run Quick Select to segregate the k closest points to the front
        quickSelect(points, 0, points.size() - 1, k);
        
        // Return a sub-vector containing just the first k elements
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};