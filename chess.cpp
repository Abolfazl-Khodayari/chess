#include <iostream>
#include <string>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class keys {
public:
    int x = 9;
    int y = 9;
    int team;
    Texture texturekey;
    Sprite spritekey;
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
            texturekey.loadFromFile("texture/set/wking.png", IntRect(0, 0, 75, 75));
        }
        else {
            texturekey.loadFromFile("texture/set/bking.png", IntRect(0, 0, 75, 75));
            keyname = "KB";
        }
        spritekey.setTexture(texturekey);
        spritekey.setPosition(Vector2f((x * 75), (y * 75)));

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
            texturekey.loadFromFile("texture/set/wqueen.png", IntRect(0, 0, 75, 75));
        }
        else {
            keyname = "QB";
            texturekey.loadFromFile("texture/set/bqueen.png", IntRect(0, 0, 75, 75));
        }
        spritekey.setTexture(texturekey);
        spritekey.setPosition(Vector2f((x * 75), (y * 75)));
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
            texturekey.loadFromFile("texture/set/wbishop.png", IntRect(0, 0, 75, 75));
        }
        else {
            keyname = "BB";
            texturekey.loadFromFile("texture/set/bbishop.png", IntRect(0, 0, 75, 75));
        }
        spritekey.setTexture(texturekey);
        spritekey.setPosition(Vector2f((x * 75), (y * 75)));
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
            texturekey.loadFromFile("texture/set/wknight.png", IntRect(0, 0, 75, 75));
        }
        else {
            keyname = "NB";
            texturekey.loadFromFile("texture/set/bknight.png", IntRect(0, 0, 75, 75));
        }
        spritekey.setTexture(texturekey);
        spritekey.setPosition(Vector2f((x * 75), (y * 75)));
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
            texturekey.loadFromFile("texture/set/wrook.png", IntRect(0, 0, 75, 75));
        }
        else {
            keyname = "RB";
            texturekey.loadFromFile("texture/set/brook.png", IntRect(0, 0, 75, 75));
        }
        spritekey.setTexture(texturekey);
        spritekey.setPosition(Vector2f((x * 75), (y * 75)));
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
            texturekey.loadFromFile("texture/set/wpawn.png", IntRect(0, 0, 75, 75));
        }
        else {
            keyname = "PB";
            texturekey.loadFromFile("texture/set/bpawn.png", IntRect(0, 0, 75, 75));
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
class GraphicCore {
public:
    void runGraphic(point** myboard) {
        RenderWindow window(VideoMode(600, 600), "Hi Sina", Style::Titlebar | Style::Close);
        //CircleShape shape(50);
        window.setFramerateLimit(60);
        Texture textureboard;
        textureboard.loadFromFile("texture/set/boardblue.jpg", IntRect(0, 0, 600, 600));
        Sprite spriteboard;
        spriteboard.setTexture(textureboard);
        //RectangleShape rectangle(Vector2f(120, 50));
        //RectangleShape shape(50);
        Texture temp4;
        Sprite temp4sprite;
        //cout << myboard[0][0].mohre->keyname << endl;
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
                if (event.type == Event::Closed)
                    window.close();
            window.clear();
            window.draw(spriteboard);
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (myboard[i][j].mohre->keyname != "--") {
                        temp4 = myboard[i][j].mohre->texturekey;
                        temp4sprite.setTexture(temp4);
                        temp4sprite.setPosition(Vector2f((j * 75), (i * 75)));
                        window.draw(temp4sprite);
                    }
                }
            }
            window.display();
        }
    }

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
    GraphicCore maingraphics;
    maingraphics.runGraphic(mainboard.board);
    int temp2[4];
    cout << "Enter the key origin and destination. for example: i j x y" << endl;
    while (1) {
        for (int i = 0; i < 4; i++) {
            cin >> temp2[i];
        }
        cout << "Enter the key origin and destination. for example: i j x y" << endl;
        mainboard.move(temp2[0] - 1, temp2[1] - 1, temp2[2] - 1, temp2[3] - 1);
        mainboard.printchess();
        maingraphics.runGraphic(mainboard.board);
    }
    cout << "end of program" << endl;
    return 0;
}