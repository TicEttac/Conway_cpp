#include "conway.hpp"

/*TODO :
    - parse entries (int, int or char *)
    - apply rules
    - term interface
    - visual interface
    - key binding (space bar == pause)

*/

inline bool exists_test2 (const std::string& name) {
    return ( access( name.c_str(), F_OK ) != -1 );
}

int main(int ac, char **av)
{
    if (ac == 2 && exists_test2(av[1]))
    {
        Cmap conway(av[1]);
        std::cout << conway;
        /*      TEST CELLON
        for (int i = 0; i < conway.GetY(); i++)
            conway.CellOn(0, i);
        std::cout << conway;*/
        while (1)
        {
            char s;
            std::cin.get(s);
            while (s != 10)
                std::cin.get(s);
            conway.RunOne();
            std::cout << conway;
        }
        std::cout << conway;
    }
}