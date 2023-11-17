#include <iostream>
#include <ctime>
#include<cstdlib>
using namespace std;

void ShowTitle()
{
	cout << "	    	" << "TIC TAC TOE" << endl;
	cout << "	   " << "X and O for symbols.\n\n";


}

void BoardInitialization(char arr[20][20], int size)
{

	for (int i = 0; i < size;i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = ' ';
		}
	}


}


bool RowMatch(char arr[20][20], int size, int rownumber, bool player1)
{
	bool isRowMatch = false;

	int matchCount = 0;

	if (player1)
	{
		for (int i = 0; i < size; i++)
		{
			if ('X' == arr[rownumber][i])
			{
				matchCount++;
			}
			else
			{
				isRowMatch = false;
			}
		}

		if (matchCount == size)
		{
			isRowMatch = true;
		}
	}
	else if (!player1)
	{
		for (int i = 0; i < size; i++)
		{
			if ('O' == arr[rownumber][i])
			{
				matchCount++;
			}
			else
			{
				isRowMatch = false;
			}
		}

		if (matchCount == size)
		{
			isRowMatch = true;
		}
	}



	if (isRowMatch == true)
	{
		return true;
	}
	else
	{
		return false;
	}


}



bool ColMatch(char arr[20][20], int size, int colnumber, bool player1)
{
	bool isColMatch = false;

	int matchCount = 0;

	if (player1)
	{
		for (int i = 0; i < size; i++)
		{
			if ('X' == arr[i][colnumber])
			{
				matchCount++;
			}
			else
			{
				isColMatch = false;
			}
		}

		if (matchCount == size)
		{
			isColMatch = true;
		}
	}
	else if (!player1)
	{
		for (int i = 0; i < size; i++)
		{
			if ('O' == arr[i][colnumber])
			{
				matchCount++;
			}
			else
			{
				isColMatch = false;
			}
		}

		if (matchCount == size)
		{
			isColMatch = true;
		}
	}



	if (isColMatch == true)
	{
		return true;
	}
	else
	{
		return false;
	}


}


bool DiagPrimeMatch(char arr[20][20], int size, int rownumber, int colnumber, bool player1)
{
	bool isDiagMatch = false;

	int matchCount = 0;

	if (player1)
	{
		for (int i = 0; i < size; i++)
		{
			int j = i;
			if ('X' == arr[i][j])
			{
				matchCount++;
			}
			else
			{
				isDiagMatch = false;
			}
		}

		if (matchCount == size)
		{
			isDiagMatch = true;
		}
	}
	else if (!player1)
	{
		for (int i = 0; i < size; i++)
		{
			int j = i;
			if ('O' == arr[i][j])
			{
				matchCount++;
			}
			else
			{
				isDiagMatch = false;
			}
		}

		if (matchCount == size)
		{
			isDiagMatch = true;
		}
	}



	if (isDiagMatch == true)
	{
		return true;
	}
	else
	{
		return false;
	}


}





bool DiagSecMatch(char arr[20][20], int size, int rownumber, int colnumber, bool player1)
{
	int coltrack = 0;
	bool isDiagMatch = false;

	int matchCount = 0;

	if (player1)
	{
		for (int i = 0; i < size ; i++)
		{
			coltrack = size;
			if ('X' == arr[i][coltrack])
			{
				matchCount++;
			}
			else
			{
				isDiagMatch = false;
			}
			coltrack--;
		}

		if (matchCount == size)
		{
			isDiagMatch = true;
		}
	}
	else if (!player1)
	{

		for (int i = 0; i < size; i++)
		{
				coltrack = size;
				if ('O' == arr[i][coltrack])
				{
					matchCount++;
				}
				else
				{
					isDiagMatch = false;
				}
				coltrack--;
		}

		if (matchCount == size)
		{
			isDiagMatch = true;
		}
	}



	if (isDiagMatch == true)
	{
		return true;
	}
	else
	{
		return false;
	}


}





void PrintBoard(char arr[20][20], int size)
{
	//printing

	system("CLS");
	ShowTitle();

	cout << "\n";

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j == 0)
			{
				cout << "\t";
			}
			cout << arr[i][j];
			if (j != size - 1)
			{
				cout << " | ";
			}
		}
		cout << "\n\t";
		for (int i = 0; i < (size * 4) - (size / 2.5); i++) //a random ratio for printing line
		{
			cout << "-";
		}
		cout << "\n";
	}

	cout << "\n";

}








