#include <iostream>
#include <conio.h> // for keypress
#include <windows.h>
#include<time.h>

using namespace std;

#define MAX_LENGTH 1000 // macro for max length

const char DIR_UP = 'U';
const char DIR_DOWN = 'L';
const char DIR_LEFT = 'D';
const char DIR_RIGHT = 'R';

int consol_width, consol_Height;

// to initlize Screen

void initScreen()
{

    // return console handle
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // creating object of C_S_B_I class
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(hconsole, &csbi);

    // Extractiong height and width
    consol_Height = csbi.srWindow.Bottom - csbi.srWindow.Top;

    consol_width = csbi.srWindow.Right - csbi.srWindow.Left;
}

// much Security not needed on Point so declared structure
struct Point
{
    int x;
    int y;
    Point() {}

    Point(int x, int y)
    {
        x = x;
        y = y;
    }
};

// snake class
class Snake
{
    int length;
    char direction;

public:
    Point body[MAX_LENGTH];

    Snake(int x, int y)
    {
        length = 1;
        // specifying starting length and point
        body[0] = Point(x, y);
        direction = DIR_RIGHT;
    }

    ~Snake()
    {
        
    }

    int getLength()
    {
        return length;
    }

    void changeDir(char newDir)
    {
        // avoid 180 degree turn

        if (newDir == DIR_UP && direction != DIR_DOWN)
        {
            direction = newDir;
        }
        else if (newDir == DIR_DOWN && direction != DIR_UP)
        {
            direction = newDir;
        }
        else if (newDir == DIR_LEFT && direction != DIR_RIGHT)
        {
            direction = newDir;
        }
        else if (newDir == DIR_RIGHT && direction != DIR_LEFT)
        {
            direction = newDir;
        }
    }



// moving Snake and checking self bite
    bool move(Point food){
        for(int i=length-1;i>0;i--){
            body[i]=body[i-1];
        }  


        switch(direction){
            int val;
            case DIR_UP:
                body[0].y--;
                break;
            case DIR_DOWN:
                body[0].y++;
                break;
            case DIR_RIGHT:
                body[0].x++;
                break;
            case DIR_LEFT:
                body[0].x--;
                break;

        } 

        //snake bite itself
        for(int i=1;i<length;i++){
            if(body[0].x==body[i].x && body[0].y == body[i].y){
                return false;
            }
        }

        //snake eats food

        if(food.x == body[0].x && food.y == body[0].y){
            body[length]=Point(body[length-1].x,body[length-1].y);
            length++;
        }


        return true;
    }
};

class Board
{
    Snake *snake;

    const char SNAKE_BODY = 'O';

    Point food;

    const char FOOD = 'o';

    int score;

public:
    Board()
    {
        spawnfood();

        snake = new Snake(10, 10);

        score = 0;
    }
    ~Board()
    {
        delete snake;
    }

    int getScore()
    {
        return score;
    }

    void spawnfood()
    {
        int x = rand() % consol_width; // 0-console height
        int y = rand() % consol_Height;
        food=Point(x,y);
    };

    void gotoxy(int x, int y)
    {
        // moving  to  a point on board

        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

    void draw()
    {
        // to clear Screen first before
        system("cls");

        // printing

        for (int i = 0; i < snake->getLength(); i++)
        {
            gotoxy(snake->body[i].x, snake->body[i].y);
            // printing
            cout << SNAKE_BODY;
        }

        gotoxy(food.x, food.y);
        cout << FOOD;
    }

    bool update(){
        bool isAlive = snake->move(food);

        if(!isAlive){
            return false;
        }

        if(food.x == snake->body[0].x && food.y == snake->body[0].y){
            score++;
            spawnfood();
        }


        return true;
        
    }

    void getInput(){
        //return true if any key is pressed  kbhit
        if(kbhit){
            int key = getch();
            if(key == 'w' || key == 'W'){
                snake->changeDir(DIR_UP);
                
            }
            else if(key == 's' || key == 's'){
                snake->changeDir(DIR_DOWN);

            }
            else if(key == 'a' || key == 'A'){
                snake->changeDir(DIR_LEFT);

            }
            else if(key == 'd' || key == 'D'){
                snake->changeDir(DIR_RIGHT);

            }
        }
    }

};

int main()
{

    srand(time(0));

    initScreen();

    Board *board = new Board();

    while(board->update()){
        board->getInput();
        board->draw();
        Sleep(800);

    }

    cout<<"Game Over ";

    return 0;
}