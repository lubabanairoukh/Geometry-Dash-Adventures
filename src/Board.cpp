#include "Board.h"

<<<<<<< HEAD

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
=======
Board::Board()
{
	setArraySurround();

	m_blackCircles = BLACKCIRCLES;
	m_newlevel = true;
	m_gameover = false;
	setBlackCircles();
	drawSquares();
	
}

void Board::setArraySurround()
{
	std::pair<int, int>m_index(1, 10);
	for (int i = 0; i < 11; i++)
		m_array.push_back(std::pair<int, int>(0, i));

	for (; m_index.first < 11; m_index.first++)
		m_array.push_back(std::pair<int, int>(m_index.first, 0));

	m_index.first = 1;

	for (; m_index.first < 11; m_index.first++)
		m_array.push_back(std::pair<int, int>(m_index.first, 10));

	m_index.first = 10;
	m_index.second = 1;

	for (; m_index.second < 10; m_index.second++)
		m_array.push_back(std::pair<int, int>(m_index.first, m_index.second));
}

void Board::setBlackCircles()
{
	bool blacrturn = false;
	m_blackcircle.clear();
	m_blackcircle.resize(m_blackCircles);
	for (int i = 0; i < m_blackCircles; i++)
	{
		blacrturn = false;
		int y = (rand() % (10 + 1));
		int w = (rand() % (10 + 1));
		if (y != 5 && w != 5) {
			for (int i = 0; i < m_blackcircle.size(); i++)
				if (m_blackcircle[i].first == y && m_blackcircle[y].second == w)
					blacrturn = true;

			if (!blacrturn)
				m_blackcircle.push_back({ y,w });
			else
				i -= 1;
		}
		else
			i -= 1;
	}
}


//draw the grid of the level
void Board::drawSquares()
{
	m_newlevel = false;
	m_gameover = false;
	m_circles.clear();
	m_circles.resize(ROWS);
	
	m_xStart = XSTART;
	m_yStart = YSTART;
	for (int y = 0; y < ROWS; y++) {
		m_xStart = XSTART;
		if (y != 0 && y % 2 != 0)
		{
			m_xStart += YSTART;
		}
		for (int i = 0; i < COLS; i++) {
			m_circles[y].push_back(std::make_unique<Circles>(sf::Vector2f(m_xStart + (i * P_SIZE), m_yStart),
				std::pair<int, int>(y, i)));
			m_xStart += ADDX;

		}
		m_yStart += ADDY;
	}

	for (int i = 0; i < m_blackcircle.size(); i++)
		m_circles[m_blackcircle[i].first][m_blackcircle[i].second]->changeCircleColor();


	m_Cat.setPosition(m_circles[STARTCAT.first][STARTCAT.second]->getPosition(),
		                                                              std::pair<int,int>(STARTCAT.first, STARTCAT.second));

	for (int i = 1; i < m_circles.size() - 1; i++)
		for (int y = 1; y < m_circles[i].size() - 1; y++)
			if (i == 0 || i % 2 == 0)
				m_circles[i][y]->setNeighborsEven(i, y);
			else
				m_circles[i][y]->setNeighborsOod(i, y);



}


//draw the level
void Board::drawWindow(sf::RenderWindow& window)
{
	
	for (int i = 0; i < m_circles.size(); i++)
		for (int y = 0; y < m_circles[i].size(); y++)
			m_circles[i][y]->draw(window);
	
	m_Cat.draw(window);

	

}


//mouse click function
bool Board::mouseClick(sf::Event evnt, sf::RenderWindow& window)
{
	
	auto mousePosWindow = sf::Mouse::getPosition(window);
	auto mousePosView = window.mapPixelToCoords(mousePosWindow);

	for (int y = 0; y < m_circles.size();y++)
	{
		for (size_t i = 0; i < m_circles[y].size(); i++)
		{
			if (m_circles[y][i]->handleCollision(mousePosView))
			{
				if (m_circles[y][i]->getPosition() == m_Cat.getPosition() || 
					(m_circles[y][i]->getFillColor() != sf::Color(173, 255, 47)))
					return false;
				

			
				m_circles[y][i]->setFillColor(sf::Color(85, 107, 47));

				CatMove(m_Cat.getCirclePoint(), window);
							return true;
						
				return true;
			}

		}
	}
	
	return false;
}

