#pragma once
#include <iostream>

const int BLACKCIRCLES = 14;


const int XSTART = 200;
const int YSTART = 50;
const int ADDX = 20;
const int ADDY = 60;

const std::pair<int, int> STARTCAT( 5,5 );




const int ROWS = 11;
const int COLS = 11;


const int iconSize = 14;

const int W_WIDTH = 1300;
const int W_LENGTH = 800;



const int DIS = 121;



const int m_SizeMusicP = 70;






const int MenuStart = 2;
const int M_WidthWindow = 1300;
const int M_HieghtWindow = 800;
const float ICON_SIZE = 170;
const int m_ToolBar = 100;
constexpr auto ShapeSize = 50.f;
constexpr auto ShapeSpeed = ShapeSize * 3;
const int withouttoolbar = 1200;
const int m_HiegthText = M_HieghtWindow - m_ToolBar;
const int TIME = 60;
const int SIZEPIC = 46;
const int MENUTEXT = 2;
const int MENUSTART = 3;
const int SIZECHARACTER = 35;
const int P_SIZE = 50;
const int LEFTTIME = 10;
const int TOOLBARPLAYER = 40;
const int SIZEY = 40;

const int NumOfObjects = 14;
const int MUSICONOFF = 2;
enum  Objects {
	KingObj, MageObj, WarriorObj, ThiefObj, FireObj, WallObj, KeyObj, GateObj, OrcObj, TelObj, ChairKingObj,
	EnemyObj, ThiefWithKey, GiftsObj
};
enum gifts {
	EnTime, DECTIME, ERASEO, NONE
};



















// game consts
const int PIPE_TYPE_AMOUNT = 4;
const int NEIGHBOR_AMOUNT = 4;
const int MAX_POSSIBLE_ROTATIONS = 4;
const int SEED = 17;
const int MAX_HEIGHT_BOARD = 7;
const int MAX_WIDTH_BOARD = 15;
const int SIZE_OFFSET = 5;

// window measurements

const int CAPTION_HEIGHT = 100;


// map measurements
const int MAP_HEIGHT = 800;
const int MAP_WIDTH = 800;
const int HEIGHT_OFFSET = 100;
const int WIDTH_OFFSET = 300;

// rotation measurements
const int ANGLE = 90;
const int PARTIAL_ROTATION = 45;

// for start screen
const int HEADER_SIZE = 60;
const int REG_CHAR_SIZE = 100;
const float OUTLINE_THICKNESS = 5.0;
const float BOLD_OUTLINE = 10.0;

const sf::Vector2f RECT_SIZE = { 140.0, 60.0 };

// for caption
const int CAP_CHAR_SIZE = 50;
const float CAP_OUTLINE_THICKNESS = 3.0;
const int CAPTION_OFFSET = 200;
const auto RECTANGLE_POSITION = sf::Vector2f{ 190.f, 65.f };
const int SMALL_OFFSET = 10;

enum class Direction
{
	Start, Right, Down, Left, Up, End
};
inline Direction operator++(Direction& x)
{
	return x = (Direction)(std::underlying_type<Direction>::type(x) + 1);
}

enum class Type
{
	Origin, Destination, TwoWayCroocked, TwoWayStraight, ThreeWayPipe, FourWayPipe,
	Wallpaper
};
















