#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
//Function definitions
char** CreateMap();
void UpdateMap(char**);
void DisplayView(char**);
void AskToContinue();
void GetUserInput();
void intro();
//Starting coordinates for snake / snake head
int x = 3;
int y = 3;
int mouseX, mouseY;
//Contains coordinates for each snake body part
int* snakeX = new int[400];
int* snakeY = new int[400];

int main()
{
	intro();

	//Create map
	char** map = CreateMap();
	//Food
	srand(time(NULL));
	//Make mouse coordinates the map width / height
	mouseX = (rand() % 19)+1;//dont have it spawn on 0
	mouseY = (rand() % 19)+1;
	if(mouseX==19){mouseX--;}//dont have it spawn on max
	if(mouseY==19){mouseY--;}

	//Game loop
	bool gameLoop = true;
	while (gameLoop)
	{
		GetUserInput();
		UpdateMap(map);
		DisplayView(map);
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
			case 'x':
				system("CLS");
				exit(0);
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
								if(i == mouseX && j == mouseY)
								{
									map[i][j] = 'O';
									mouseX = (rand() % 19)+1;
									mouseY = (rand() % 19)+1;
									if(mouseX==19){mouseX--;}//dont have it spawn on max
									if(mouseY==19){mouseY--;}
								}
								else
								{
									map[i][j] = 'O';
								}

							}
							else
							{
								//Food
								if(i == mouseX && j == mouseY)
								{
									map[i][j] = '+';
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
void intro()
{
	cout << "Welcome to snake.\nUse the w,a,s and d keys to move.\nPress any key to start. . .";
	_getch();
	system("CLS");
}
