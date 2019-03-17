typedef pair<int,int> pii;
typedef vector<pii> vpii;

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        dirs = {{"U", {-1, 0}}, {"L", {0, -1}}, {"R", {0, 1}}, {"D", {1, 0}}};
        snakeBody.push_front(0);
        occupiedBlocks.insert(0);
        foodIdx = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        pii currPos = getHead(), nextPos = addOffset(currPos, dirs[direction]);
        
        // Check if the current move makes snake go out of bound
        if (!checkInBound(nextPos)){
            return -1;
        }
        

        if (foodIdx < food.size() && checkSameCoords(nextPos, food[foodIdx])){
            foodIdx++;
        } else {
            removeBack();
        }
        if (checkBodyOverlap(nextPos)) return -1;
        
        insertBlock(nextPos);
        return getScore();
    }
    
private:
    unordered_map<string, pii> dirs;
    unordered_set<int> occupiedBlocks;
    deque<int> snakeBody;
    vpii food;
    int width, height, foodIdx;
    
    bool checkInBound(pii& coords){
        int x = get<0>(coords), y = get<1>(coords);
        return x >= 0 && y >= 0 && x < height && y < width;
    }
    
    pii addOffset(pii& p1, pii& p2){
        return {p1.first + p2.first, p1.second + p2.second};
    }
    
    bool checkBodyOverlap(pii& coords){
        int hash = getHash(coords);
        return occupiedBlocks.count(hash);
    }
    
    bool checkSameCoords(pii& p1, pii& p2){
        return get<0>(p1) == get<0>(p2) && get<1>(p2) == get<1>(p1);
    }
    
    int getHash(pii& coords){
        int x = get<0>(coords), y = get<1>(coords);
        return x*width + y;
    }
    
    pii getCoords(int hash){
        int y = hash % width;
        return {(hash - y)/width, y};
    }
    
    pii getHead(){
        return getCoords(snakeBody.front());
    }
    
    int getScore(){
        return snakeBody.size() - 1;
    }
    void insertBlock(pii& coords){
        int hash = getHash(coords);
        snakeBody.push_front(hash);
        occupiedBlocks.insert(hash);
    }
    
    void removeBack(){
        auto hash = snakeBody.back();
        snakeBody.pop_back();
        occupiedBlocks.erase(hash);
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