void Board::CatMove(std::pair<int, int>loccir, sf::RenderWindow& window)
{
	std::vector<std::pair< int, int>>path;
	int min = DIS;


	for (int i = 0; i < m_array.size(); i++)
	{
		std::vector<std::pair< int, int>>temp;
		int distance = ShortestDistance(m_circles[loccir.first][loccir.second]->getpair(),
			m_array[i], temp);

		if (distance < min)
		{
			min = distance;
			path = temp;

		}
	}
	if (min != DIS)
		changeCatLoc(m_Cat.getPosition(), std::pair<int,int>(path[path.size()-2].first, path[path.size() - 2].second), window);
	else
		moveRandomcat(loccir, window);
	
}
void Board::moveRandomcat(std::pair<int, int> loccir, sf::RenderWindow& window)
{
	bool end_of_cat = false;
	std::list< std::pair<int, int>>::iterator i;
	auto neighbor = m_circles[loccir.first][loccir.second]->getListNeighbors();
	for (i = neighbor.begin();
		i != neighbor.end();
		i++)
	{

		if (m_circles[i->first][i->second]->getFillColor() != sf::Color(85, 107, 47))
		{
			end_of_cat = true;
			changeCatLoc(m_Cat.getPosition(), std::pair<int, int>(i->first, i->second), window);
			break;
		}

	}
	if (end_of_cat == false)
	{
		m_newlevel = true;
	}
}


void Board::wingamecheck()
{
	for (int i = 0; i < m_array.size(); i++)
	{
		if (m_circles[m_array[i].first][m_array[i].second]->getPosition() == m_Cat.getPosition())
		{
			m_gameover = true;
		}
	}
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
}



<<<<<<< HEAD
=======
bool Board::BFS(std::pair< int, int>src, std::pair< int, int> dest,
	std::vector<std::vector< std::pair< int, int>>>& pred, std::vector< std::vector<int>>& dist)
{
	// a queue to maintain queue of vertices whose
	// adjacency list is to be scanned as per normal
	// DFS algorithm
	std::list< std::pair< int, int>> queue;

	// boolean array visited[] which stores the
	// information whether ith vertex is reached
	// at least once in the Breadth first search
	std::vector<std::vector<bool>>visited;

	// initially all vertices are unvisited
	// so v[i] for all i is false
	// and as no path is yet constructed
	// dist[i] for all i set to infinity
	visited.resize(11);
	dist.resize(11);
	pred.resize(11);
	for (int i = 0; i < 11; i++) {
		visited[i].resize(11, false);
		dist[i].resize(11, 0);
		pred[i].resize(11, { -1,-1 });
	}

	// now source is first to be visited and
	// distance from source to itself should be 0
	visited[src.first][src.second] = true;
	dist[src.first][src.second] = 0;
	queue.push_back(src);
	std::list< std::pair<int, int>>::iterator i;
	// standard BFS algorithm
	while (!queue.empty()) {
		auto u = queue.front();
		queue.pop_front();
		auto neighbor = m_circles[u.first][u.second]->getListNeighbors();
		for (i =neighbor.begin();
			i != neighbor.end();
			i++)
		{
			if (visited[i->first][i->second] == false && 
				m_circles[i->first][i->second]->getFillColor()!= sf::Color(85, 107, 47)) {
				visited[i->first][i->second] = true;
				dist[i->first][i->second] = dist[u.first][u.second] + 1;
				pred[i->first][i->second] = u;

				queue.push_back({ i->first,i->second });
				
				if (i->first == dest.first && i->second == dest.second)
					return true;
			}
		}

	}

	return false;
}

