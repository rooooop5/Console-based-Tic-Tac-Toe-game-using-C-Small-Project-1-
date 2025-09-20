#include <stdio.h>



void board_printer(char board[][3]);
char game();
void get_index(int n,int* row, int* col);
char who_won(char board[3][3],int* game_over);
char win_checker(char board[][3]);
void format_printer();
void write_in_posn(char board[3][3],int* boxes_filled,char entry);
char decider(char board[3][3],int* boxes_filled,int* game_over);



char decider(char board[3][3],int* boxes_filled,int* game_over)
{
    char winner='N';
    if ((*boxes_filled)>=5 && (*boxes_filled)!=9)
    {
        winner=who_won(board,game_over);
        return winner;
    }
    if((*boxes_filled)==9)
    {
        winner=' ';
        printf("Its a draw\n");
        (*game_over)=1;
        return winner;
    }
    return winner;


}



void write_in_posn(char board[3][3],int* boxes_filled,char entry)
{
    int row,col,posn;
    while(1)
    {
        
        if(scanf("%d", &posn) ==0)
        {
            printf("Invalid input. Enter a number 1-9: ");
            while(getchar() != '\n');
        }
        else if(posn<=0 || posn>9)
        {
            printf("Invalid posn input. Try again: ");
        }
        else
        {
            while(getchar() != '\n');
            get_index(posn,&row,&col);
            if(board[row][col]==' ')
            {
                board[row][col]=entry;
                (*boxes_filled)++;
                break;
            }
            else
            {
            printf("Inputted posn is already occupied. Enter a valid posn:");
            }
        }
    }

}



void format_printer()
{
    printf("\n\nRefer to this table to know what number corresponds to what posn in the tic tac toe table.\n\n");
    printf(" 1 | 2 | 3 \n"
           "---+---+---\n"
           " 4 | 5 | 6 \n"
           "---+---+---\n"
           " 7 | 8 | 9 \n\n");
    
}



char game()
{
    format_printer();
    char board[3][3]={
                      {' ',' ',' '},
                      {' ',' ',' '},
                      {' ',' ',' '}
                     };
    char winner;
    int game_over=0,row,col,p1_turn=1;
    int boxes_filled=0;
    while(game_over==0)
    {
        if (boxes_filled==4)
        {
            printf("Bet you forgot about the format \U0001F600!");// 😀
            format_printer();
        }
        if(p1_turn==1)
        {
            printf("Player One's turn to enter :");
            write_in_posn(board,&boxes_filled,'X');
            p1_turn=0;
        
        }
        else
        {
            printf("Player Two's turn to enter :");
            write_in_posn(board,&boxes_filled,'O'); 
            p1_turn=1;
        }
        board_printer(board);
        winner=decider(board,&boxes_filled,&game_over);
    }
    return winner;
}




char who_won(char board[3][3],int* game_over)
{
    char winner=win_checker(board);
    if(winner=='X')
    {
        printf("Player one wins\n");
        *game_over=1;
        return winner;
    }
    if (winner=='O')
    {
        printf("Player two wins\n");
        *game_over=1;
        return winner;
    }
    return winner;
    
}




char win_checker(char board[][3])
{
    int win_counter=0;
    char winner=' ';
    int condtn_1=board[0][0]!=' ' && board[0][0]==board[0][1] && board[0][1]==board[0][2];//upper row check
    int condtn_2=board[1][0]!=' ' && board[1][0]==board[1][1] && board[1][1]==board[1][2];//middle row check
    int condtn_3=board[2][0]!=' ' && board[2][0]==board[2][1] && board[2][1]==board[2][2];//lower row check
    int condtn_4=board[0][0]!=' ' && board[0][0]==board[1][0] && board[1][0]==board[2][0];//left col check
    int condtn_5=board[0][1]!=' ' && board[0][1]==board[1][1] && board[1][1]==board[2][1];//middle col check
    int condtn_6=board[0][2]!=' ' && board[0][2]==board[1][2] && board[1][2]==board[2][2];//right col check
    int condtn_7=board[0][0]!=' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2];//left to right diagonal check
    int condtn_8=board[0][2]!=' ' && board[0][2]==board[1][1] && board[1][1]==board[2][0];//right to left diagonal check
    if(condtn_1)
    {
        winner=board[0][0];
    }
    else if(condtn_2)
    {
        winner=board[1][0];
    }
    else if(condtn_3)
    {
        winner=board[2][0];
    }
    else if(condtn_4)
    {
        winner=board[0][0];
    }
    else if(condtn_5)
    {
        winner=board[0][1];
    }
    else if(condtn_6)
    {
        winner=board[0][2];
    }
    else if(condtn_7)
    {
        winner=board[0][0];
    }
    else if(condtn_8)
    {
        winner=board[0][2];
    }
    return winner;

}



void board_printer(char board[][3])
{
    printf("\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j>0)
            {
                printf("| %c ",board[i][j]);
            }
            else
            {
                printf("  %c ",board[i][j]);
            }
            
        }
        //printf("");
        printf("\n");
        if(i!=2)
            printf(" ---+---+---\n");
    }
    printf("\n");
}




void get_index(int posn,int* row, int* col)
{
    *row=(posn-1)/3;
    *col=(posn-1)%3;   
}



void best_of_N(int N)
{
    char winner;
    int p1_count=0,p2_count=0;
    for(int i=1;i<=N;i++)
    {
        printf("This is round %d.\n",i);
        winner=game();
        if (winner=='X')
        {
            p1_count++;
        }
        if(winner=='O')
        {
            p2_count++;
        }
    }
    if (p1_count>p2_count)
    {
        printf("Player one wins %d - %d.\n",p1_count,p2_count);
    }
    else if (p1_count<p2_count)
    {
        printf("Player two wins %d - %d.\n",p2_count,p1_count);
    }
    else
    {
        printf("The game is a draw.\n");
    }
        
}




int round_inputter()
{
    printf("You wanna play this game as best of how many rounds?: ");
    int N;
    scanf("%d",&N);
    return N;

}

int run()
{
    char choice;
    int N;
    printf("This program is a game of tic-tac-toe. Do you wanna play?(y/n): ");
    scanf(" %c",&choice);
    if(choice=='y')
    {
        while(choice=='y')
        {
                N=round_inputter();
                best_of_N(N);
                printf("Do you wanna play again?(y/n): ");
                scanf(" %c",&choice);
        }       
    }
    else
    {            
        printf("Exiting program.\n");
        return 0;
    }
    printf("Exiting program.\n");
    return 0;
}


int main()
 {
    run();
    return 0;
 }
