#include <iostream>
#include "table.h"
#include <conio.h>
using namespace std;


class Players{
private:
    string player1;
    string player2;
    int turn;
    bool win;
public:
    Players(){
        player1 = "X";
        player2 = "O";
        turn = 1;
        win = false;
    }
    bool getWin(){
        return win;
    }
    int getTurn(){
        return turn;
    }
    void setTurn(int n){
        this->turn = n;
    }
    void setMark(int turn){
        this->turn = turn;
    }
    string getMark(){
        if(turn==2)
            return player1;
        if(turn==1)
            return player2;
    }
    string checkWin(int n){
        if(table[0][0]=="X" && table[0][1]=="X" && table[0][2]=="X"){
            win = true;
            return player1;
        }
        if(table[1][0]=="X" && table[1][1]=="X" && table[1][2]=="X"){
            win = true;
            return player1;
        }
        if(table[2][0]=="X" && table[2][1]=="X" && table[2][2]=="X"){
            win = true;
            return player1;
        }
        if(table[0][0]=="X" && table[1][0]=="X" && table[2][0]=="X"){
            win = true;
            return player1;
        }
        if(table[0][1]=="X" && table[1][1]=="X" && table[2][1]=="X"){
            win = true;
            return player1;
        }
        if(table[0][2]=="X" && table[1][2]=="X" && table[2][2]=="X"){
            win = true;
            return player1;
        }
        if(table[2][0]=="X" && table[1][1]=="X" && table[0][2]=="X"){
            win = true;
            return player1;
        }
        if(table[0][0]=="X" && table[1][1]=="X" && table[2][2]=="X"){
            win = true;
            return player1;
        }
        //player2:
        if(table[0][0]=="O" && table[0][1]=="O" && table[0][2]=="O"){
            win = true;
            return player2;
        }
        if(table[1][0]=="O" && table[1][1]=="O" && table[1][2]=="O"){
            win = true;
            return player2;
        }
        if(table[2][0]=="O" && table[2][1]=="O" && table[2][2]=="O"){
            win = true;
            return player2;
        }
        if(table[0][0]=="O" && table[1][0]=="O" && table[2][0]=="O"){
            win = true;
            return player2;
        }
        if(table[0][1]=="O" && table[1][1]=="O" && table[2][1]=="O"){
            win = true;
            return player2;
        }
        if(table[0][2]=="O" && table[1][2]=="O" && table[2][2]=="O"){
            win = true;
            return player2;
        }
        if(table[2][0]=="O" && table[1][1]=="O" && table[0][2]=="O"){
            win = true;
            return player2;
        }
        if(table[0][0]=="O" && table[1][1]=="O" && table[2][2]=="O"){
            win = true;
            return player2;
        }
        if(n==9){
            win = true;
            return "non";
        }
    }
};


void playing(Players& player, int& n){
    int choice;
    int turn = player.getTurn();
    if(turn==2){
        player.setTurn(1);
    }else{
        player.setTurn(2);
    }
    bool start = true;
    while(start && n<=9){
    cin >> choice;
    switch(choice){
    case 1:
        if(table[0][0]=="X" || table[0][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][0] = player.getMark();
            n++;
            start = false;
        }
        break;
    case 2:
        if(table[0][1]=="X" || table[0][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][1] = player.getMark();
            n++;
            start = false;
        }
        break;
    case 3:
        if(table[0][2]=="X" || table[0][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][2] = player.getMark();
            n++;
            start = false;
        }
        break;
    case 4:
        if(table[1][0]=="X" || table[1][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][0] = player.getMark();
            n++;
            start = false;
        }
        break;
    case 5:
        if(table[1][1]=="X" || table[1][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][1] = player.getMark();
            n++;
            start = false;
        }
        break;
    case 6:
        if(table[1][2]=="X" || table[1][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][2] = player.getMark();
            n++;
            start = false;
        }
        break;
    case 7:
        if(table[2][0]=="X" || table[2][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][0] = player.getMark();
            n++;
            start = false;
        }
        break;
    case 8:
        if(table[2][1]=="X" || table[2][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][1] = player.getMark();
            n++;
            start = false;
        }
        break;
    case 9:
        if(table[2][2]=="X" || table[2][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][2] = player.getMark();
            n++;
            start = false;
        }
        break;
    }
    }
}

int main()
{
    system("color 3");
    bool start = true;
    while(start){
        int option;
        cout << "1-start a New Game\n2- Stop The Game\n";
        cin >> option;
        switch(option){
        case 1:{
            createTable();
            Players play = Players();
            int n = 0;
            while(!play.getWin()){
                system("cls");
                showTable();
                playing(play, n);
                play.checkWin(n);
            }
            system("cls");
            showTable();
            string winner = play.checkWin(n);
            if(winner=="X"){
                winner = "Player 1";
            }else if(winner=="O"){
                winner = "player 2";
            }else if(n==9){
                cout << "No one win This game\n";
                cout << "Press any Key to back\n";
                getch();
                break;
            }
            cout << "------------------- Congratulation for " << winner << " For Winning The game \n";
            cout << "Click anything to Back to Main Menu\n";
            getch();
            system("cls");
            break;
        }
        case 2:
            start = false;
            break;
        }
    }
    return 0;
}
