#include <iostream>
#include <vector>

using namespace std;

//struct Position
//{
//	int X;
//	int Y;
//};
//
//class Actor
//{
//public:
//	Position Pos;
//	int Shape;
//};
//
//class Player : public Actor
//{
//public:
//	bool IsArrive; 
//	void MoveUp() {}
//	void MoveDown() {}
//	void MoveLeft() {}
//	void MoveRight() {}
//};
//
//class Monster : public Actor
//{
//public:
//	void MoveUp() {}
//	void MoveDown() {}
//	void MoveLeft() {}
//	void MoveRight() {}
//};
//
//class Wall : public Actor
//{
//public:
//	bool CanPass;
//};
//
//class Floor : public Actor
//{
//public:
//	bool CanPass;
//};
//
//class World
//{
//public:
//	Wall Walls[100];
//	Floor Floors[100];
//	int Size;
//	Actor Actors[100];
//	Position Destination[100];
//	bool IsEnd;
//};
//
//class Engine
//{
//public:
//	World Worlds;
//
//	void Run()
//	{
//		while(true)
//		{
//			void Input();
//			void Tick();
//			void Render();
//		}
//	}
//};

//function overloading, overriding
//name mangling(오버로딩된 함수가 내부에서 동작할때 이름을 바꿔서 실행)

//template function 개수 제한X
//metaprogramming
//template<typename T, typename Y>
//
//T Add(T A, Y B)
//{
//	return A + B;
//}
//
//int main()
//{
//	cout << Add<int, int>(1, 2) << endl;
//	cout << Add<float, float>(3.0f, 2.2f) << endl;
//	cout << Add<int, float>(1, 2.2f) << endl;
//
//	return 0;
//}

//헤더 파일 명세
//cpp 파일 구현

#include "Player.h"
#include "Monster.h"

int main()
{
	Player* MyPlayer = new Player();
	vector<Monster*> MyMonster;

	MyMonster.push_back(new Monster());
	MyMonster.push_back(new Monster());
	MyMonster.push_back(new Monster());
	MyMonster.push_back(new Monster());

	MyPlayer->Move();
	
	for (int i = 0; i < MyMonster.size(); ++i)
	{
		MyMonster[i]->Move();
		MyMonster[i]->Attack();
	}

	for (int i = 0; i < MyMonster.size(); ++i)
	{
		delete MyMonster[i];
	}

	delete MyPlayer;

	return 0;
}