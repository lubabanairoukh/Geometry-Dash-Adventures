#pragma once

const int M_WidthWindow = 1800;
const int M_HieghtWindow = 800;
const int m_backgroundRepeated = 20;


enum Staticobject_t {

	THORNS, TRIANGLE, FLOOR, PLAYER, FLOORSTATE, RECTANGLE, SMALLRECTANGLE, STAIRS, BIGFLOORSTATE, TRIANGLESTAIRS, PORTAL, BACKTRIANGLE, MINTRIANGKE,TROPHY

};
enum Direction { Left, Right, Up };
enum BackgroundColor
{
	BLUE,
	RED
};
enum PlayerType
{
	PLAYER1, PLAYER2, PLAYER3, PLAYER4
};
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


const int WIDTHWINDOW = 1800;
const int HEIGHTWINDOW = 800;
const int ZERO = 0;
const float ZEROFLOAT = 0.0f;
const float GRAVITYWORLD = 10.0f;
const int TWO = 2;
const int STARTPLAYERLOCATION = 600;
const int PLAYERPOSITIONRESET = 550;
const int POSITIONYFLOOR = 660;
const int SIZEOFOBJECTS = 60;
const int STARINDEXX = 12;
const int STARINDEXY = 30;
const int ICONSIZE = 60;
const int FLOORBODYPOSITIONY = 70;
const int ICONSTATICNUM = 14;
const int FLOORBODYPOSITIONX = 900;
const int PLAYERNUM = 4;

/*
std::vector<std::string>m_playername = {
	"player1.png","player2.png","player3.png","player4.png"
};*/