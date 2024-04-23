# include <iostream>
# include "gobang.h"
# include <vector>


void MoveP(int *pBoard, int piece)	// player move 
{	
	char cY, c;
	int iX;
	int iValue; 
	
	// Gets the drop position and checks if the input format is valid 
	cout << "\33[1mPlease enter the position to place the chess \033[1;33m(letter + number):\033[0m";
	while((c = getchar()) != '\n');
	scanf("%c%d", &cY, &iX);
	
	if((cY >= 'A' && cY <= 'O') && (iX >= 1 && iX <= 15))
	{
		Posi[0] = 15 - iX;
		Posi[1] = cY - 'A';
	} 
	else 
	{
		cout<<BOLD << "The input format is incorrect. Please re-enter the position: "<<endl;

		MoveP(pBoard, piece);
		return; 
	}
	
	//Check if there are any pieces in this position
	iValue = *(pBoard + 15 * Posi[0] + Posi[1]); 
	if(iValue == BLACK || iValue == WHITE || iValue == BLACKtem || iValue == WHITEtem)
	{
		cout <<BOLD<< "There are already pieces in this position, please re-enter the position: "<<endl;
		MoveP(pBoard, piece);
		return;
	}	

	// place the chess
	*(pBoard + 15 * Posi[0] + Posi[1]) = piece;
} 


void MoveAi(int side)	// AI move 
{
	int i, j;
	int x_b, y_b, x_w, y_w;
	int val_b = -1, val_w = -1;
	
	// Find the highest score for each two pieces 
	for(i = 0; i < 15; i++)
		for(j = 0; j < 15; j++)
		{
			if(ScoreBoard_b[i][j] > val_b)
			{
				val_b = ScoreBoard_b[i][j];
				x_b = i;
				y_b = j;
			}
			if(ScoreBoard_w[i][j] > val_w) 
			{
				val_w = ScoreBoard_w[i][j];
				x_w = i;
				y_w = j;
			}
		}
	
	// decide to attack or defense depending on the corresponding score 
	if(val_b >= val_w)
	{
		for(i = 0; i < 15; i++)
		{
			for(j = 0; j < 15; j++)
			{
				if(ScoreBoard_b[i][j] == val_b)
				{
					if(ScoreBoard_w[i][j] > ScoreBoard_w[x_b][y_b])
					{
						x_b = i;
						y_b = j;
					}
				}
			}
		}
		Board[x_b][y_b] = side;
		Posi[0] = x_b;
		Posi[1] = y_b; 
	}
	
	else
	{
		for(i = 0; i < 15; i++)
		{
			for(j = 0; j < 15; j++)
			{
				if(ScoreBoard_w[i][j] == val_w)
				{
					if(ScoreBoard_b[i][j] > ScoreBoard_b[x_w][y_w])
					{
						x_w = i;
						y_w = j;
					}
				}
			}
		}
		Board[x_w][y_w] = side;
		Posi[0] = x_w;
		Posi[1] = y_w;
	}
}
