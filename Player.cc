#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;


Player::Player(const string& name) : name(name) {}

void Player::placeShips()
{
}

bool Player::takeTurn(Player &opponent)
{
    return false;
}

Board &Player::getBoard()
{
    return board;
}

string Player::getName() const {
    return name;
}

HumanPlayer::HumanPlayer(const string& name) : Player(name) {}

void HumanPlayer::placeShips() {
    cout << name << ", umieść swoje statki:\n";
    for (int size : {1, 1, 1, 1, 2, 2, 2, 3, 3, 4}) {
        int x, y, orientation;
        bool placed = false;
        while (!placed) {
            board.printBoard(true); // Wyświetla planszę przed każdą próbą
            cout<< name << ", podaj współrzędne dla statku o rozmiarze " << size << " (x y): ";
            cin >> x >> y;
            cout << "Podaj orientację (0 - poziomo, 1 - pionowo): ";
            cin >> orientation;

            placed = board.placeShip(x, y, size, orientation == 0);
            if (!placed) {
                cout << "Nie można umieścić statku w tym miejscu. Spróbuj ponownie.\n";
                
            } 
            
        }
        board.printBoard(true);
    }
}

bool HumanPlayer::takeTurn(Player& opponent) {
    bool validShot = false;
    int x, y;
    while (!validShot)
    {
        cout << name << ", podaj współrzędne ataku (x y): ";
    cin >> x >> y;
    // sprzawdzanie czy strzał nie był już wykonany w to pole
        if (opponent.getBoard().hasbeenShotAt(x, y))
        {
            cout << " strzelałeś w to miejsce, spróbuj ponownie. \n";
        }else{
            validShot = true; // pole jest dostepne
        }
        
    }
    return opponent.getBoard().receiveAttack(x, y);
}
    
    
    




AIPlayer::AIPlayer() : Player("AI") {
    srand(time(nullptr));
}

void AIPlayer::placeShips() {
    for (int size : {1, 1, 1, 1, 2, 2, 2, 3, 3, 4}) {
        bool placed = false;
        while (!placed) {
            int x = rand() % 10;
            int y = rand() % 10;
            bool horizontal = rand() % 2 == 0;
            placed = board.placeShip(x, y, size, horizontal);

            
        }
    }
}

bool AIPlayer::takeTurn(Player& opponent) {
    int x = rand() % 10;
    int y = rand() % 10;
    return opponent.getBoard().receiveAttack(x, y);
}