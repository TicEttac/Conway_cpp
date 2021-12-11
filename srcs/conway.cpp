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

void    Cmap::CellOn(int x, int y){
    std::pair<int, int> {x, y} = ConvertPos(x, y);
    Cmap::map[x][y] = true;
}

void	Cmap::CellOff(int x, int y){
    std::pair<int, int> {x, y} = ConvertPos(x, y);
        Cmap::map[x][y] = true;
}

std::pair<int, int>   Cmap::ConvertPos(int x, int y)
{
    if (x > Cmap::x)
        x -= Cmap::x;
    if (y > Cmap::y)
        y -= Cmap::y;
    if (x < 0)
        x += Cmap::x;
    if (y < 0)
        y += Cmap::y;
    return std::make_pair(x, y);
}