bool WinCheck(char arr[20][20], int size, int rownumber, int colnumber, bool player1)
{
	if (RowMatch(arr, size, rownumber, player1))
	{
		if (player1)
		{

			PrintBoard(arr, size);

			cout << "\n\nPlayer1 wins\n\n";
			return true;

		}
		else
		{
			PrintBoard(arr, size);

			cout << "\n\nPlayer2 wins\n\n";
			return true;
		}

	}


	if (ColMatch(arr, size, colnumber, player1))
	{
		if (player1)
		{
			PrintBoard(arr, size);

			cout << "\n\nPlayer1 wins\n\n";
			return true;

		}
		else
		{
			PrintBoard(arr, size);

			cout << "\n\nPlayer2 wins\n\n";
			return true;
		}

	}



	if (DiagPrimeMatch(arr, size, rownumber, colnumber, player1))
	{
		if (player1)
		{
			PrintBoard(arr, size);

			cout << "\n\nPlayer1 wins\n\n";
			return true;

		}
		else
		{
			PrintBoard(arr, size);

			cout << "\n\nPlayer2 wins\n\n";
			return true;
		}

	}


	if (DiagSecMatch(arr, size, rownumber, colnumber, player1))
	{
		if (player1)
		{
			PrintBoard(arr, size);

			cout << "\n\nPlayer1 wins\n\n";
			return true;

		}
		else
		{
			PrintBoard(arr, size);

			cout << "\n\nPlayer2 wins\n\n";
			return true;
		}

	}




}












int RandomTurnGenerator()
{
	int randomnum = 0;
	srand(time(0));
	randomnum = (rand() % 2) ;
	return randomnum;
}

void GameStart(char arr[20][20], int boardSizeInput)
{

	int rownum;
	int colnum;
	int inputcounter = 0;

	bool player1wins = false;
	bool player2wins = false;
	bool isDraw = false;

	// RANDOM TURN DECIDE AT START

	int turndecider = RandomTurnGenerator();
	bool player2turn = true;
	bool player1turn = false;

	bool isWin = false;

	if (turndecider == 0)
	{
		player1turn = true;
	}
	else if (turndecider == 1)
	{
		player2turn = true;
	}




	// GAME LOOP

	while (isWin != true && isDraw != true)
	{

		if (player1turn == true)
		{
			cout << "\n\t  Player 1 Turn\n" << endl;
		}
		else
		{
			cout << "\n\t  Player 2 Turn" << endl;

		}

		//input
		cout << "Enter row number: ";
		cin >> rownum;

		cout << "Enter column number: " << endl;
		cin >> colnum;

		if (rownum > boardSizeInput)
		{
			cout << "Invalid Row Number. Enter again." << endl;
			continue;
		}
		if (colnum > boardSizeInput)
		{
			cout << "Invalid Column Number. Enter again." << endl;
			continue;
		}
		rownum -= 1;
		colnum -= 1;

		//storing required in req index
		if (player1turn == true)
		{
			if (arr[rownum][colnum] == ' ') //Checking whether it has been printed before
			{
				arr[rownum][colnum] = 'X';
				inputcounter++;//keeping count of number of inputs


			}
			else
			{
				cout << "Already placed. Enter again. ";
				continue;
			}

			isWin = WinCheck(arr, boardSizeInput, rownum, colnum, player1turn);
			if (isWin)
			{
				break;
			}
			player1turn = false;
			player2turn = true;
		}
		else if (player2turn == true)
		{
			if (arr[rownum][colnum] == ' ')
			{
				arr[rownum][colnum] = 'O';
				inputcounter++;


			}
			else
			{
				cout << "Already placed. Enter again. ";
				continue;
			}

			isWin = WinCheck(arr, boardSizeInput, rownum, colnum, player1turn);
			if (isWin)
			{
				break;
			}
			player2turn = false;
			player1turn = true;
		}



		PrintBoard(arr, boardSizeInput);
		if (isWin == false && inputcounter == boardSizeInput * boardSizeInput)
		{
			cout << "\nDraw\n\n";
			isDraw = true;
		}
	}


}


int main()
{
	ShowTitle();


	bool isGameStart = false;
	while (true)
	{
		int boardSizeInput;
		cout << "Enter rows and column count: ";

		cin >> boardSizeInput;

		if (boardSizeInput > 2 && isGameStart == false)
		{
			char arr[20][20];
			BoardInitialization(arr, boardSizeInput);
			isGameStart = true;
			PrintBoard(arr, boardSizeInput);
			GameStart(arr, boardSizeInput);
			break;
		}
		else
		{
			cout << "\n\nInvalid Table Size (Enter greater than 2)\n\n";
			continue;
		}
	}



}
