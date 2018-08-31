// https://leetcode.com/problems/robot-room-cleaner/description/

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
private:
    int x = 0, y = 0, dir = 0;
    vector<int> dx = {1, 0 , -1, 0}, dy = {0, 1, 0, -1};
    unordered_map<int, unordered_map<int, int>> data;
    
public:
    void cleanRoom(Robot& robot) {
        if (data[x][y] == 1) return;
        
        robot.clean();
        data[x][y] = 1;
        
        for(int i = 0; i < 4; i++){
            if (robot.move()){
                x += dx[dir]; y += dy[dir];
                cleanRoom(robot);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
                x -= dx[dir]; y -= dy[dir];
            }
            dir = (dir + 1) % 4;
            robot.turnRight();
        }
    }
};
