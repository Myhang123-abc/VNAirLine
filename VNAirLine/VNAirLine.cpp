
#include "Header.h"
#include "RandomGenerator.h"
int main()
{
    srand(time(NULL));
    RandomGenerator random;
    int name;
    for (int i = 0; i < 10; i++) {
        name = random.randomOfNumSeat();
        cout << name << endl;
    }
}
