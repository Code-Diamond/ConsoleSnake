#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;

void ShiftSnake(int* snake, int s, int newPlace);
void PrintSnake();

void Intro();
void Setup();
char** CreateMap(char** map);
void UpdateMap();
void DisplayView();
void GetUserInput();


//Direction enumerator
enum Direction
{
	UP, DOWN, LEFT, RIGHT
};

//SNAKE
//Create Dynamic Arrays
int* snakeX = new int[400];
int* snakeY = new int[400];
//Starting Position for snake head
int snakeSize = 1;

//Map, score and current direction
char** map;
int score = 0;
Direction direction;

//Mouse coordinates
int mouseX, mouseY;


int main(void)
{
	Intro();
	// snakeX[1] = 5;
	// snakeX[2] = 7;
	// snakeX[3] = 9;
	// size = 4;

	bool gameLoop = true;
	while (gameLoop)
	{
		GetUserInput();
		UpdateMap();
		DisplayView();
		Sleep(35);
	}
	// ShiftSnake(snakeX, size, snakeX[0]+1);
	// PrintSnake();

	return(0);

}

void ShiftSnake(int* snake, int s, int newPlace)
{
	//Temporary holders for previous numbers in the array
	int t;
	int t2;
	t = snake[0];

	//Shift array to the right and except first and last elements
	for (int i = 0; i < s - 1; i++)
	{
		t2 = snake[i + 1];
		snake[i + 1] = t;
		t = t2;
	}

	//Assign first element
	snake[0] = newPlace;

	// //Assign last element
	// snake[s] = t;

	// size++;

}
//Testing function
void PrintSnake()
{
	for (int i = 0; i < snakeSize; i++)
	{
		cout << snakeX[i] << ' ';
	}
	cout << endl;
}








void Intro()
{
	system("CLS");
	cout << "\n\n\n\n\n   Welcome to snake.\n\n   Use the w,a,s and d keys to move.\n\n   At any point during gameplay, press x to exit.\n\n\n    If you touch the walls at any point you lose.\n      Press any key to start. . .\n";
	_getch();
	system("CLS");
	Setup();
}
//Initial Setup
void Setup()
{
	//Create map
	map = CreateMap(map);
	//Food
	srand(time(NULL));
	//Make mouse coordinates the map width / height
	mouseX = (rand() % 19) + 1;//dont have it spawn on 0
	mouseY = (rand() % 19) + 1;
	if (mouseX == 19) { mouseX--; }//dont have it spawn on max
	if (mouseY == 19) { mouseY--; }
	direction = RIGHT;
	snakeX[0] = 3;
	snakeY[0] = 3;
}
//Initial creation of the game map array
char** CreateMap(char** map)
{
	map = new char*[20];
	for (int i = 0; i < 20; i++)
	{
		map[i] = new char[20];
	}
	return map;
}

//Get the user input
void GetUserInput()
{
	if (_kbhit())
	{
		switch (_getch())
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

//Logic for updating the game map
void UpdateMap()
{
	int lastPositionX = snakeX[snakeSize - 1];
	int lastPositionY = snakeY[snakeSize - 1];

	//Move the snake based on direction
	switch (direction)
	{
	case UP:
		ShiftSnake(snakeX, snakeSize, snakeX[0] - 1);
		for (int i = 1; i < snakeSize; i++)
		{
			//UP
			if (snakeY[i] > snakeY[0])
			{
				snakeY[i]--;
			}
			//UP
			if (snakeY[i] < snakeY[0])
			{
				snakeY[i]++;
			}
		}
		// x--;
		break;
	case LEFT:
		ShiftSnake(snakeY, snakeSize, snakeY[0] - 1);
		for (int i = 1; i < snakeSize;i++)
		{
			//LEFT
			if (snakeX[i] > snakeX[0])
			{
				snakeX[i]--;
			}
			//LEFT
			if (snakeX[i] < snakeX[0])
			{
				snakeX[i]++;
			}
		}
		// y--;
		break;
	case DOWN:
		ShiftSnake(snakeX, snakeSize, snakeX[0] + 1);
		for (int i = 1; i < snakeSize;i++)
		{
			//DOWN
			if (snakeY[i] < snakeY[0])
			{
				snakeY[i]++;
			}
			//DOWN
			if (snakeY[i] > snakeY[0])
			{
				snakeY[i]--;
			}

		}
		// x++;
		break;
	case RIGHT:
		ShiftSnake(snakeY, snakeSize, snakeY[0] + 1);
		for (int i = 1; i < snakeSize;i++)
		{
			//RIGHT
			if (snakeX[i] < snakeX[0])
			{
				snakeX[i]++;
			}
			//RIGHT
			if (snakeX[i] > snakeX[0])
			{
				snakeX[i]--;
			}
		}
		// y++;
		break;
	}
	//Lose game if snake body if touching wall switch comment for wall to reposition snake
	//for(int i = 0; i < size; i++)
	//{
	if (snakeX[0] >= 19)//if(snakeX[i] >= 19)
	{
		cout << "\n\n             GAME OVER!" << endl << endl << "   Press any key to exit.";
		_getch();
		exit(0);
		//snakeX[i] = 1;
	}
	if (snakeY[0] >= 19)
	{
		cout << "\n\n             GAME OVER!" << endl << endl << "   Press any key to exit.";
		_getch();
		exit(0);
		//snakeY[i] = 1;

	}
	if (snakeX[0] <= 0)
	{
		cout << "\n\n             GAME OVER!" << endl << endl << "   Press any key to exit.";
		_getch();
		exit(0);
		//snakeX[i] = 19;
	}
	if (snakeY[0] <= 0)
	{
		cout << "\n\n             GAME OVER!" << endl << endl << "   Press any key to exit.";
		_getch();
		exit(0);
		//snakeY[i] = 19;
	}
	//}





	//Update the map
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			bool printed = false;

			//Borders
			if (i == 0 || i == 19)
			{
				map[i][j] = '-';
				printed = true;
			}
			if (j == 0 || j == 19)
			{
				map[i][j] = '|';
				printed = true;
			}
			//Mouse
			if (i == mouseX && j == mouseY)
			{
				map[i][j] = 'M';
				printed = true;
			}

			//Snake
			for (int k = 0; k < snakeSize; k++)
			{
				//Check if mouse eaten then -v
				int x = snakeX[k];
				int y = snakeY[k];
				//If its the snake
				if (i == x && j == y)
				{
					//If its the snake eating mouse
					if (i == mouseX && j == mouseY)
					{
						if (k == 0)
						{
							map[i][j] = 'S';
						}
						else
						{
							map[i][j] = 'O';
						}

						mouseX = (rand() % 19) + 1;
						mouseY = (rand() % 19) + 1;
						if (mouseX == 19) { mouseX--; }//dont have it spawn on max
						if (mouseY == 19) { mouseY--; }
						score += 100;

						snakeX[snakeSize - 1] = lastPositionX;
						snakeY[snakeSize - 1] = lastPositionY;
						snakeSize++;
						printed = true;
					}
					else
					{
						if (k == 0)
						{
							map[i][j] = 'S';
						}
						else
						{
							map[i][j] = 'O';
						}
						printed = true;
					}
				}


			}
			//Blank tile
			if (printed == false)
			{
				map[i][j] = ' ';
			}


		}
	}

}

//Prints the map
void DisplayView()
{
	//Clear screen
	system("CLS");
	//Print map
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "\n              Score: " << score << endl;
}
