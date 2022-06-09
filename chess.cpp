#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;



class keys {
public:
    int x = 9;
    int y = 9;
    int team;
    enum keytypes { king, queen, bishop, knight, rook, pawn, empt };
    keytypes keytype;
    string keyname;
    void move(int i, int j) {
        x = i;
        y = j;
    }
};
class point {
public:
    keys* mohre;
};
class King : public keys {
public:
    King(int t) {
        team = t;
        keytype = king;
        if (team == 1) {
            keyname = "KW";
        }
        else {
            keyname = "KB";
        }
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
        keytype = queen;
        if (team == 1) {
            keyname = "QW";
        }
        else {
            keyname = "QB";
        }
    }
    // int checkmove(int i, int j) {

    // }
};
class Bishop : public keys {
public:
    Bishop(int t) {
        team = t;
        keytype = bishop;
        if (team == 1) {
            keyname = "BW";
        }
        else {
            keyname = "BB";
        }
    }
    // int checkmove(int i, int j) {

    // }
};
class Knight : public keys {
public:
    Knight(int t) {
        team = t;
        keytype = knight;
        if (team == 1) {
            keyname = "NW";
        }
        else {
            keyname = "NB";
        }
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
        keytype = rook;
        if (team == 1) {
            keyname = "RW";
        }
        else {
            keyname = "RB";
        }
    }
    // int checkmove(int i, int j) {


    // }
};
class Pawn : public keys {
public:
    Pawn(int t) {
        team = t;
        keytype = pawn;
        if (team == 1) {
            keyname = "PW";
        }
        else {
            keyname = "PB";
        }
    }
    /*int checkmove(int i, int j) {
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

    }*/
};
class Empty : public keys {
public:
    Empty() {
        team = 0;
        keytype = empt;
        keyname = "--";
    }

};

class defboard {
public:
    defboard() {
        board = new point * [8];
        for (int i = 0; i < 8; i++) {
            board[i] = new point[8];
        }
    }
    point** board;
    void printchess() {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << board[i][j].mohre->keyname << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    void move(int i, int j, int x, int y) {
        if (board[x][y].mohre->team == board[i][j].mohre->team) {
            cout << "Cant do that" << endl;
        }
        else {
            board[i][j].mohre->x = x;
            board[i][j].mohre->y = y;
            board[x][y].mohre = board[i][j].mohre;
            board[i][j].mohre = new Empty;
        }
    }
    // int cellckeck(int i, int j) {
    //     if (board[i][j].keytype == 0) {
    //         return 0;
    //     }
    //     if (board[i][j].team == 1) {
    //         return 1;
    //     }
    //     if (board[i][j].team == 2) {
    //         return 2;
    //     }
    // }

};

int main() {
    cout << " -- starting -- \n";

    defboard mainboard;
    string temp1;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> temp1;
            if (temp1 == "--") {
                mainboard.board[i][j].mohre = new Empty;
            }
            else if (temp1[0] == 'K') {
                if (temp1[1] == 'W') {
                    mainboard.board[i][j].mohre = new King(1);
                }
                else {
                    mainboard.board[i][j].mohre = new King(2);
                }
            }
            else if (temp1[0] == 'Q') {
                if (temp1[1] == 'W') {
                    mainboard.board[i][j].mohre = new Queen(1);
                }
                else {
                    mainboard.board[i][j].mohre = new Queen(2);
                }
            }
            else if (temp1[0] == 'B') {
                if (temp1[1] == 'W') {
                    mainboard.board[i][j].mohre = new Bishop(1);
                }
                else {
                    mainboard.board[i][j].mohre = new Bishop(2);
                }
            }

            else if (temp1[0] == 'N') {
                if (temp1[1] == 'W') {
                    mainboard.board[i][j].mohre = new Knight(1);
                }
                else {
                    mainboard.board[i][j].mohre = new Knight(2);
                }
            }
            else if (temp1[0] == 'R') {
                if (temp1[1] == 'W') {
                    mainboard.board[i][j].mohre = new Rook(1);
                }
                else {
                    mainboard.board[i][j].mohre = new Rook(2);
                }
            }
            else if (temp1[0] == 'P') {
                if (temp1[1] == 'W') {
                    mainboard.board[i][j].mohre = new Pawn(1);
                }
                else {
                    mainboard.board[i][j].mohre = new Pawn(2);
                }
            }
            mainboard.board[i][j].mohre->x = i;
            mainboard.board[i][j].mohre->y = j;
        }
    }
    cout << '\n';
    int temp2[4];
    while (1) {
        for (int i = 0; i < 4; i++) {
            cin >> temp2[i];
        }
        mainboard.move(temp2[0], temp2[1], temp2[2], temp2[3]);
        mainboard.printchess();
    }

    cout << "end of program" << endl;
    return 0;
}
