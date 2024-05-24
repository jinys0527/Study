#include <iostream>
#include <string>

using namespace std;

//custom DataType
struct Vector2D
{
	int X;
	int Y;
};

struct Actor //sizeof(Actor) 12 구조체 내에 큰 자료형을 기준으로 패딩한다.	
{
	Vector2D Position;
	char Shape;
	string name;
};

////Photoshop 0~255, for CPU
//struct Color
//{
//	unsigned char R;
//	unsigned char G;
//	unsigned char B;
//};
//
////UE 0 ~ 1 % Percent // Led 밝기, for GPU / 하드웨어에 관계없이 사용 가능
//struct Color
//{
//	float R;
//	float G;
//	float B;
//};

int main()
{
	Actor* Player = new Actor; //Load / 생성자
	(*Player).Position.X;
	Player->Position.X = 10;
	Player->Position.Y = 10;
	Player->Shape = 'P';
	Player->name = "바보";

	cout << Player->Position.X << endl;

	delete Player; //Save / 소멸자

	return 0;
}