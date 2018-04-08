#include <iostream>
#include <conio.h>
using namespace std;

//Function definitions
char** CreateMap();
void UpdateMap(char**);
void DisplayView(char**);
void AskToContinue();
void GetUserInput();


//Starting coordinates
int x = 3;
int y = 3;

//Contains coordinates for each snake body part
int* snakeX = new int[400];
int* snakeY = new int[400];

//Create enumerator for directions
enum Direction 
{
	UP, DOWN, LEFT, RIGHT
};
Direction currentDirection;

int main()
{
	//Create map
	char** map = CreateMap();
	
	bool gameLoop = true;
	//Game loop
	while (gameLoop)
	{
		//TODO: Need to retrieve user input 'behind the scenes'
		GetUserInput();

		UpdateMap(map);
		DisplayView(map);
		//If snake accidently hits himself
		
	}

	return 0;
}
//Get the user input
void GetUserInput()
{
	if (_kbhit())
	{
		switch(_getch())
		{
			case 'w':
				x--;
				break;
			case 'a':
				y--;
				break;				
			case 's':
				x++;
				break;
			case 'd':
				y++;
				break;
		}
	}
}

//Initial creation of the gmae map array
char** CreateMap()
{
	char** map = new char*[20];


	for (int i = 0; i < 20; i++)
	{
		map[i] = new char[20];
	}

	return map;
}
//Logic for updating the game map
void UpdateMap(char** map)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//If its top border
			if (i == 0)
			{
				map[i][j] = '#';
			}
			else
			{
				//Left border
				if (j == 0)
				{
					map[i][j] = '#';
				}
				else
				{
					//Bottom border
					if (i == 19)
					{
						map[i][j] = '#';
					}
					else
					{
						//Top border
						if (j == 19)
						{
							map[i][j] = '#';
						}
						else //Other spaces
						{
							//Snake
							if (i == x && j == y)
							{
								map[i][j] = 'O';
							}
							else
							{
								map[i][j] = ' ';
							}
						}
					}
				}
			}
		}
	}
}
//Prints the map
void DisplayView(char** map)
{
	//Clear screen
	system("CLS");
	//Print map
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
//Ask user to press any key and enter to continue
void AskToContinue()
{
	cout << "Press any key and then enter to exit." << endl;
	char continueKey;
	cin >> continueKey;
}
