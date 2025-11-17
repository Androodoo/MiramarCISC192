#include <iostream>



class TicTacToe{
    private:
        char unmarked = '_'; //unmarked tiles will be _
        char board[3][3]; //3x3 board
        char currentPlayer; // X or O
        int moveCount = 0; //max9
        int r,c;

    public:
    //initialize everything to _ so it doesnt freak out and give crazy symbols
        void initializeBoard(){
            for(int column = 0; column < 3; column++){
                for(int row = 0; row < 3; row++){
                    board[row][column] = unmarked;
                }
            }
        }
        void displayBoard(){
            //in each row of each column, cout the element
            for(int column = 0; column < 3; column++){
                std::cout << "\n";
                for(int row = 0; row < 3; row++){
                    std::cout << board[row][column];
                    if(row < 2){
                        std::cout << "|";
                    }
                }
            }
        }
        bool isValidMove(int r,int c){
            if(r > 3 || r < 0){
                std::cerr << "r must be within 0-2";
                return false;
            }
            if(c > 3 || c < 0){
                std::cerr << "c must be within 0-2";
                return false;
            }
            if(board[r][c] != unmarked){
                std::cerr << "This tile is already taken,";
                return false;
            }
            return true;
        }
        void makeMove(int r,int c){
            switchPlayer(); //after every move, go from x to o or o to x
            bool valid = false;
            while(!valid){
                std::cout << "\n" << currentPlayer <<", make your move (r, c): ";
                std::cin >> r >> c;
                if(isValidMove(r-1,c-1)){
                    board[r-1][c-1] = currentPlayer; //the -1 is just so the user can input 1-3 instead of 0-2
                    moveCount++; //counter that can lead up to a draw
                    valid = true;
                } else {
                    std::cerr << " invalid move, input again \n";
                }
            }
            
            
        }

        //I was going to make an x/o counter and use loops, but I think it's easier to read and code if i just hard coded it. also im on a time crunch lol
        bool checkWinner(){
            // X ACROSS
            if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X'){
                std::cout << "\nX wins!";
                return true;
            }
            if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X'){
                std::cout << "\nX wins!";
                return true;
            }
            if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X'){
                std::cout << "\nX wins!";
                return true;
            }
            //X DIAG
            if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X'){
                std::cout << "\nX wins!";
                return true;
            }
            if(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'){
                std::cout << "\nX wins!";
                return true;
            }
            // O ACROSS
            if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O'){
                std::cout << "\nO wins!";
                return true;
            }
            if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O'){
                std::cout << "\nO wins!";
                return true;
            }
            if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O'){
                std::cout << "\nO wins!";
                return true;
            }
            // O DIAG
            if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O'){
                std::cout << "\nO wins!";
                return true;
            }
            if(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'){
                std::cout << "\nO wins!";
                return true;
            }
            return false; // no winner
        }
        bool isDraw(){
            if(moveCount == 9 && !checkWinner()){
                std::cout << "\nDraw!";
                return true; //winner
            }
            return false; //no draw, continue
        }
        void switchPlayer(){
            if(moveCount % 2 == 0){
                currentPlayer = 'X';
            }
            else {
                currentPlayer = 'O';
            }
        }
        void playGame(){
            displayBoard();
            //While there is no winner/draw, keep making moves until there is one
            while(!checkWinner() && !isDraw()){
                makeMove(r,c);
                displayBoard();
            }
        }
};

int main(){
    char replay;
    TicTacToe game; //create game

    //Do this while the choice is y
    do{
        game.initializeBoard(); //set up the board!
        game.playGame(); //play

        std::cout << "\nDo u wanna play again? (y/n) ";
        std::cin >> replay;
    } while (replay == 'y' || replay == 'Y');
    //otherwise end
    return 0;
}