#include <bits/stdc++.h>
#include <conio.h> // for function like khbit() and getch()
using namespace std;

// global variables
bool gameover;
const int width = 20; 
const int height = 15;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; //snake coordinates
int snakeLen;

// Controls
enum movements
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
movements mov;

// Setting up the game
void Setup()
{
    gameover = false;

    mov = STOP;

    x = width / 2;

    y = height / 2;

    fruitX = rand() % width; //placing fruit in a random place

    fruitY = rand() % height;
    score = 0;
}

// Displaying the game
void Display()
{
    system("cls");

    for (int i = 0; i < width + 2; i++)

        cout << "#";

    cout << endl;
    //Inside of game
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            if (j == 0)

                cout << "#";

            if (i == y && j == x)

                cout << "^"; // snake's head

            else if (i == fruitY && j == fruitX)

                cout << "O"; // fruit

            else
            {

                bool print = false;

                for (int k = 0; k < snakeLen; k++)
                {

                    if (tailX[k] == j && tailY[k] == i)
                    {

                        cout << "*"; // adding snake * in snake's lenght
                        print = true;
                    }
                }

                if (!print)
                    cout << " ";
            }

            if (j == width - 1)

                cout << "#";
        }

        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)

        cout << "#";

    cout << endl;

    cout << "Score:" << score << endl;
}

void moves()
{

    if (_kbhit())   // checks if key is not pressed
    {

        switch (_getch()) //takes the input
        {

        case 'a':

            mov = LEFT;

            break;

        case 'd':

            mov = RIGHT;

            break;

        case 'w':

            mov = UP;

            break;

        case 's':

            mov = DOWN;

            break;

        case 'x':

            gameover = true;

            break;
        }
    }
}

void algorithm()
{

    int prevX = tailX[0];

    int prevY = tailY[0];

    int tempX, tempY;

    tailX[0] = x;

    tailY[0] = y;

    for (int i = 1; i < snakeLen; i++)
    {

        tempX = tailX[i];

        tempY = tailY[i];

        tailX[i] = prevX;

        tailY[i] = prevY;

        prevX = tempX;

        prevY = tempY;
    }

    switch (mov)
    {

    case LEFT:

        x--;

        break;

    case RIGHT:

        x++;

        break;

    case UP:

        y--;

        break;

    case DOWN:

        y++;

        break;

    default:

        break;
    }
    //in the edge
    if (x >= width)
        x = 0;
    else if (x < 0)
        x = width - 1;

    if (y >= height)
        y = 0;
    else if (y < 0)
        y = height - 1;

    for (int i = 0; i < snakeLen; i++)

        if (tailX[i] == x && tailY[i] == y)
            gameover = true;

    if (x == fruitX && y == fruitY) // getting fruit
    {

        score += 10; //updating score 

        fruitX = rand() % width;

        fruitY = rand() % height;

        snakeLen++; //incrementing length of snake
        ;
    }
}

int main()
{
    Setup(); // initializing 

    while (!gameover)
    {

        Display();

        moves();

        algorithm();
    }

    return 0;
}
