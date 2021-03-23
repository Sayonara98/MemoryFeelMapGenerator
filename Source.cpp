#include <iostream>

int const n = 8;
int arr[n][n];
int step = 1;
int x = 0;
int y = 0;

bool isQualified(int x, int y)
{
	if (arr[x][y] != 0 || x < 0 || x > n || y < 0 || y > n)
		return false;
	return true;
}

bool canTurnLeft(int x, int y)
{
	if (y - 1 < 0 || arr[x][y-1] != 0 || arr[x - 1][y - 1] != 0)
		return false;
	return true;
}

bool canTurnRight(int x, int y)
{
	if (y + 1 > n || arr[x][y + 1] != 0 || arr[x - 1][y + 1] != 0)
		return false;
	return true;
}

void move(int x, int y)
{
	arr[x][y] = step;
	step++;
}

void forward()
{
	x++;
	move(x, y);
}

void turnLeft()
{
	y--;
	move(x, y);
}

void turnRight()
{
	y++;
	move(x, y);
}

int main()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	srand(time(NULL));
	y = rand() % n;
	x = 0;
	move(x, y);
	forward();

	while (x < n - 1)
	{
		int tmp = rand() % 2;
		if (tmp == 1)
		{
			if (isQualified(x + 1, y))
				forward();
			else if (canTurnRight(x, y))
				turnRight();
			else if (canTurnLeft(x, y))
				turnLeft();
		}
		else
		{
			if (tmp == 0)
			{
				if (canTurnLeft(x, y))
					turnLeft();
				else if (canTurnRight(x, y))
					turnRight();
			}
			else
			{
				if (canTurnRight(x, y))
					turnRight();
				else if (canTurnLeft(x, y))
					turnLeft();
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
				std::cout << "* ";
			else
				std::cout << "$ ";
		}
		std::cout << std::endl;
	}

	return 0;
}