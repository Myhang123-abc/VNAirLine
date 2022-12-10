
#include "Header.h"
#include "RandomGenerator.h"
int main()
{
    srand(time(NULL));
    RandomGenerator random;
    string** chosen = random.randomDestinations();
    random.displayChosenDestinations(chosen);
}
