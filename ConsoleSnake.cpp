#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;
//Function definitions
char** CreateMap();
void UpdateMap(char**);
void DisplayView(char**);
void AskToContinue();
void GetUserInput();
void Intro();
void Setup();

enum Direction
{
	UP, DOWN, LEFT, RIGHT
};
Direction direction;

//Starting coordinates for snake / snake head
int x = 3;
int y = 3;
int mouseX, mouseY;
char** map;
//Contains coordinates for each snake body part
int* snakeX = new int[400];
int* snakeY = new int[400];

int main()
{
	Intro();

	//Game loop
	bool gameLoop = true;
	while (gameLoop)
	{
		GetUserInput();
		UpdateMap(map);
		DisplayView(map);
		Sleep(20);
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
				direction = UP;
				break;
			case 'a':
				direction = LEFT;
				break;				
			case 's':
				direction = DOWN;
				break;
			case 'd':
				direction = RIGHT;
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
	switch(direction)
	{
		case UP:
			x--;
			break;
		case LEFT:
			y--;
			break;				
		case DOWN:
			x++;
			break;
		case RIGHT:
			y++;
			break;
	}

	//Move snake's head to opposite side of map if touches wall
	if(x >= 19)
	{
		x = 1;
	}
	if(y >= 19)
	{
		y = 1;
	}
	if(x <= 0)
	{
		x = 19;
	}
	if(y <= 0)
	{
		y = 19;
	}

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
void Intro()
{
	system("CLS");
	cout << "\n\n\n\n\n   Welcome to snake.\n\n   Use the w,a,s and d keys to move.\n\n   At any point during gameplay, press x to exit.\n\n\n\n      Press any key to start. . .\n";
	_getch();
	system("CLS");
	Setup();
}
void Setup()
{
	//Create map
	map = CreateMap();
	//Food
	srand(time(NULL));
	//Make mouse coordinates the map width / height
	mouseX = (rand() % 19)+1;//dont have it spawn on 0
	mouseY = (rand() % 19)+1;
	if(mouseX==19){mouseX--;}//dont have it spawn on max
	if(mouseY==19){mouseY--;}
	direction = RIGHT;
}
