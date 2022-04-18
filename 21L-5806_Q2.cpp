#include<iostream>
#include<fstream>
using namespace std;
bool LeftToRight(char** array, int row, int col, char word[]) // This funcion returns true if the word is found and return false otherwise
{
	int index = 0;
	for (; word[index]!= '\0'; index++) // It compares index by index value wiit the word from the point which has been passed to it 
	{
		if (array[row][col] != word[index]) 
		{
			return false;
		}
		col++;
	}
	return true;
}
bool RightToLeft(char** array, int row, int col, char word[])
{
	int index = 0;
	for (; word[index] != '\0'; index++)  // It compares index by index value wiit the word from the point which has been passed to it 
	{
		if (array[row][col] != word[index])
		{
			return false;
		}
		col--;
	}
	return true;
}
bool TopToBottom(char** array, int row, int col, char word[])
{
	int index = 0;
	for (; word[index] != '\0'; index++)  // It compares index by index value wiit the word from the point which has been passed to it 
	{
		if (array[row][col] != word[index])
		{
			return false;
		}
		row++;
	}
	return true;
}
bool BottomToTop(char** array, int row, int col, char word[])
{
	int index = 0;
	for (; word[index] != '\0'; index++)  // It compares index by index value wiit the word from the point which has been passed to it 
	{
		if (array[row][col] != word[index])
		{
			return false;
		}
		row--;
	}
	return true;
}
bool TopLeftToBottomRight(char** array, int row, int col, char word[])
{
	int index = 0;
	for (; word[index] != '\0'; index++)  // It compares index by index value wiit the word from the point which has been passed to it 
	{
		if (array[row][col] != word[index])
		{
			return false;
		}
		row++;
		col++;
	}
	return true;
}
bool BottomRightToTopLeft(char** array, int row, int col, char* word)
{
	
	for (int index = 0; word[index] != '\0'; index++)  // It compares index by index value wiit the word from the point which has been passed to it 
	{
		if (array[row][col] != word[index])
		{
			return false;
		}
		row--;
		col--;
		
	}
	return true;
}
bool TopRightToBottomLeft(char** array, int row, int col, char word[])
{
	int index = 0;
	for (; word[index] != '\0'; index++)  // It compares index by index value wiit the word from the point which has been passed to it 
	{
		if (array[row][col] != word[index])
		{
			return false;
		}
		row++;
		col--;
	}
	return true;
}
bool BottomLeftToTopRight(char** array, int row, int col, char word[])
{
	int index = 0;
	for (; word[index] != '\0'; index++)  // It compares index by index value wiit the word from the point which has been passed to it 
	{
		if (array[row][col] != word[index])
		{
			return false;
		}
		row--;
		col++;
	}
	return true;
}
int main()
{
	ifstream fin;
	fin.open("Grid.txt");

	char word[25];   // A character array to store the word
	char** grid;

	int test_cases = 0;
	int start = 0;
	int rows = 0, cols = 0;
	int WordRangeRow = 0;
	int WordRangeCol = 0;

	bool found = false;

	fin >> rows >> cols;  //Taking rows and columns of grid
	
	grid = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		grid[i] = new char[cols];
	}

	// Creating a two dimensional array with the rows and columns read from the file

	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			fin >> grid[i][j];
		}
	}
	//Taking the word grid as input from the file grid

	fin >> test_cases;            // the number of test cases

	for (int i = 0; i < test_cases; i++)            // The loop wil be executed till the value of i becomes equal to the number of test cases
	{
		fin >> word;
		cout << word << endl;

		for (int i = 0; i < rows && !found; i++)      // The loop will be executed till the word is found or the we have searched the whole array
		{
			for (int j = 0; j < cols && !found; j++)       
			{
				if (grid[i][j] == word[start])                      // Comparing every letter to the starting letter of the word whose location we have to find
				{
					WordRangeRow = i - (strlen(word) - 1);         // It is the space which the word would require in the right to left direction
					WordRangeCol = j - (strlen(word) - 1);         // It is the direction which the word would require in the bottom to top direction

					if ((j + (strlen(word) - 1)) < cols)          // If there is space in the left to right direction then it would search in this direction
					{
						found = LeftToRight(grid, i, j, word);
						if (found)
						{
							cout << "{" << i << "," << j << "}" << "{" << i << "," << j + (strlen(word) - 1) << "}" << endl;
							break;
						}
					}
					if (WordRangeCol >= 0)              // If there is space in the right to left direction then it would search in this direction
					{
						found = RightToLeft(grid, i, j, word);
						if (found)
						{
							cout << "{" << i << "," << j << "}" << "{" << i << "," << WordRangeCol << "}" << endl;
							break;
						}
					}
				    if ((i + (strlen(word) - 1)) < rows)        // If there is space in the Top to Bottom direction then it would search in this direction
				    {
					   found = TopToBottom(grid, i, j, word);
					    if (found)
					    {
						   cout << "{" << i << "," << j << "}" << "{" << i + (strlen(word) - 1) << "," << j << "}" << endl;
						    break;
					    }
				    }
				
			
					if ((WordRangeRow >= 0))             // If there is space in the Bottom to Top direction then it would search in this direction
					{
						found = BottomToTop(grid, i, j, word);
						if (found)
						{
							cout << "{" << i << "," << j << "}" << "{" << WordRangeRow << "," << j << "}" << endl;
							break;
						}
					}
					if ((j + (strlen(word) - 1)) < cols && (i + (strlen(word) - 1)) < rows)         // If there is space in the Yopleft to Bottomright direction then it would search in this direction
					{
						found = TopLeftToBottomRight(grid, i, j, word);
						if (found)
						{
							cout << "{" << i << "," << j << "}" << "{" << i + (strlen(word) - 1) << "," << j + (strlen(word) - 1) << "}" << endl;
							break;
						}
					}
					if ((WordRangeCol >= 0) && (WordRangeRow >= 0))       // If there is space in the Bottomright To TopLeft direction then it would search in this direction
					{
						found = BottomRightToTopLeft(grid, i, j, word);          
						if (found)
						{
							cout << "{" << i << "," << j << "}" << "{" << WordRangeRow << "," << WordRangeCol << "}" << endl;
							break;
						}
					}
					if (WordRangeCol >= 0 && (i + (strlen(word) - 1)) < rows)    // If there is space in the TopRight to BottomLeft direction then it would search in this direction
					{
						found = TopRightToBottomLeft(grid, i, j, word);
						if (found)
						{
							cout << "{" << i << "," << j << "}" << "{" << i + (strlen(word) - 1) << "," << WordRangeCol<< "}" << endl;
							break;
						}
					}
					if ((j + (strlen(word) - 1)) < rows && WordRangeRow >= 0 )       // If there is space in the Bottomleft to Topright direction then it would search in this direction
					{
						found = BottomLeftToTopRight(grid, i, j, word);
						if (found)
						{
							cout << "{" << i << "," << j << "}" << "{" << WordRangeRow << "," << j + (strlen(word) - 1) << "}" << endl;
							break;
						}
					}
				}
			}
		}
		if (!found)
		{
			cout << "Word not found " << endl;
		}
		found = false;
	}
	system("pause");
	return 0;
}