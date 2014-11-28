//demo the snake movement, boundry wrapped
#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstdlib>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

#define LEFT	's'
#define UP 	 	'e'
#define RIGHT 	'f'
#define DOWN	'd'
#define SNAKE_LEN	9

class Board;
class GreedyGrub;

class Board
{
public:
	Board(int width, int height)
	{
		board.resize(height);
		for(int i=0; i<height; i++)
			board[i].resize(width);
	}

	char getStatus(int x, int y)
	{
		if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
			return 'z';
		return board[x][y];
	}

	void setStatus(int x, int y, char ch)
	{
		if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
			return;
		board[x][y] = ch;
	}

	void print()
	{
		for(int j=0; j<board[0].size(); j++)
			cout << "---";
		cout << endl;

		for(int i=0; i<board.size(); i++)
		{
			cout << "|";
			for(int j=0; j<board[i].size(); j++)
			{
				cout << board[i][j];
				if(j != board[i].size()-1)
					cout << "  ";
			}
			cout << "|" << endl;
		}
		for(int j=0; j<board[0].size(); j++)
			cout << "---";

		cout << endl;
	}

	void setSnake(vector<pair<int,int> > &seq)
	{
		for(int i=0; i<seq.size(); i++)
			board[seq[i].first][seq[i].second] = '1';
	}

	int height()
	{
		return board.size();
	}

	int width()
	{
		return board[0].size();
	}

	void init()
	{
		for(int i=0; i<board.size(); i++)
		{
			for(int j=0; j<board[i].size(); j++)
			{
				board[i][j] = ' ';
			}
		}
	}

private:
	vector<vector<char> > board;
};

class Snake
{
public:
	Snake(Board *board)
	{
		this->board = board;
		//init vector sequence
		for(int i=0; i<SNAKE_LEN; i++)
			seq.push_back(make_pair(0, i));
	}

	bool isvalid(int x, int y)
	{
		for(int i=0; i<seq.size(); i++)
		{
			if(x == seq[i].first && y == seq[i].second)
				return false;
		}
		return true;
	}

	void move(int dir)
	{
		int nx = seq[0].first + dx[dir];
		int ny = seq[0].second + dy[dir];

		nx = (nx + board->height())%(board->height());
		ny = (ny + board->width()) %(board->width());

		cout << nx << " " << ny << endl;

		if(isvalid(nx, ny))
		{
			for(int i=seq.size()-1; i>0; i--)
			{
				seq[i].first = seq[i-1].first;
				seq[i].second= seq[i-1].second;
			}
			seq[0].first = nx;
			seq[0].second = ny;
		}

		board->init();
		board->setSnake(seq);
		board->print();
	}

private:
	vector<pair<int,int> > seq;
	Board *board;
};


class GreedyGrub
{
public:
	GreedyGrub(int w, int h)
	{
		map = new Board(w, h);
		snake = new Snake(map);
	}

	~GreedyGrub()
	{
		delete map;
		delete snake;
	}

	void run()
	{
		while(true)
		{
			char s = getchar();
			cout << s << endl;
			if(s == ' ')
				break;

			switch(s)
			{
				case LEFT:
					snake->move(2);
				break;

				case RIGHT:
					snake->move(3);
				break;

				case UP:
					snake->move(0);
				break;

				case DOWN:
					snake->move(1);
				break;

				case ' ':
					return;
			}
		}
	}
private:
	Board *map;
	Snake *snake;

};

int main()
{
	GreedyGrub game(20, 20);
	game.run();
	return 0;
}
