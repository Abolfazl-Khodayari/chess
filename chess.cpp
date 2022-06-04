#include <iostream>
#include <string>
using namespace std;
class defboard{
public:
    string board[8][8] = { "--" };
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
};

class keys {
    public:
        sdwdacx m,/
};
int main() {
    defboard board;
    cout << " -- starting -- \n";
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