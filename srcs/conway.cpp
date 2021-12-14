#include "conway.hpp"

Cmap::Cmap(unsigned int x, unsigned int y)
{
    Cmap::x = x;
    Cmap::y = y;
    for (int i = 0 ; i < x ; i++)
    {
        std::vector<bool>   v1;
        for (int j = 0; j < y; j++)
            v1.push_back(false);
        Cmap::map.push_back(v1);
    }
}

Cmap::Cmap(std::string file_path)
{
    std::ifstream   file;
    std::string     line;

    file.open(file_path.c_str());
    if (file.is_open())
    {
        Cmap::x = 0;
        while ( std::getline(file,line) )
        {
            std::vector<bool> v;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == '0')
                    v.push_back(false);
                if (line[i] == '1')
                    v.push_back(true);
                Cmap::y = i;
            }
            Cmap::map.push_back(v);
            x++;
        }
        file.close();
    }
    else
        std::cout << "Unable to open file";
}

std::vector<std::vector<bool>>	Cmap::GetMap()
{
    return Cmap::map;
}

unsigned int 					Cmap::GetX(){
	return (x);
}

unsigned int					Cmap::GetY(){
	return (y);
}

void							Cmap::RunOne(){
    next_map = map;
	for (int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			ApplyRules(i, j);
        }
    }
    map = next_map;
}

void                            Cmap::CellOn(int x, int y){
    std::pair<int, int> {x, y} = ConvertPos(x, y);
    Cmap::map[x][y] = true;
}

void	                        Cmap::CellOff(int x, int y){
    std::pair<int, int> {x, y} = ConvertPos(x, y);
        Cmap::map[x][y] = false;
}

//			PRIVATE

void    testfunc(){}

std::pair<int, int>				Cmap::ConvertPos(int _x, int _y)
{
	int nx = _x, ny = _y;
    if (nx >= int(Cmap::x))
        nx -= int(Cmap::x);
    if (ny >= int(Cmap::y))
        ny -= int(Cmap::y);
    if (nx < 0)
        nx += int(Cmap::x);
    if (ny < 0)
        ny += int(Cmap::y);
    std::pair<int, int> ret = std::make_pair(nx, ny);
	return ret;
}

void							Cmap::ApplyRules(int _x, int _y){
	int sum = 0;

	for (int i = -1; i < 2; i++){
		std::pair<int, int> pos = ConvertPos(_x - 1, _y + i);
		sum += int(map[pos.first][pos.second]);
	}
	for (int i = 0 ; i < 2; i++){
		std::pair<int, int> pos = ConvertPos(_x + i, _y - 1);
		sum += int(map[pos.first][pos.second]);
	}
	for (int i = 0; i < 2; i++){
		std::pair<int, int> pos = ConvertPos(_x + 1, _y + i);
		sum += int(map[pos.first][pos.second]);
	}
	std::pair<int, int> pos = ConvertPos(_x, _y + 1);
	sum += int(map[pos.first][pos.second]);

	if (map[_x][_y] == 0 && sum == 3)
        next_map[_x][_y] = true;
	else if ((map[_x][_y] == 1 && (sum == 2 || sum == 3))){}
	else
        next_map[_x][_y] = false;
		//CellOff(_x, _y);
}