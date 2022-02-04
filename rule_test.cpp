#include <bits/stdc++.h>

int liveNeighbors(char grid[10][10], int x, int y) {
    int liveCt = 0;
    if (grid[x-1][y-1] == '*' && x != 0 && y != 0)
        liveCt++;
    if (grid[x-1][y+1] == '*' && x != 0 && y != 9)
        liveCt++;
    if (grid[x+1][y-1] == '*' && x != 9 && y != 0)
        liveCt++;
    if (grid[x+1][y+1] == '*' && x != 9 && y != 9)
        liveCt++;
    if (grid[x][y+1] == '*' && y != 9)
        liveCt++;
    if (grid[x][y-1] == '*' && y != 0)
        liveCt++;
    if (grid[x+1][y] == '*' && x != 9)
        liveCt++;
    if (grid[x-1][y] == '*' && x != 0)
        liveCt++;
    return liveCt;
}

void nextStep(char grid[10][10]) {
    bool change[10][10]; 
    for(size_t i = 0; i < 10; i++) {
        for(size_t j = 0; j < 10; j++) {
            change[i][j]=false;
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int liveNeighborsCt = liveNeighbors(grid, i, j);
            int deadNeighborsCt = 8 - liveNeighborsCt;

            if (grid[i][j] == ' ' && liveNeighborsCt == 3)
                change[i][j] = true;
            if (grid[i][j] == '*' && (liveNeighborsCt >= 4 || liveNeighborsCt <= 1))
                change[i][j] = true;
        }
    }

    for(size_t i = 0; i < 10; i++) {
        for(size_t j = 0; j < 10; j++) {
            if (change[i][j] == true) {
                if (grid[i][j] == '*')
                    grid[i][j] = ' ';
                else grid[i][j] = '*';
            }
        }
    }
}

int main(void)
{
    char array[10][10];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            array[i][j] = ' ';
        }
    }

    array[5][4] = '*';
    array[5][5] = '*';
    array[4][6] = '*';
    array[4][5] = '*';
    array[6][5] = '*';

    std::cout << "Initial:" << std::endl;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++ j) {
            std::cout << array[i][j];
        }
        std::cout << std::endl;
    }
    
    for (int k = 0; k < 50; ++k) {
        nextStep(array);
        
        std::cout << "Next:" << std::endl;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++ j) {
                std::cout << array[i][j];
            }
            std::cout << std::endl;
        }
        // system("clear");
    }
    return 0;
}
