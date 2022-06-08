#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class defboard{
    public:
        keys board[8][8];
        /*
        void printchess() {
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    cout << board[i][j] << " ";
                }
                cout << '\n';
            }
            cout << '\n';
        }
        */
        int cellckeck(int i, int j) {
            if (board[i][j].keytype == 0) { 
                return 0;
            }
            if (board[i][j].team == 'W') {
                return 1;
            }
            if (board[i][j].team == 'B') {
                return 2;
            }
        }
};

class keys {
    public:
        int x = 9;
        int y = 9;
        int team;
        int keytype;
        void move(int i, int j) {
            x = i;
            y = j;
        }
};
class King : public keys {
    public:
        King(int t) {
            team = t;
        }
        int checkmove(int i, int j) {
            if (abs(x - i) == 1 || abs(y - j) == 1) {
                return 1;
            }
            return 0;
        }
};
class Queen : public keys {
public:
    Queen(int t) {
        team = t;
    }
    int checkmove(int i, int j) {

    }
};
class Bishop : public keys {
public:
    Bishop(int t) {
        team = t;
    }
    int checkmove(int i, int j) {

    }
};
class Knight : public keys {
public:
    Knight(int t) {
        team = t;
    }
    int checkmove(int i, int j) {
        if ((abs(i * j) == 2)) {
            return 1;
        }
    }
};
class Rook : public keys {
public:
    Rook(int t) {
        team = t;
    }
    int checkmove(int i, int j) {


    }
};
class Pawn : public keys {
public:
    Pawn(int t) {
        team = t;
    }
    int checkmove(int i, int j) {
        /*if (board.cellckeck(i, j) == team) {
            return 0;
        }
        if (abs(x - i) == 1 && (y - j) == 1) {
            if (board.cellckeck(i, j) == 0) {
                return 0;
            }
        }
        if (abs(x - i) == 0 && (y - j) == 1)
            return 0;
        */
    }
};

int main() {
    cout << " -- starting -- \n";
    defboard board;
    string temp1;
    int bbishab = 0, bknight = 0, brook = 0, bpawn = 0;
    int wbishab = 0, wknight = 0, wrook = 0, wpawn = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> temp1;
            if (temp1 == "--") {
                board.board[i][j].keytype = 0;
            }
            else if (temp1[0] == 'K') {
                if (temp1[1] == 'W') {
                    King Wking(1);
                    board.board[i][j] = Wking;
                }
                else {
                    King Bking(2);
                    board.board[i][j] = Bking;
                }
            }
            else if (temp1[0] == 'Q') {
                if (temp1[1] == 'W') {
                    Queen Wqueen(1);
                    board.board[i][j] = Wqueen;
                }
                else {
                    Queen Bqueen(1);
                    board.board[i][j] = Bqueen;
                }
            }
            else if (temp1[0] == 'B') {
                if (temp1[1] == 'W') {
                    if (wbishab == 0) {
                        Bishop Wbishab1(1);
                        board.board[i][j] = Wbishab1;
                        wbishab++;
                    }
                    else {
                        Bishop Wbishab2(1);
                        board.board[i][j] = Wbishab2;
                        wbishab++;
                    }
                }
                else {
                    if (bbishab == 0) {
                        Bishop Bbishab1(1);
                        board.board[i][j] = Bbishab1;
                        bbishab++;
                    }
                    else {
                        Bishop Bbishab2(1);
                        board.board[i][j] = Bbishab2;
                        bbishab++;
                    }
                }
            }
            else if (temp1[0] == 'N') {
                if (temp1[1] == 'W') {
                    if (wknight == 0) {
                        Knight Wknight1(1);
                        board.board[i][j] = Wknight1;
                        wknight++;
                    }
                    else {
                        Knight Wknight2(1);
                        board.board[i][j] = Wknight2;
                        wknight++;
                    }
                }
                else {
                    if (bknight == 0) {
                        Knight Bknight1(1);
                        board.board[i][j] = Bknight1;
                        bknight++;
                    }
                    else {
                        Knight Bknight2(1);
                        board.board[i][j] = Bknight2;
                        bknight++;
                    }
                }
            }
            else if (temp1[0] == 'R') {
                if (temp1[1] == 'W') {
                    if (wrook == 0) {
                        Rook Wrook1(1);
                        board.board[i][j] = Wrook1;
                        wrook++;
                    }
                    else {
                        Rook Wrook2(1);
                        board.board[i][j] = Wrook2;
                        wrook++;
                    }
                }
                else {
                    if (brook == 0) {
                        Rook Brook1(1);
                        board.board[i][j] = Brook1;
                        brook++;
                    }
                    else {
                        Rook Brook2(1);
                        board.board[i][j] = Brook2;
                        brook++;
                    }
                }
            }
            else if (temp1[0] == 'P') {
                if (temp1[1] == 'W') {
                    if (wpawn == 0) {
                        Pawn Wpawn1(1);
                        board.board[i][j] = Wpawn1;
                        wpawn++;
                    }
                    else if (wpawn == 1) {
                        Pawn Wpawn2(1);
                        board.board[i][j] = Wpawn2;
                        wpawn++;
                    }
                    else if (wpawn == 2) {
                        Pawn Wpawn3(1);
                        board.board[i][j] = Wpawn3;
                        wpawn++;
                    }
                    else if (wpawn == 3) {
                        Pawn Wpawn4(1);
                        board.board[i][j] = Wpawn4;
                        wpawn++;
                    }
                    else if (wpawn == 4) {
                        Pawn Wpawn5(1);
                        board.board[i][j] = Wpawn5;
                        wpawn++;
                    }
                    else if (wpawn == 5) {
                        Pawn Wpawn6(1);
                        board.board[i][j] = Wpawn6;
                        wpawn++;
                    }
                    else if (wpawn == 6) {
                        Pawn Wpawn7(1);
                        board.board[i][j] = Wpawn7;
                        wpawn++;
                    }
                    else if (wpawn == 7) {
                        Pawn Wpawn8(1);
                        board.board[i][j] = Wpawn8;
                        wpawn++;
                    }
                }
                else {
                    if (bpawn == 0) {
                        Pawn Bpawn1(1);
                        board.board[i][j] = Bpawn1;
                        bpawn++;
                    }
                    else if (bpawn == 1) {
                        Pawn Bpawn2(1);
                        board.board[i][j] = Bpawn2;
                        bpawn++;
                    }
                    else if (bpawn == 2) {
                        Pawn Bpawn3(1);
                        board.board[i][j] = Bpawn3;
                        bpawn++;
                    }
                    else if (bpawn == 3) {
                        Pawn Bpawn4(1);
                        board.board[i][j] = Bpawn4;
                        bpawn++;
                    }
                    else if (bpawn == 4) {
                        Pawn Bpawn5(1);
                        board.board[i][j] = Bpawn5;
                        bpawn++;
                    }
                    else if (bpawn == 5) {
                        Pawn Bpawn6(1);
                        board.board[i][j] = Bpawn6;
                        bpawn++;
                    }
                    else if (bpawn == 6) {
                        Pawn Bpawn7(1);
                        board.board[i][j] = Bpawn7;
                        bpawn++;
                    }
                    else if (bpawn == 7) {
                        Pawn Bpawn8(1);
                        board.board[i][j] = Bpawn8;
                        bpawn++;
                    }
                }

            }
        }
    }


    int command = 1;
    while (command != 0) {
        cout << "1: print board \n2: make new board\n0: exit\n";
        cin >> command;
    }
}