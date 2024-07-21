#include "Board.h"


// build the level by the level number.
Board::Board(b2World& world, std::string level)
{


	initStaticObject(world);

	ifstream file; //to read from file.

	file.open(level + ".txt"); //the name of the file.

	if (!file.is_open())
		cout << "The level of the game is not define\n";

	copyFileVector(file, world); //copy to the file vector.
}

// copy the level string from file to the string vector.
void Board::copyFileVector(ifstream& file, b2World& world)
{
	string line;

	file >> m_length >> m_width;

	getline(file, line); //eat enter;

	for (int index = 0; index < m_length; index++) // build the map
	{
		getline(file, line);
		for (int y = 0; y < line.size(); y++)
			buildObjects(pair<int, int>(index, y), line[y], world);
	}

}

void Board::buildObjects(pair<int, int> loc, char icon, b2World& world)
{

	sf::Vector2f location;


	location.x = loc.second * SIZEOFOBJECTS;
	location.y = (loc.first + 1) * SIZEOFOBJECTS;

	

	switch (icon)
	{
	case 'T':
		m_board.push_back(std::make_unique<Triangle>(world, location, TRIANGLE));
		break;
	case 't':
		std::cout << "hi" << std::endl;
		m_board.push_back(std::make_unique<Triangle>(world, location, MINTRIANGKE));;
		break;
	case 'r':
		m_board.push_back(std::make_unique<Rectangle>(world, location, RECTANGLE));
		break;
	case 'p':
		m_board.push_back(std::make_unique<Rectangle>(world, location, SMALLRECTANGLE));
		break;
	case 'h':
		m_board.push_back(std::make_unique<Thorns>(world, location));
		break;
	case 'f':
		m_board.push_back(std::make_unique<Rectangle>(world, location, FLOORSTATE));
		break;
	case'F':
		m_board.push_back(std::make_unique<Rectangle>(world, location, BIGFLOORSTATE));
		break;
	case's':
		location.x = location.x+ STARINDEXX;
		location.y = location.y - STARINDEXY;
		m_board.push_back(std::make_unique<Rectangle>(world, location, STAIRS));
		break;
	case'b':
		location.y = location.y - ICONSIZE;
		m_board.push_back(std::make_unique<Triangle>(world, location, BACKTRIANGLE));;
		break;
	case 'w':
 		m_board.push_back(std::make_unique<Trophy>(world, location));
		break;
	case 'B':
		location.y = location.y - (ICONSIZE/TWO);
		m_board.push_back(std::make_unique<Portal>(world, location));
		break;
	case 'd':
		m_board.push_back(std::make_unique<Doublejump>(world, location));
		break;
	default:
		break;
	}

}

void Board::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < m_board.size(); i++)
	{
		m_board[i]->draw(window);
	}
}


void Board::initStaticObject(b2World& world)
{

	sf::Vector2f position;

	for (int i = 0; i < m_backgroundRepeated; i++)
	{

		position.x = i * WIDTHWINDOW;
		position.y = POSITIONYFLOOR;
		m_board.push_back(std::make_unique<Floor>(world, position));

	}
}



