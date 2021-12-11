#ifndef CONWAY_HPP
# define CONWAY_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Cmap{
    public :
        Cmap(unsigned int sizex = 4, unsigned int sizey = 4);
        Cmap(std::string file_path);
        virtual	~Cmap(){}
		std::vector<std::vector<bool>>	GetMap();
		void							CellOn(int _x, int _y);
		void							CellOff(int _x, int _y);
		friend std::ostream& operator<<( std::ostream& flux, Cmap &map)
		{
			flux << "x : " << map.x << ", y : " << map.y << std::endl;
            for (int i = 0; i < map.x; i++)
			{
				for (int j = 0; j < map.y; j++)
					flux << int(map.map[i][j]);
				flux << std::endl;
			}
            return flux;
		}

	private :
		std::pair<int, int>				ConvertPos(int x, int y);

		std::vector<std::vector<bool>>	map;
		unsigned int					x;
		unsigned int					y;
};

#endif