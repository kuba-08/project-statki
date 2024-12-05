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
    cout << name << ", umiesc swoje statki:\n";
    for (int size : {1, 1, 1, 1, 2, 2, 2, 3, 3, 4}) {
        int x, y, orientation;
        bool placed = false;
        board.printBoard(true);
        while (!placed && size == 1)
          {
            cout<< name << ", podaj wspolrzedne dla statku o rozmiarze " << size << " (y x): ";
            cin >> x >> y;
             
             placed = board.placeShip(x, y, size, orientation == 0);
if (!placed)
{
    board.canPlaceShip(x, y, size, orientation);
}

          }
          board.printBoard(true);
          system("cls");
          
        while (!placed) {
          board.printBoard(true);
          
            cout<< name << ", podaj wspolrzedne dla statku o rozmiarze " << size << " (y x): ";
            cin >> x >> y;
            cout << "Podaj orientacje (1 - poziomo, 0 - pionowo): ";
            cin >> orientation;

            placed = board.placeShip(x, y, size, orientation == 0);
            if (!placed) {
                
                board.canPlaceShip(x, y, size, orientation);
                
            } 
            
        
        }
        system("cls");
    }
}

bool HumanPlayer::takeTurn(Player& opponent) {
    bool validShot = false;
    int x, y;
    while (!validShot)
    {
        cout << name << ", podaj wspolrzedne ataku (y x): ";
    cin >> x >> y;
    // sprzawdzanie czy strzał nie był już wykonany w to pole
        if (opponent.getBoard().hasbeenShotAt(x, y))
        {
            cout << " strzelałes w to miejsce, sprobuj ponownie. \n";
        }else if(x > 10 || y > 10){
            cout << " strzelasz po za plansze, sprobuj ponownie. \n";
        }else{
            validShot = true;
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
