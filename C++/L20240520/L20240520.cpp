#include <iostream>
#include <string>

using namespace std;

//custom DataType
struct Vector2D
{
	int X;
	int Y;
};

struct Actor //sizeof(Actor) 12 ����ü ���� ū �ڷ����� �������� �е��Ѵ�.	
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
////UE 0 ~ 1 % Percent // Led ���, for GPU / �ϵ��� ������� ��� ����
//struct Color
//{
//	float R;
//	float G;
//	float B;
//};

int main()
{
	Actor* Player = new Actor; //Load / ������
	(*Player).Position.X;
	Player->Position.X = 10;
	Player->Position.Y = 10;
	Player->Shape = 'P';
	Player->name = "�ٺ�";

	cout << Player->Position.X << endl;

	delete Player; //Save / �Ҹ���

	return 0;
}