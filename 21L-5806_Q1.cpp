#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;
bool Word_Left_To_Right(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	int start = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		arr[row][col] = str[start];
		col++;
	}
	word_placed = true;
	return word_placed;
}
bool Word_Right_to_Left(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	bool space_check = true;
	int start = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		arr[row][col] = str[start];
		col--;
	}
	word_placed = true;
	return word_placed;
}
bool Word_Top_To_Bottom(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	int start = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		arr[row][col] = str[start];
		row++;
	}
	word_placed = true;
	return word_placed;
}
bool Word_Bottom_to_Top(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	int start = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		arr[row][col] = str[start];
		row--;
	}
	word_placed = true;
	return word_placed;
}
bool Word_TopLeft_to_Bottomright(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	int start = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		arr[row][col] = str[start];
		row++;
		col++;
	}
	word_placed = true;
	return word_placed;
}
bool  Word_Bottomright_To_TopLeft(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	int start = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		arr[row][col] = str[start];
		row--;
		col--;
	}
	word_placed = true;
	return word_placed;
}

bool  TopPightToBottomLeft(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	int start = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		arr[row][col] = str[start];
		row++;
		col--;
	}
	word_placed = true;
	return word_placed;
}

bool BottomLeftToTopRight(char** arr, int row, int col, char str[])
{
	bool word_placed = false;
	int start = 0;
	for (start = 0; str[start] != '\0'; start++)
	{
		arr[row][col] = str[start];
		row--;
		col++;
	}
	word_placed = true;
	return word_placed;
}
bool GeneralCheck(char** array, int row, int col, char word[], int movement)
{
	int index = 0;
	for (; word[index] != '\0'; index++)
	{
		if (array[row][col] != '*')
		{
			if (array[row][col] != word[index])
			{
				return false;
			}
		}
		if (movement == 1)
		{
			col++;
		}
		if (movement == 2)
		{
			col--;
		}
		if (movement == 3)
		{
			row++;
		}
		if (movement == 4)
		{
			row--;
		}
		if (movement == 5)
		{
			row++;
			col++;
		}
		if (movement == 6)
		{
			row--;
			col--;
		}
		if (movement == 7)
		{
			row++;
			col--;
		}
		if (movement == 8)
		{
			row--;
			col++;
		}
	}
	return true;
}
int main()
{
	ifstream fin;
	ofstream fout;
	char str1[15];
	int rand_row = 0;
	int rand_col = 0;
	int move = 0;
	int WordRangeRow = 0;
	int WordRangeCol = 0;
	int rows = 0;
	int cols = 0;
	srand(time(0));
	bool word_placed = false;
	bool space_check = true;
	char arr[10][10];
	fin.open("Input.txt");
	fin >> str1;
	int length = strlen(str1);
	while (!fin.eof())  // This loop is used to find the the maximum length in the grid  
	{
		fin >> str1;
		if (strlen(str1) > length)
		{
			length = strlen(str1);
		}
	}
	fin.close();
	char** grid = 0;
	length += 3;  //Expanding the length by 3
	rows = length;
	cols = length;
	grid = new char* [length];
	for (int i = 0; i < length; i++)   //Creating a two dimensional array with same number of rows and columns
	{
		grid[i] = new char[length];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			grid[i][j] = '*';  // Initializing the array with *
		}
	}
	fin.open("Input.txt");
	while (!fin.eof())   // This loop will be executed till the end of file 
	{
		fin >> str1;
		word_placed = false;
		while (!word_placed)
		{
			rand_row = rand() % length;  //Selecting a random row
			rand_col = rand() % length;  // Selecting a random column
			WordRangeRow = rand_row - (strlen(str1) - 1);   // It is the direction which the word would require in the left to right direction
			WordRangeCol = rand_col - (strlen(str1) - 1);  // It is the direction which the word would require in the bottom to top direction

			if ((rand_col + (strlen(str1) - 1)) < cols)   // Checking If there is space for the exist in left to right direction
			{
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 1); // Checking that if there is space for the word to be placed
				if (space_check)
				{
					word_placed = Word_Left_To_Right(grid, rand_row, rand_col, str1); // Function will place the word in left to right direction
				}
			}

			if (((rand_col + (strlen(str1) - 1)) < cols && (rand_row + (strlen(str1) - 1)) < rows) && !word_placed) // Checking If there is space for the exist in Topleft to Bottomright direction
			{
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 5); // Checking that if there is space for the word to be placed
				if (space_check)
				{
					word_placed = Word_TopLeft_to_Bottomright(grid, rand_row, rand_col, str1);  // Function will place the word in Topleft to Bottomright direction
				}

			}

			if (WordRangeCol >= 0 && !word_placed)     // Checking If there is space for the exist in right to left direction
			{
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 2);  // Checking that if there is space for the word to be placed
				if (space_check)
				{
					word_placed = Word_Right_to_Left(grid, rand_row, rand_col, str1); // Function will place the word in Right to left direction
				}
			}

			if (((WordRangeCol >= 0) && (WordRangeRow >= 0)) && !word_placed)  // Checking If there is space for the exist in Bottomright to Topleft direction
			{
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 6);    // Checking that if there is space for the word to be placed
				if (space_check)
				{
					word_placed = Word_Bottomright_To_TopLeft(grid, rand_row, rand_col, str1);  // Function will place the word in BottomRight to Topleft direction
				}

			}

			if ((rand_row + (strlen(str1) - 1)) < rows && !word_placed)  // Checking If there is space for the exist in Top to Bottom direction
			{
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 3);  // Checking that if there is space for the word to be placed
				if (space_check)
				{
					word_placed = Word_Top_To_Bottom(grid, rand_row, rand_col, str1); // Function will place the word in Top to Bottom direction
				}
			}

			if ((WordRangeCol >= 0 && (rand_row + (strlen(str1) - 1)) < rows) && !word_placed)  // Checking If there is space for the exist in TopRight to BottomLeft direction
			{
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 7);  // Checking that if there is space for the word to be placed
				if (space_check)
				{
					word_placed = TopPightToBottomLeft(grid, rand_row, rand_col, str1);  // Function will place the word in TopRight to BottomLeft direction
				}

			}

			if (WordRangeRow >= 0 && !word_placed)    // Checking If there is space for the exist in  Bottom to Top direction
			{
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 4);  // Checking that if there is space for the word to be placed
				if (space_check)
				{
					word_placed = Word_Bottom_to_Top(grid, rand_row, rand_col, str1);    // Function will place the word in Bottom To Top direction
				}

			}

			if (((rand_col + (strlen(str1) - 1)) < rows && WordRangeRow >= 0) && !word_placed)   // Checking If there is space for the exist in  BottomLeft to TopRight direction
			{
				space_check = GeneralCheck(grid, rand_row, rand_col, str1, 8); // Checking that if there is space for the word to be placed
				if (space_check)
				{
					word_placed = BottomLeftToTopRight(grid, rand_row, rand_col, str1);    // Function will place the word in BottomLeft To TopRight direction
				}

			}
		}
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			cout << grid[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
	fout.open("Output.txt");
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (grid[i][j] == '*')
			{
				grid[i][j] = (rand() % 26) + 65;   //Filling the empty spaces with random alphabets
			}
			cout << grid[i][j] << "   ";
		}
		cout << endl;
	}
	for (int i = 0; i < length; i++)  // Printing the array in the test file
	{
		for (int j = 0; j < length; j++)
		{
			fout << grid[i][j] << "   ";
		}
		fout << endl;
	}
	fout.close();
	system("pause");
	return 0;
}