// utility function to print the shortest distance
// between source vertex and destination vertex
int  Board::ShortestDistance(std::pair< int,  int> s,
	std::pair< int,  int> dest, std::vector<std::pair< int, int>>&path)
{
	// predecessor[i] array stores predecessor of
	// i and distance array stores distance of i
	// from s
	std::vector<std::vector< std::pair< int, int>>> pred;
	std::vector<std::vector<int>>dist;
	
	if (BFS(s, dest,  pred, dist) == false) {
		return 122;
	}

	// vector path stores the shortest path
	//std::vector<std::pair< int,  int>>path;
	std::pair< int,  int> crawl = dest;
	
	path.push_back(crawl);
  while (pred[crawl.first][crawl.second] != std::pair<int,int>(-1,-1)) {
		path.push_back(pred[crawl.first][crawl.second]);
		crawl = pred[crawl.first][crawl.second];
	}


     return dist[dest.first][dest.second];
	
}




void Board::clearBoard(bool win)
{
	if (win)
		nextLevel();
	m_circles.clear();
	
	drawSquares();
}

void Board::nextLevel()
{
	m_newlevel = false;
	m_blackCircles -= 2;
	if (m_blackCircles < 4)
	{
		m_blackCircles = BLACKCIRCLES;
	}
	setBlackCircles();
}





void Board::changeCatLoc(sf::Vector2f cat, std::pair<int,int>location, sf::RenderWindow& window)
{
	sf::Vector2f circle = m_circles[location.first][location.second]->getPosition();
	int x = 0, y = 0;
	if (cat.x > circle.x && cat.y == circle.y)
	{
		m_Cat.setTexture(0);
		int x1 = (cat.x - circle.x) / 5;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 5; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);
				m_Cat.move(sf::Vector2f(-x1, 0.f));
				y = 0;
				x++;
				x = x % 5;
				m_Cat.setTextureRect(sf::IntRect((x * 100) + 10, 100 + 20, 100, 80));
				window.display();
				Sleep(20);
			}

		}
	}

	if (cat.x < circle.x && cat.y == circle.y)
	{
		m_Cat.setTexture(0);
		int x1 = (circle.x - cat.x) / 5;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 5; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(x1, 0.f));
				y = 0;
				x++;
				x = x % 5;
				m_Cat.setTextureRect(sf::IntRect((x * 100) + 10, 20, 100, 80));
				window.display();
				Sleep(20);
			}

		}
	}
	if (cat.x > circle.x && cat.y < circle.y)
	{
		m_Cat.setTexture(2);
		int x1 = (cat.x - circle.x) / 5;
		int y1 = (circle.y - cat.y) / 5;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 5; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(-x1, y1));
				y = 0;
				x++;
				x = x % 5;
				m_Cat.setTextureRect(sf::IntRect((x * 100), 0, 100, 100));
				window.display();
				Sleep(20);
			}

		}

	}
	if (cat.x < circle.x && cat.y < circle.y)
	{
		m_Cat.setTexture(2);
		int x1 = (circle.x - cat.x) / 5;
		int y1 = (circle.y - cat.y) / 5;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 5; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(x1, y1));
				y = 0;
				x++;
				x = x % 5;
				m_Cat.setTextureRect(sf::IntRect((x * 100), 100, 100, 100));
				window.display();
				Sleep(20);
			}

		}

	}
	if (cat.x > circle.x && cat.y > circle.y)
	{
		m_Cat.setTexture(1);
		int x1 = (cat.x - circle.x) / 4;
		int y1 = (cat.y - circle.y) / 4;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 4; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(-x1, -y1));
				y = 0;
				x++;
				x = x % 4;
				m_Cat.setTextureRect(sf::IntRect((x * 100), 100, 100, 100));
				window.display();
				Sleep(20);
			}

		}



	}
	if (cat.x < circle.x && cat.y > circle.y)
	{
		m_Cat.setTexture(1);
		int x1 = (circle.x - cat.x) / 4;
		int y1 = (cat.y - circle.y) / 4;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			for (int i = 0; i < 4; i++)
			{

				window.clear(sf::Color::White);
				drawWindow(window);

				m_Cat.move(sf::Vector2f(x1, -y1));
				y = 0;
				x++;
				x = x % 4;
				m_Cat.setTextureRect(sf::IntRect((x * 100), 0, 100, 100));
				window.display();
				Sleep(20);
			}

		}

	}

	m_Cat.setPosition(circle, location);
	wingamecheck();
}
>>>>>>> 2dec36ab4a5e6cb7221be1257d9c5d2906b155f9
