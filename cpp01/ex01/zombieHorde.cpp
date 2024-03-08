#include "Zombie.hpp"

Zombie*    zombieHorde( int N, std::string name ) {

    Zombie* res = new Zombie[N];
    std::string str;
    for (int i = 0; i < N; i++){
        res[i].setName(name);
        res[i].announce();
    }
	return (res);
}
