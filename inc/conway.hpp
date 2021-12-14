#ifndef CONWAY_HPP
# define CONWAY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <unistd.h>

class Cmap{
    public :
        Cmap(unsigned int sizex = 4, unsigned int sizey = 4);
        Cmap(std::string file_path);
        virtual	~Cmap(){}
		void							RunOne();
		std::vector<std::vector<bool>>	GetMap();
		unsigned int					GetX();
		unsigned int					GetY();
		void							CellOn(int _x, int _y);
		void							CellOff(int _x, int _y);

		friend std::ostream& operator<<( std::ostream& flux, Cmap &map)
		{
			flux << "\033[1;34m" << "x : " << map.x << ", y : " << map.y << "\n\033[0m";
            for (int i = 0; i < map.x; i++)
			{
				for (int j = 0; j < map.y; j++)
				{
					if (map.map[i][j])
						flux << "\033[1;32m"<< int(map.map[i][j]) << "\033[0m";
					else
						flux << "\033[1;31m"<< int(map.map[i][j]) << "\033[0m";
				}
				flux << std::endl;
			}
            return flux;
		}

	private :
		std::pair<int, int>				ConvertPos(int x, int y);
		void							ApplyRules(int x, int y);
		std::vector<std::vector<bool>>	map;
		std::vector<std::vector<bool>>	next_map;
		unsigned int				x;
		unsigned int				y;
};

#endif