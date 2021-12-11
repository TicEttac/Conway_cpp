#include "conway.hpp"

/*TODO :
    - parse entries (int, int or char *)
    - apply rules
    - term interface
    - visual interface
    - key binding (space bar == pause)

*/
int main(int ac, char **av)
{
    Cmap conway(av[1]);
    std::cout << conway;
}