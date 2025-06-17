#include <stdio.h>
#include <stdbool.h>

#define ENTITY_COUNT 8

typedef struct Vec2
{
  int x;
  int y;
} Vec2;

typedef struct fVec2
{
  float x;
  float y;
} fVec2;

typedef struct RGB_Color
{
  unsigned char r;
  unsigned char g;
  unsigned char b;
} RGB_Color;

typedef struct Direction
{
  bool top;
  bool down;
  bool left;
  bool right;
} Direction;

typedef struct Entity
{
  Vec2 pos;
  Direction dir;
  RGB_Color color;
} Entity;

typedef struct Game_Engine
{
  Entity entities[ENTITY_COUNT];
} Game_Engine;

Game_Engine g;

void Game_Init(void)
{

}

void Game_Loop(void)
{

}

void Game_Over(void)
{

}

void Game_AddEntity(Vec2 v, RGB_Color color)
{

}

int main(void)
{

}
