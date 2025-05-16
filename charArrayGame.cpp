#include<iostream>
using namespace std;
void displayArray(char(*arr)[3], int row, int rowSize);
void playGame(char (*arr)[3], int row, int rowSize);
void displayWinner(char (*arr)[3], int row, int rowSize);
bool checkIfAnyPlayerWin(char(*arr)[3], int row, int rowSize);
void inputPlayer1Choice(char(*arr)[3], int row, int rowSize);
void inputPlayer2Choice(char(*arr)[3], int row, int rowSize);
int main()
{
	const int  row = 3, rowSize = 3;
	char arr[row][rowSize] = {'1','2','3','4','5','6','7','8','9'};
	displayArray(arr, row, rowSize);
	playGame(arr, row, rowSize);
}
void playGame(char (*arr)[3], int row, int rowSize)
{
	int choice = 1;
	while((checkIfAnyPlayerWin(arr,row,rowSize) == false) && (choice <= 9))
	{
		if (choice % 2 == 1)
		{
			inputPlayer1Choice(arr, row, rowSize);
		}
		else
		{
			inputPlayer2Choice(arr, row, rowSize);
		}
		displayArray(arr, row, rowSize);
		if (checkIfAnyPlayerWin(arr, row, rowSize))
		{
			displayWinner(arr, row, rowSize);
		}
		choice = choice + 1;
	}
	if (choice == 10)
	{
		cout << "Match has been Tie ! ";
	}
}
void displayArray(char(* arr)[3], int row, int rowSize)
{
	for (int i = 0;i < row;i = i + 1)
	{
		for (int j = 0;j < rowSize;j = j + 1)
		{
			cout << arr[i][j]<<"  ";
		}
		cout << "\n";
	}
}
void inputPlayer1Choice(char(*arr)[3],int row,int rowSize)
{
	char choice;
	cout << "Player 1 : Enter your choice_";
	cin >> choice;
	for (int i = 0;i < row;i = i + 1)
	{
		for (int j = 0;j < rowSize;j = j + 1)
		{
			if (arr[i][j] == choice)
			{
				arr[i][j] = 'X';
			}
		}
	}
}
void inputPlayer2Choice(char(*arr)[3], int row, int rowSize)
{
	char choice;
	cout << "Player 2 : Enter your choice_";
	cin >> choice;
	for (int i = 0;i < row;i = i + 1)
	{
		for (int j = 0;j < rowSize;j = j + 1)
		{
			if (arr[i][j] == choice)
			{
				arr[i][j] = 'Y';
			}
		}
	}
}
bool checkIfAnyPlayerWin(char(*arr)[3], int row, int rowSize)
{
	if (((arr[0][0] == arr[0][1]) && (arr[0][0] == arr[0][2]))|| ((arr[1][0] == arr[1][1]) && (arr[1][0] == arr[1][2]))|| ((arr[2][0] == arr[2][1]) && (arr[2][0] == arr[2][2]))|| ((arr[0][0] == arr[1][0]) && (arr[0][0] == arr[2][0]))|| ((arr[0][1] == arr[1][1]) && (arr[0][1] == arr[2][1]))|| ((arr[0][2] == arr[1][2]) && (arr[0][2] == arr[2][2]))|| ((arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2]))|| ((arr[0][2] == arr[1][1]) && (arr[0][2] == arr[2][0])))
	{
		return true;
	}
	return false;
}
void displayWinner(char (*arr)[3], int row, int rowSize)
{
	if (((arr[0][0] == arr[0][1]) && (arr[0][0] == arr[0][2]) && (arr[0][0] == 'X')) || ((arr[1][0] == arr[1][1]) && (arr[1][0] == arr[1][2]) && (arr[1][0] == 'X')) || ((arr[2][0] == arr[2][1]) && (arr[2][0] == arr[2][2]) && (arr[2][0] == 'X')) || ((arr[0][0] == arr[1][0]) && (arr[0][0] == arr[2][0]) && (arr[0][0] == 'X')) || ((arr[0][1] == arr[1][1]) && (arr[0][1] == arr[2][1]) && (arr[0][1] == 'X')) || ((arr[0][2] == arr[1][2]) && (arr[0][2] == arr[2][2]) && (arr[0][2] == 'X')) || ((arr[0][0] == arr[1][1]) && (arr[0][0] == arr[2][2]) && (arr[0][0] == 'X')) || ((arr[0][2] == arr[1][1]) && (arr[0][2] == arr[2][0]) && (arr[0][2] == 'X')))
	{
		cout << "Congratulations ! Player #1 won the Match";
	}
	else
	{
		cout << "Congratulations ! Player #2 won the Match";
	}
}