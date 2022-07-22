#include<iostream>

using namespace std;
char board[3][3];

char playerSymbol, computerSymbol, turn;
int moves = 0;

void getPlayerMove(char board[3][3]){
    int line, column;

    cout << "Input the line and column where you want the move to be: " << endl;
    cin >> line >> column;
    if(board[line][column] == ' '){
        board[line][column] = playerSymbol;
        moves++;
    }else{
        cout << "Slot is already taken!" << endl;
        getPlayerMove(board);
    }
}
int getComputerInput(char board[3][3]){
    int line = rand() % 3;
    int column = rand() % 3;

    if(board[line][column] == ' '){
        board[line][column] = computerSymbol;
        moves++;
    }else{
        getComputerInput(board);
    }
}
char checkVictory(char board[3][3]){
    for(int i = 0; i <= 2; i++){
        if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][0]!=' '){
            return board[i][0];
        }
    }
    for(int i = 0; i <= 2; i++){
      if (board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[0][i]!=' '){
        return board[0][i];
      }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2] && board[0][0] != ' '){
        return board[0][0];
    }
     if(board[0][2]==board[1][1] && board[1][1]==board[2][0] && board [0][2] != ' '){
        return board[0][2];
     }
    if(moves == 9){
        return 'D';
    }
     return 'P';
}

void outputBoard(char board[3][3]){
    cout << "Move counter: " << moves << endl;
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<"\n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<"\n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<"\n";
    cout<<"     |     |     \n";
    cout << "---------------------------------------------" << endl;

}

int main()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }

    int coin = rand() % 2;
    if(coin == 0){
        playerSymbol = 'X';
        computerSymbol = 'O';
    }else{
        playerSymbol = 'O';
        computerSymbol = 'X';
    }

    while(checkVictory(board) == 'P'){

        if(moves % 2 != 0){
            turn = 'X';
        }else{
            turn = 'O';
        }

        if(playerSymbol == turn){
            getPlayerMove(board);
        }
        if(computerSymbol == turn){
            getComputerInput(board);
        }

        outputBoard(board);
    }

    if(checkVictory(board) == playerSymbol){
        cout << "You win!" << endl;
    }else if(checkVictory(board) == 'D'){
        cout << "The game is a draw." << endl;
    }else{
        cout << "Computer wins!" << endl;
    }
}
