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
	string text7_1 = "Please select the mode for\"pvp\"";
	string text7_2 = "(p)or\"";
	string text7_3 = "pve\"(a) or ";
	string text7_3 = "Residual situation(r): ";

	 for (char& c : text7_1) {
        cout << BOLD << c << RESET;
        this_thread::sleep_for(milliseconds(5));
      }
	for (char& c : text7_2) {
        if (c == 'p'){
	        cout << BOLD << RED << c << RESET;
	        this_thread::sleep_for(milliseconds(5));
	    }
	    else {
	        cout << BOLD << c << RESET;
	        this_thread::sleep_for(milliseconds(5));
	    }
	}
	for (char& c : text7_3) {
        if (c == 'a'){
	        cout << BOLD << RED << c << RESET;
	        this_thread::sleep_for(milliseconds(5));
	    }
	    else {
	        cout << BOLD << c << RESET;
	        this_thread::sleep_for(milliseconds(5));
	    }
	}
	for (char& c : text7_4) {
        if (c == 'r'){
	        cout << BOLD << RED << c << RESET;
	        this_thread::sleep_for(milliseconds(5));
	    }
	    else {
	        cout << BOLD << c << RESET;
	        this_thread::sleep_for(milliseconds(5));
	    }
	}
	cin >> s;
	if(s == 'p')
		mode = 0;
	else if(s == 'a')
		mode = 1;
	else if(s == 'r')
		mode = 2;
	else
	{
		string text8_1 = "please type in letter ";
		string text8_2 = "p or a."

		for (char& c : text8_1) {
		        cout << BOLD << c << RESET;
		        this_thread::sleep_for(milliseconds(5));
		      }

		for (char& c : text8_2) {
		        if (c == 'p' || c == 'a'){
			        cout << BOLD << RED << c << RESET;
			        this_thread::sleep_for(milliseconds(5));
			    }
			    else {
			        cout << BOLD << c << RESET;
			        this_thread::sleep_for(milliseconds(5));
			    }
			}
		ChooseMode();
	}
} 


void ChooseSide()
{	
	string s;
	cout << "Please choose whether to play as black (b) or white (w):";
	cin >> s;
	if(s[0] == 'b')
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
		cout << "\nPlease type in b or w.";
		ChooseSide();
	}
}


int RestrictedMove(int x, int y)	//determine whether it is a restricted move
{	
	if(ScoreBoard_b[x][y] == -2) return 1;
	else return 0;
}
