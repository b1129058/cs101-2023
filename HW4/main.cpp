#include <iostream>

using namespace std;

class TicTacToe {
    public:
    TicTacToe(){
        _init();
    }
    
    void run(){
        for(int i = 0;i<9;i++){
            do{
                cout <<"Player "<< (char)((int)player + 'A') << ", 請輸入[1~9] 的數字:";
                cin>>tmp;
            }while(!boardStatus(tmp-1));
            step(player, tmp-1);
            system("clear");
            printBoard();
            Winner = checkWinner(player);
            player = !player;
            if(end){
                cout<<"==> Player "<<(char)(Winner + 'A')<<" Wins!";
                break;
            }
        }
        if(!end)
            cout<<"==> Game draw!";
        
    }
    
    private:
        bool end;
        int tmp;
        bool player;
        int Winner;
        int board[9];// -1 : init
                        // 0  : A
                        // 1  : B
        
        void _init(){
            end = 0;
            Winner = -1;
            player = 0;// 0 : A
                       // 1 : B
            for(int i = 0;i<9;i++){
                board[i] = -1;
            }
            printBoard();
        }
        
        bool boardStatus(int num){
            if(board[num] == -1 and num>=0 and num<=8)
                return true;
            cout<<"請重新輸入:";
            return false;
        }
        
        void printBoard(){
            cout<<"--- Tic Tac Toe --- CSIE@CGU"<<endl
                <<"Player 1 (x) -- Player 2 (o)"<<endl;
            printLine(1);
            printLine(0, 2);
            printLine(1);
            
            printLine(0);
            
            printLine(1);
            printLine(3, 5);
            printLine(1);
            
            printLine(0);
            
            printLine(1);
            printLine(6, 8);
            printLine(1);
            
        }
        
        void printLine(bool type){
            if(type)
                cout<<"     |     |     "<<endl;
            else
                cout<<"================="<<endl;
        }
        void printLine(int _start, int _end){
            for(int i = _start; i <= _end ; i++){
                if(board[i] == 0)
                    cout<<"  x  ";
                else if(board[i] == 1)
                    cout<<"  o  ";
                else
                    cout<<"  "<<i+1<<"  ";
                if((i+1)%3 == 0)
                    cout<<endl;
                else
                    cout<<"|";
            }
        }
        
        void step(bool player, int num){
            board[num] = player;
        }
        
        int checkWinner(bool player){
            int checkList[8][3] = {
                {0, 1, 2}, {3, 4, 5}, {6, 7, 8},//row
                
                {0, 3, 6}, {1, 4, 7}, {2, 5, 8},//column
                
                {0, 4, 8}, {2, 4, 6}//incline
            };
            for(int i = 0; i<8; i++){
                if(board[checkList[i][0]] == player and
                   board[checkList[i][1]] == player and
                   board[checkList[i][2]] == player){
                       end = 1;
                       return player;
                   }
            }
            return -1;
        }
    
};

int main(){
    TicTacToe game;
    game.run();
    return 0;
}
