#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <conio.h>

const int WIDTH = 10;
const int HEIGHT = 20;

int grid[HEIGHT][WIDTH] = {0};

struct Point {
    int x, y;
} a[4], b[4];

int figures[7][4] = {
    1,3,5,7, // I
    2,4,5,7, // Z
    3,5,4,6, // S
    3,5,4,7, // T
    2,3,5,7, // L
    3,5,7,6, // J
    2,3,4,5  // O
};

bool check() {
    for (int i = 0; i < 4; i++) {
        if (a[i].x < 0 || a[i].x >= WIDTH || a[i].y >= HEIGHT) return 0;
        else if (grid[a[i].y][a[i].x]) return 0;
    }
    return 1;
}

void draw() {
    system("cls");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid[i][j] == 0) std::cout << ".";
            else std::cout << "#";
        }
        std::cout << "\n";
    }
}

int main() {
    srand(time(0));

    int dx = 0, color = 1, n = rand() % 7;
    bool rotate = 0;
    int timer = 0, delay = 1000;
    bool gameOver = false;

    for (int i = 0; i < 4; i++) {
        a[i].x = figures[n][i] % 2;
        a[i].y = figures[n][i] / 2;
    }

    while (!gameOver) {
        delay = 1000;
        timer++;

        if (_kbhit()) {
            char key = _getch();
            if (key == 'a') dx = -1;
            else if (key == 'd') dx = 1;
            else if (key == 's') delay = 100;
            else if (key == 'w') rotate = true;
        }

        for (int i = 0; i < 4; i++) {
            b[i] = a[i];
            a[i].x += dx;
        }

        if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];

        if (rotate) {
            Point p = a[1];
            for (int i = 0; i < 4; i++) {
                int x = a[i].y - p.y;
                int y = a[i].x - p.x;
                a[i].x = p.x - x;
                a[i].y = p.y + y;
            }
            if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
        }

        if (timer > delay) {
            for (int i = 0; i < 4; i++) {
                b[i] = a[i];
                a[i].y += 1;
            }
            if (!check()) {
                for (int i = 0; i < 4; i++) grid[b[i].y][b[i].x] = color;

                color = 1 + rand() % 7;
                n = rand() % 7;
                for (int i = 0; i < 4; i++) {
                    a[i].x = figures[n][i] % 2;
                    a[i].y = figures[n][i] / 2;
                }

                if (!check()) {
                    gameOver = true;
                    break;
                }
            }
            timer = 0;
        }

        int k = HEIGHT - 1;
        for (int i = HEIGHT - 1; i > 0; i--) {
            int count = 0;
            for (int j = 0; j < WIDTH; j++) {
                if (grid[i][j]) count++;
                grid[k][j] = grid[i][j];
            }
            if (count < WIDTH) k--;
        }

        dx = 0;
        rotate = 0;
        draw();
    }

    std::cout << "Game Over!" << std::endl;
    return 0;
}
