#include <iostream>
#include "table.h"
#include <conio.h>
using namespace std;
string player = "O", opponent = "X";
struct AImove{
    int i, j;
};
AImove findBestMove(string table[3][3]);
int evaluate(string table[3][3]);

void copyTable(string temptable[3][3]);

class Players{
private:
    string player1;
    string player2;
    string AI;
    int AIturn;
    int turn;
    bool win;
public:
    Players(){
        player1="X";
        player2="O";
        AI="O";
        turn = 1;
        win = false;
    }
    bool getWin(){
        return win;
    }
    int getTurn(){
        return turn;
    }
    string getAI(){
        return AI;
    }
    string getPlayer1(){
        return player1;
    }
    string getPlayer2(){
        return player2;
    }
    void setPlayer1(string p1){
        this->player1 = p1;
    }
    void setAI(string AI){
        this->AI = AI;
    }
    void setPlayer2(string p2){
        this->player2 = p2;
    }
    void setTurn(int n){
        this->turn = n;
    }
    void setAIturn(int n){
        this->AIturn = n;
    }
    int getAIturn(){
        return AIturn;
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
    string checkWin(){
        for(int i=0;i<3;i++){
            if(table[i][0]!="." && table[i][0]==table[i][1] && table[i][1]==table[i][2]){
                win = true;
                if(table[i][0]==player1)
                    return player1;
                else
                    return player2;
            }
        }
        for(int i=0;i<3;i++){
            if(table[0][i]!="." && table[0][i]==table[1][i] && table[1][i]==table[2][i]){
                win = true;
                if(table[0][i]==player1)
                    return player1;
                else
                    return player2;
            }
        }
        if(table[0][0]!="." && table[0][0]==table[1][1] && table[1][1]==table[2][2]){
            win = true;
            if(table[0][0]==player1)
                return player1;
            else
                return player2;
        }
        if(table[0][2]!= "." && table[0][2]==table[1][1] && table[1][1]==table[2][0]){
            win = true;
            if(table[0][2]==player1)
                return player1;
            else
                return player2;
        }
        return "non";
        }
};


void playingAI(Players& player){
    int choice;
    bool start = true;
    while(start){
    cin >> choice;
    switch(choice){
    case 1:
        if(table[0][0]=="X" || table[0][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][0] = player.getPlayer1();
            start = false;
        }
        break;
    case 2:
        if(table[0][1]=="X" || table[0][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][1] = player.getPlayer1();
            start = false;
        }
        break;
    case 3:
        if(table[0][2]=="X" || table[0][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][2] = player.getPlayer1();
            start = false;
        }
        break;
    case 4:
        if(table[1][0]=="X" || table[1][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][0] = player.getPlayer1();
            start = false;
        }
        break;
    case 5:
        if(table[1][1]=="X" || table[1][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][1] = player.getPlayer1();
            start = false;
        }
        break;
    case 6:
        if(table[1][2]=="X" || table[1][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][2] = player.getPlayer1();
            start = false;
        }
        break;
    case 7:
        if(table[2][0]=="X" || table[2][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][0] = player.getPlayer1();
            start = false;
        }
        break;
    case 8:
        if(table[2][1]=="X" || table[2][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][1] = player.getPlayer1();
            start = false;
        }
        break;
    case 9:
        if(table[2][2]=="X" || table[2][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][2] = player.getPlayer1();
            start = false;
        }
        break;
    }
    }
}

void playing(Players& player){
    int choice;
    int turn = player.getTurn();
    if(turn==2){
        player.setTurn(1);
    }else{
        player.setTurn(2);
    }
    bool start = true;
    while(start){
    cin >> choice;
    switch(choice){
    case 1:
        if(table[0][0]=="X" || table[0][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][0] = player.getMark();
            start = false;
        }
        break;
    case 2:
        if(table[0][1]=="X" || table[0][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][1] = player.getMark();
            start = false;
        }
        break;
    case 3:
        if(table[0][2]=="X" || table[0][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[0][2] = player.getMark();
            start = false;
        }
        break;
    case 4:
        if(table[1][0]=="X" || table[1][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][0] = player.getMark();
            start = false;
        }
        break;
    case 5:
        if(table[1][1]=="X" || table[1][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][1] = player.getMark();
            start = false;
        }
        break;
    case 6:
        if(table[1][2]=="X" || table[1][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[1][2] = player.getMark();
            start = false;
        }
        break;
    case 7:
        if(table[2][0]=="X" || table[2][0] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][0] = player.getMark();
            start = false;
        }
        break;
    case 8:
        if(table[2][1]=="X" || table[2][1] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][1] = player.getMark();
            start = false;
        }
        break;
    case 9:
        if(table[2][2]=="X" || table[2][2] == "O")
            cout << "error, the place already taken\n";
        else{
            table[2][2] = player.getMark();
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
        cout << "1-start a New Game\n2-Play Vs AI\n3- Stop The Game\n";
        cin >> option;
        switch(option){
        case 1:{
            createTable();
            int playerchoix;
            cout << "1 for X\n2 for O\n";
            cin >> playerchoix;
            Players play = Players();
            if(playerchoix==2){
                play.setPlayer1("O");
                play.setPlayer2("X");
            }
            while(!play.getWin()){
                system("cls");
                showTable();
                playing(play);
                play.checkWin();
                if(!isMovesLeft(table))
                    break;
            }
            system("cls");
            showTable();
            string winner = play.checkWin();
            if(winner=="non"){
                cout << "No one win This game\n";
                cout << "Press any Key to back\n";
                getch();
                break;
            }
            if(winner==play.getPlayer1()){
                winner = "Player 1";
            }else{
                winner = "Player 2";
            }
            cout << "------------------- Congratulation for " << winner << " For Winning The game \n";
            cout << "Click anything to Back to Main Menu\n";
            getch();
            system("cls");
            break;
        }
        case 2:
            {
    //AI--------------------------------------------------------


            string temptable[3][3];
            AImove moving;
            createTable();
            int playerchoix;
            cout << "1 for X\n2 for O\n";
            cin >> playerchoix;
            Players play = Players();
            if(playerchoix==2){
                player = "X";
                opponent = "O";
                play.setPlayer1("O");
                play.setAI("X");
            }else{
                player = "O";
                opponent = "X";
            }
            while(!play.getWin()){
                system("cls");
                showTable();
                playingAI(play);
                copyTable(temptable);
                moving = findBestMove(temptable);
                if(isMovesLeft(table)){
                    table[moving.i][moving.j] = play.getAI();
                }
                play.checkWin();
                if(!isMovesLeft(table))
                    break;
            }
            system("cls");
            showTable();
            string winner = play.checkWin();
            if(winner=="non"){
                cout << "No one win This game\n";
                cout << "Press any Key to back\n";
                getch();
                break;
            }
            if(winner==play.getPlayer1()){
                winner = "Player 1";
            }else{
                winner = "AI";
            }
            cout << "------------------- Congratulation for " << winner << " For Winning The game \n";
            cout << "Click anything to Back to Main Menu\n";
            getch();
            system("cls");
            break;
            }
            break;
        case 3:
            start = false;
            break;
        }
    }
    return 0;
}




int evaluate(string table[3][3])
{
    for (int i = 0; i<3; i++)
    {
        if (table[i][0]==table[i][1] &&
            table[i][1]==table[i][2])
        {
            if (table[i][0]==player)
                return +10;
            else if (table[i][0]==opponent)
                return -10;
        }
    }

    for (int col = 0; col<3; col++)
    {
        if (table[0][col]==table[1][col] &&
            table[1][col]==table[2][col])
        {
            if (table[0][col]==player)
                return +10;

            else if (table[0][col]==opponent)
                return -10;
        }
    }

    // Checking for Diagonals for X or O victory.
    if (table[0][0]==table[1][1] && table[1][1]==table[2][2])
    {
        if (table[0][0]==player)
            return +10;
        else if (table[0][0]==opponent)
            return -10;
    }

    if (table[0][2]==table[1][1] && table[1][1]==table[2][0])
    {
        if (table[0][2]==player)
            return +10;
        else if (table[0][2]==opponent)
            return -10;
    }

    // Else if none of them have won then return 0
    return 0;
}



int minimax(string table[3][3], int depth, bool isMax)
{
    int score = evaluate(table);

    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;

    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;

    // If there are no more moves and no winner then
    // it is a tie
    if (isMovesLeft(table)==false)
        return 0;

    // If this maximizer's move
    if (isMax)
    {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (table[i][j]==".")
                {
                    // Make the move
                    table[i][j] = player;

                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                        minimax(table, depth+1, !isMax) );

                    // Undo the move
                    table[i][j] = ".";
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (table[i][j]==".")
                {
                    // Make the move
                    table[i][j] = opponent;

                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                           minimax(table, depth+1, !isMax));

                    // Undo the move
                    table[i][j] = ".";
                }
            }
        }
        return best;
    }
}

// This will return the best possible move for the player
AImove findBestMove(string table[3][3])
{
    int bestVal = -1000;
    AImove bestMove;
    bestMove.i = -1;
    bestMove.j = -1;

    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if cell is empty
            if (table[i][j]==".")
            {
                // Make the move
                table[i][j] = player;

                // compute evaluation function for this
                // move.
                int moveVal = minimax(table, 0, false);

                // Undo the move
                table[i][j] = ".";

                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
                {
                    bestMove.i = i;
                    bestMove.j = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

void copyTable(string temptable[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            temptable[i][j] = table[i][j];
        }
    }
}
