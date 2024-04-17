#define _CRT_SECURE_NO_WARNINGS
# include "gobang.h"
#include "string"
#include <vector>

int main()
{	
	int x, y;
	
	ChooseMode();
	
	if(mode==1) // man vs machine mode 
	{
		// initial 
		InitBoardArray();
		DisplayBoard();
		
		ChooseSide();
		
		while(side_p == BLACK)
		{	
			//black piece move
			ChangeTemPieces(BLACKtem);		// change tem chess piece  
			MoveP(&Board[0][0], BLACKtem);	// drop a chess piece 
			x = Posi[0];			// record the position of dropping chess piece
			y = Posi[1];
			if(judge(x, y) == -1)			// determine  restricted move 
			{
				cout << "Restricted move!" << endl;
				break;   
			}
			ChangeScoreBoard(x, y, Board);	// refresh the scoreboard 
			DisplayBoard();			// print chessboard  
			if(judge(x, y) == BLACK)	// determine winning or not 
			{
				cout << "Black win!" << endl;
				break; 
			}
			//white piece move 
			ChangeTemPieces(WHITEtem);
			MoveAi(WHITEtem);
			x = Posi[0];
			y = Posi[1];
			ChangeScoreBoard(Posi[0], Posi[1], Board);
			DisplayBoard();
			cout << "drop chess piece at " << char(y + 'A') << 15 - x << "." << endl;
			if(judge(x, y) == WHITE)
			{
				cout << "White win!" << endl;
				break; 
			}
		}
		
		while(side_p == WHITE)
		{
			//black piece move
			ChangeTemPieces(BLACKtem);
			MoveAi(BLACKtem);
			x = Posi[0];
			y = Posi[1];
			ChangeScoreBoard(Posi[0], Posi[1], Board);
			DisplayBoard();
	
			cout << "drop chess piece at " << char(y + 'A') << 15 - x << "." << endl; 
			if(judge(x, y) == BLACK)
			{
				cout << "Black win!" << endl;
				break; 
			}
			//white piece move 
			ChangeTemPieces(WHITEtem);
			MoveP(&Board[0][0], WHITEtem);
			x = Posi[0];
			y = Posi[1]; 
			ChangeScoreBoard(x, y, Board);
			DisplayBoard();
			if(judge(x, y) == WHITE)
			{
				cout << "White win!" << endl;
				break; 
			}
		}	
	}
	
	if (mode==0) //man vs man 
	{
		int i;
		
		InitBoardArray();
		DisplayBoard();
		
		while(1)
		{
			// Black piece move 
			ChangeTemPieces(BLACKtem);
			MoveP(&Board[0][0], BLACKtem);
			x = Posi[0];
			y = Posi[1];
			if(judge(x, y) == -1)
			{
				cout << "Restricted move!" << endl;
				break;   
			}
			ChangeScoreBoard(x, y, Board);
			DisplayBoard();
			if(judge(x, y) == BLACK)
			{
				cout << "Black win!" << endl;
				break; 
			}
			
			//White piece move
			ChangeTemPieces(WHITEtem);
			MoveP(&Board[0][0], WHITEtem);
			x = Posi[0];
			y = Posi[1];
			ChangeScoreBoard(Posi[0], Posi[1], Board);
			DisplayBoard();
			if(judge(x, y) == WHITE)
			{
				cout << "White win!" << endl;
				break; 
			}	
		}		
	}
	if (mode==2){
		int i;
		
		InitBoardArray();
		chooseboard();
		DisplayBoard();
		
		while(1)
		{
			 
			ChangeTemPieces(BLACKtem);
			MoveP(&Board[0][0], BLACKtem);
			x = Posi[0];
			y = Posi[1];
			if(judge(x, y) == -1)
			{
				cout<<"Restricted move"<<endl;
				break;   
			}
			
			ChangeScoreBoard(x, y, Board);
			
			DisplayBoard();
			if(judge(x, y) == BLACK)
			{
				cout<<"Black wins!"<<endl;
				break; 
			}
			
			
			ChangeTemPieces(WHITEtem);
			MoveP(&Board[0][0], WHITEtem);
			x = Posi[0];
			y = Posi[1];
			ChangeScoreBoard(Posi[0], Posi[1], Board);
			DisplayBoard();
			if(judge(x, y) == WHITE)
			{
				cout <<"White wins!"<<endl;
				break; 
			}	
		}		

	}

	while(1) //Prevent direct exit
	{	
		x = getchar(); 
		if(x == '0') break;
	}  
}

