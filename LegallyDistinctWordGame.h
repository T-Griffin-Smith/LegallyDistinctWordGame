#include "WindowManager.cpp"

class Tile {
    private:
        char p_letter;
        uint8_t p_value;
        uint8_t p_posX;
        uint8_t p_posY;
        uint8_t p_playerID;

    public:
        // Constructor
        Tile(char letter = ' ', uint8_t value = 0, uint8_t posX = 255, uint8_t posY = 255, uint8_t playerID = 0) {
            p_letter = letter;
            p_value = value;
            p_posX = posX;
            p_posY = posY;
            p_playerID = playerID;
        };

        // Getters
        char g_GetLetter() {

        };

        uint8_t g_GetValue() {

        };

        uint8_t g_GetPosX() {

        };

        uint8_t g_GetPosY() {

        };

        uint8_t g_GetPlayerID() {

        };

        // Setters

};

class TileBag {
    private:
        int p_BagCount = 100;
        Tile p_Bag[100] = {
            {'A', 1, 15, 15, 0}, {'A', 1, 15, 15, 0}, {'A', 1, 15, 15, 0}, {'A', 1, 15, 15, 0}, {'A', 1, 15, 15, 0}, {'A', 1, 15, 15, 0}, {'A', 1, 15, 15, 0}, {'A', 1, 15, 15, 0},
            {'B', 3, 15, 15, 0}, {'B', 3, 15, 15, 0},
            {'C', 3, 15, 15, 0}, {'C', 3, 15, 15, 0},
            {'D', 2, 15, 15, 0}, {'D', 2, 15, 15, 0}, {'D', 2, 15, 15, 0}, {'D', 2, 15, 15, 0},
            {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, {'E', 1, 15, 15, 0}, 
            {'F', 4, 15, 15, 0}, {'F', 4, 15, 15, 0},
            {'G', 2, 15, 15, 0}, {'G', 2, 15, 15, 0}, {'G', 2, 15, 15, 0},
            {'H', 4, 15, 15, 0}, {'H', 4, 15, 15, 0},
            {'I', 1, 15, 15, 0}, {'I', 1, 15, 15, 0}, {'I', 1, 15, 15, 0}, {'I', 1, 15, 15, 0}, {'I', 1, 15, 15, 0}, {'I', 1, 15, 15, 0}, {'I', 1, 15, 15, 0}, {'I', 1, 15, 15, 0},
            {'J', 8, 15, 15, 0},
            {'K', 5, 15, 15, 0},
            {'L', 1, 15, 15, 0}, {'L', 1, 15, 15, 0}, {'L', 1, 15, 15, 0}, {'L', 1, 15, 15, 0},
            {'M', 3, 15, 15, 0}, {'M', 3, 15, 15, 0},
            {'N', 1, 15, 15, 0}, {'N', 1, 15, 15, 0}, {'N', 1, 15, 15, 0}, {'N', 1, 15, 15, 0}, {'N', 1, 15, 15, 0}, {'N', 1, 15, 15, 0},
            {'O', 1, 15, 15, 0}, {'O', 1, 15, 15, 0}, {'O', 1, 15, 15, 0}, {'O', 1, 15, 15, 0}, {'O', 1, 15, 15, 0}, {'O', 1, 15, 15, 0}, {'O', 1, 15, 15, 0}, {'O', 1, 15, 15, 0},
            {'P', 3, 15, 15, 0}, {'P', 3, 15, 15, 0},
            {'Q', 10, 15, 15, 0},
            {'R', 1, 15, 15, 0}, {'R', 1, 15, 15, 0}, {'R', 1, 15, 15, 0}, {'R', 1, 15, 15, 0}, {'R', 1, 15, 15, 0}, {'R', 1, 15, 15, 0},
            {'S', 1, 15, 15, 0}, {'S', 1, 15, 15, 0}, {'S', 1, 15, 15, 0}, {'S', 1, 15, 15, 0},
            {'T', 1, 15, 15, 0}, {'T', 1, 15, 15, 0}, {'T', 1, 15, 15, 0}, {'T', 1, 15, 15, 0}, {'T', 1, 15, 15, 0}, {'T', 1, 15, 15, 0},
            {'U', 1, 15, 15, 0}, {'U', 1, 15, 15, 0}, {'U', 1, 15, 15, 0}, {'U', 1, 15, 15, 0},
            {'V', 4, 15, 15, 0}, {'V', 4, 15, 15, 0},
            {'W', 4, 15, 15, 0}, {'W', 4, 15, 15, 0},
            {'X', 8, 15, 15, 0},
            {'Y', 4, 15, 15, 0}, {'Y', 4, 15, 15, 0},
            {'Z', 10, 15, 15, 0},
            {' ', 0, 15, 15, 0}, {' ', 0, 15, 15, 0} // Blank tiles
        };

    public:
        // Constructor & Destructor
        TileBag() {

        };

        ~TileBag() {

        };

        int g_GetBagCount() {
            return p_BagCount;
        }

        Tile g_GetTile(int index) {
            if (index < 0 || index >= p_BagCount) {
                printf("Error: Tile index out of bounds!\n");
                return Tile(); // Return default Tile if out of bounds
            }
            return p_Bag[index];
        }

        Tile g_RemoveTile(int index) {
            if (index < 0 || index >= p_BagCount) {
                printf("Error: Tile index out of bounds!\n");
                return Tile();
            }
            Tile drawn = p_Bag[index]; // Save selected tile
            p_Bag[index] = p_Bag[p_BagCount - 1]; // Move last available tile forward
            p_Bag[p_BagCount - 1] = drawn; // Move drawn tile out of bounds
            p_BagCount--;
            return drawn;
        }
        
};

class Board {
    private:

    public:
        // Constructor & Destructor
        // Destructor for new games? or just clear board
        Board() {
            Tile g_board[15][15];
        };

        ~Board(){
            
        };

};

class Player {
    private:
        Tile p_Rack[7];
        uint8_t p_RackTileCount;
        uint16_t p_PlayerScore;

    public:
        // Change tile's X and Y position to map to board
        int g_PlaceTile() {

        };

        // Change tile's X and Y position to map to rack
        int g_WithdrawTile() {

        };

        // Commit word tiles
        int g_PlayWord() {

        };

        // Draw a tile from the bag
        int g_DrawTile(TileBag Bag) {

            int BagCount = Bag.g_GetBagCount();

            if (BagCount == 0) {
                printf("No more tiles!\n");
                return -1;
            };
            
            if (p_RackTileCount >= 7) {
                printf("You already have 7 tiles!\n");
                return -1;
            };

            int index = rand() % BagCount; // Pick a random tile
            p_Rack[p_RackTileCount] = Bag.g_RemoveTile(index); // Add tile to rack
            return 0;

        };

};