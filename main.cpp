#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup(){
  gameOver = false;
  dir = STOP;
  x = width/2;
  y = height/2;
  fruitX = rand() % width;
  fruitY = rand() % height;
}
void Draw(){
  system("cls");

  for (int i = 0; i <= height + 1; i++){
    if (i == 0 || i == height + 1){
      for (int j = 0; j <= width + 1; j++){
        cout << "# ";
      }
      cout << endl;
    }
    else {
    for (int j = 0; j <= width; j++){
      if (j == 0){
        cout << "##";
      }
      if (j == width){
        cout << "#";
      }
      if (i == y && j == x) {
        // head of snake
        cout << "()";
      }
      else if (i == fruitY && j == fruitX){
        //fruit
        cout << "aa";
      }
      else{
        cout << "  ";
      }
      }
      cout << endl;
    }
  }
    cout << endl;
    cout << "Score: " << score;
  }


void Input() {
  if (_kbhit()){
    switch (_getch()){
      case 'a':
        dir = LEFT;
        break;
      case 'd':
        dir = RIGHT;
        break;
      case 'w':
        dir = UP;
        break;
      case 's':
        dir = DOWN;
        break;
      case 'q':
        gameOver = true;
        break;
      default:
        break;

    }
  }
}

void Logic(){
  switch(dir){
    case LEFT:
      x--;
      //x--;
      break;
    case RIGHT:
      x++;
      //x++;
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

  if ( x >= width || x < 0 || y > height || y <= 0){
    gameOver = true;
  }
  if (x == fruitX && y == fruitY){
    score++;
    fruitX = rand() % width;
    fruitY = rand() % height;
  }
}

int main() {
  Setup();
  while(!gameOver){
    Draw();
    Input();
    Logic();
    Sleep(10);
  }
  return 0;
}
