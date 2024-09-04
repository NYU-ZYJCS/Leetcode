class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obstacleSet;
        for (auto& obstacle : obstacles) {
            obstacleSet.insert(helper(obstacle));
        }
        
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> cur_position = {0, 0};
        int max_distance = 0;
        int cur_direction = 0;
        
        for (int command : commands) {
            if (command == -1) {
                cur_direction = (cur_direction + 1) % 4;
                continue;
            } else if (command == -2) {
                cur_direction = (cur_direction + 3) % 4;
                continue;
            } else {
                while (command--) {
                    vector<int> next_position = cur_position;
                    next_position[0] += directions[cur_direction][0];
                    next_position[1] += directions[cur_direction][1];
                    if (obstacleSet.contains(helper(next_position))) continue;
                    cur_position = next_position;
                }
                
                max_distance = max(max_distance, get_distance(cur_position));
            }
        }
        return max_distance;
    }
    
    string helper(vector<int>& position) {
        return to_string(position[0]) + " " + to_string(position[1]);
    }
    
    int get_distance(vector<int>& position) {
        return position[0] * position[0] + position[1] * position[1];
    }
};