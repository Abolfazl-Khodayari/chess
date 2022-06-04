#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class defboard{
public:
    string board[8][8];
    void getchess() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> board[i][j];
            }
        }
    }
    void printchess() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << board[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    int cellckeck(int i, int j) {
        if (board[i][j] == "--") {
            return 0;
        }
        if (board[i][j][1] == 'W') {
            return 1;
        }
        if (board[i][j][1] == 'B') {
            return 2;
        }
    }
};

class keys {
    public:
        int x = 9;
        int y = 9;
        int team;
        keys (int t) {
            team = t;
        }
        void move(int i, int j) {
            x = i;
            y = j;
        }
};
class King : public keys {
    public:
        int checkmove(int i, int j) {
            if (board.cellckeck(i, j) == team) {
                return 0;
            }
            if (abs(x - i) = 1 || abs(y - j) = 1) {
                return 1;
            }
            retutn 0;
        }
};
class Queen : public keys {
public:
    int checkmove(int i, int j) {
        if (board.cellckeck(i, j) == team) {
            return 0;
        }
    }
};
class Bishop : public keys {
public:
    int checkmove(int i, int j) {
        if (board.cellckeck(i, j) == team) {
            return 0;
        }
    }
};
class Knight : public keys {
public:
    int checkmove(int i, int j) {
        if (board.cellckeck(i, j) == team) {
            return 0;
        }
        if ((abs(i * j) == 2)  {
            return 1;
        }
    }
};
class Rook : public keys {
public:
    int checkmove(int i, int j) {
        if (board.cellckeck(i, j) == team) {
            return 0;
        }

    }
};
class Pawn : public keys {
public:
    int checkmove(int i, int j) {
        if (board.cellckeck(i, j) == team) {
            return 0;
        }
        if (abs(x - i) == 1 && (y - j) == 1) {
            if (board.cellckeck(i, j) == 0) {
                return 0;
            }
        }
        if (abs(x - i) == 0 && (y - j) == 1)
            return 0;

    }
};

int main() {
    cout << " -- starting -- \n";
    defboard board;

    int command = 1;
    while (command != 0) {
        cout << "1: print board \n2: make new board\n0: exit\n";
        cin >> command;
        if (command == 1) {
            board.printchess();
        }
        if (command == 2) {
            board.getchess();
        }
    }
}