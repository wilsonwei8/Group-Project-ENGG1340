#include "gobang.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

int judge(int x, int y) 
{	

	int i, a, b;
	int type;
	
	//identify whose turn is it
	if(Board[x][y] == BLACKtem)
	{
		type = BLACK;
		if(RestrictedMove(x, y)) return -1;	//determine if it is a restricted move
	} 
	else type = WHITE;
	
	
	//horizontal
	for(i=1, a=0; ; i++, a++)
		if(x-i < 0 || Board[x-i][y] != type) break;
	for(i=1, b=0; ; i++, b++)
		if(x+i > 14 || Board[x+i][y] != type) break;
	if(a+b >= 4) return type;
	//vertical
	for(i=1, a=0; ; i++, a++)
		if(y-i < 0 || Board[x][y-i] != type) break;
	for(i=1, b=0; ; i++, b++)
		if(y+i > 14 || Board[x][y+i] != type) break;
	if(a+b >= 4) return type;
	//diagonal
	for(i=1, a=0; ; i++, a++)
		if(x-i < 0 || y-i < 0 || Board[x-i][y-i] != type) break;
	for(i=1, b=0; ; i++, b++)
		if(x+i > 14 || y+i > 14 || Board[x+i][y+i] != type) break;
	if(a+b >= 4) return type;
	//anti-diagonal
	for(i=1, a=0; ; i++, a++)
		if(x+i > 14 || y-i < 0 || Board[x+i][y-i] != type) break;
	for(i=1, b=0; ; i++, b++)
		if(x-i < 0 || y+i > 14 || Board[x-i][y+i] != type) break;
	if(a+b >= 4) return type;

	return 0; 
} 


void ChooseMode()
{	
	string s;
	cout << "\033[1mPlease select the mode for \"pvp\" (\033[1;31mp\033[0m\033[1m) or \"pve\" (\033[1;31ma\033[0m\033[1m) or Residual situation (\033[1;31mr\033[0m\033[1m):\033[0m" << endl;
	cin >> s;
	if(s[0] == 'p')
		mode = 0;
	else if(s[0] == 'a')
		mode = 1;
	else if(s[0] == 'r')
		mode = 2;
	else
	{
		cout << "\n\033[1mPlease type in letter \033[1;31mp\033[0m \033[1mor \033[1;31ma\033[0m \033[1mor \033[1;31mr\033[0m.\033[0m" << endl;
		ChooseMode();
	}
} 


void ChooseSide()
{	
	string s;
	cout << "\033[1mPlease choose whether to play as black (\033[1;31mb\033[0m\033[1m) or white (\033[1;31mw\033[0m\033[1m):\033[0m" << endl;
	cin >> s;
	if(s[0]== 'b')
	{
		side_p = BLACK;
		side_ai = WHITE;
	}
	else if(s[0] == 'w')
	{
		side_p = WHITE;
		side_ai = BLACK;
	} 
	else
	{
		cout <<"\n\033[1mPlease type in (\033[1;31mb\033[0m)\033[1m or (\033[1;31mw\033[0m\033[1m).\033[0m"<< endl;
		ChooseSide();
	}
}




int RestrictedMove(int x, int y)	//determine whether it is a restricted move
{	
	if(ScoreBoard_b[x][y] == -2) return 1;
	else return 0;
}
