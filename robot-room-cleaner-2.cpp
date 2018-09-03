// https://leetcode.com/problems/robot-room-cleaner/

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    int dir = 0, x = 0, y = 0;
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    unordered_map<int, unordered_map<int, bool>> cleaned;
    
    void cleanRoom(Robot& robot) {
        if (cleaned[x][y]) return;
        cleaned[x][y] = true;
        robot.clean();
        
        for(int i = 0; i < 4; i++){
            if (robot.move()){
                
                x += dx[dir];
                y += dy[dir];
                
                cleanRoom(robot);
                
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                
                x -= dx[dir];
                y -= dy[dir];
            }
            robot.turnRight();
            dir = (dir + 1) % 4;
        }
    }
};
