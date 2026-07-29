class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> st;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && heights[i] < st.top().second) {
                int h = st.top().second;
                int index = st.top().first;
                st.pop();

                maxArea = max(maxArea, h * (i - index));

                start = index;
            }

            st.push({start, heights[i]});
        }

        int n = heights.size();
        while (!st.empty()) {
            int h = st.top().second;
            int index = st.top().first;
            st.pop();

            maxArea = max(maxArea, h * (n - index));
        }

        return maxArea;
    }
};