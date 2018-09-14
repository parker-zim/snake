#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score, nTail;
int tailX[100], tailY[100];
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup(){
  gameOver = false;
  dir = STOP;
  x = width/2;
  y = height/2;
  fruitX = (rand() % width) + 1;
  fruitY = (rand() % height) + 1;
}
void Draw(){
  system("cls");

  for (int i = 0; i <= height + 1; i++){
    for (int j = 0; j <= width + 1; j++){
      if (i == 0 || i == height + 1){
        if (j == 0) {
          cout << "##";
        }
        else {
          cout << "# ";
        }
      }
      else if (j == 0){
        cout << "##";
      }
      else if (j == width + 1){
        cout << "#";
      }
      else if (i == y && j == x) {
        // head of snake
        cout << "()";
      }
      else if (i == fruitY && j == fruitX){
        //fruit
        cout << "aa";
      }
      else{
        bool poTail = false;
        for (int k = 0; k < nTail; k++){
          if (tailX[k] == j && tailY[k] == i){
            cout << "::";
            poTail = true;
          }
        }
        if (!poTail){
          cout << "  ";
      }
      }
    }
      cout << endl;
    }
  //}
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
  if ( x >= width + 1 || x <= 0 || y >= height + 1 || y <= 0){
    gameOver = true;
  }
  for (int i = 0; i < nTail; i++) {
    if (x == tailX[i] && y == tailY[i]){
      gameOver = true;
    }
  }
  if (x == fruitX && y == fruitY){
    nTail++;
    score += 10;
    fruitX = (rand() % width) + 1;
    fruitY = (rand() % height) + 1;
  }
  int prevX = tailX[0];
  int prevY = tailY[0];
  tailX[0] = x;
  tailY[0] = y;
  int prev2X, prev2Y;
  for (int i = 1; i < nTail; i++) {
    prev2X = tailX[i];
    prev2Y = tailY[i];
    tailX[i] = prevX;
    tailY[i] = prevY;
    prevX = prev2X;
    prevY = prev2Y;
  }
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
}

int main() {
  srand(time(0));
  Setup();
  while(!gameOver){
    Draw();
    Input();
    Logic();
    Sleep(75);
  }

  return 0;
}
