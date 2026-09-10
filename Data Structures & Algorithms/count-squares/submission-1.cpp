class CountSquares {
private:
    vector<pair<int, int>> ptsList;
    unordered_map<string, int> ptsCount;

    string getKey(int x, int y) {
        return to_string(x) + "," + to_string(y);
    }

public:
    CountSquares() {}
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        
        ptsList.push_back({x, y});
        ptsCount[getKey(x, y)]++;
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int res = 0;
        
        for (auto& p3 : ptsList) {
            int x3 = p3.first;
            int y3 = p3.second;
            
            if (abs(x1 - x3) == abs(y1 - y3) && x1 != x3) {
                
                string p2 = getKey(x1, y3);
                string p4 = getKey(x3, y1);
                
                res += ptsCount[p2] * ptsCount[p4];
            }
        }
        
        return res;
    }
};