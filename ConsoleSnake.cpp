#include <iostream>

using namespace std;

int main()
{
	char** map = new char*[20];
	int x, y;
	x = 3;
	y = 3;

	for (int i = 0; i < 20; i++)
	{
		map[i] = new char[20];
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


	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Press any key and then enter to exit." << endl;
	char continueKey;
	cin >> continueKey;

	return 0;
}