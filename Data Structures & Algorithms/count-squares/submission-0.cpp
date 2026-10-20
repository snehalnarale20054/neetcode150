#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class CountSquares {
public:
    CountSquares() {
        // Initializes the object
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        x_to_ys[x].insert(y);
        ++point_counts[x][y];
    }
    
    int count(vector<int> point) {
        int result = 0;
        int x1 = point[0];
        int y1 = point[1];
        
        // If there are no other points with the same x-coordinate, no squares can be formed.
        if (x_to_ys.find(x1) == x_to_ys.end()) {
            return 0;
        }
        
        // Iterate over all points sharing the same x-coordinate (vertical partner)
        for (int y2 : x_to_ys[x1]) {
            if (y2 == y1) continue; // Skip the query point itself
            
            int side = abs(y2 - y1);
            
            // Check squares extending to the right (+side)
            int x3 = x1 + side;
            result += point_counts[x1][y2] * point_counts[x3][y1] * point_counts[x3][y2];
            
            // Check squares extending to the left (-side)
            int x4 = x1 - side;
            result += point_counts[x1][y2] * point_counts[x4][y1] * point_counts[x4][y2];
        }
        
        return result;
    }

private:
    // Keeps track of unique y-coordinates for each x-coordinate
    unordered_map<int, unordered_set<int>> x_to_ys;
    
    // Frequency map to handle duplicate points correctly: map[x][y] = count
    unordered_map<int, unordered_map<int, int>> point_counts;
};
