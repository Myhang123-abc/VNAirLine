#include "RandomGenerator.h"

string RandomGenerator::destinations[MAX][3] = 
{
	{"Ha Noi", "21.03333", "105.85000"},
	{"Ho Chi Minh", "10.83333", "106.63278"},
	{"Hai Phong", "20.86194", "106.68028"},
	{"Da Nang", "16.05194", "108.21528"},
	{"Can Tho", "10.03278", "105.78389"}
};
int RandomGenerator::getRandom(int min, int max) {
	return min + rand() % (max - min + 1);
}
string RandomGenerator::getRandomNumber() 
{
	return randomNum;
}
void RandomGenerator::setRandomNum(string randomNum)
{
	this->randomNum = randomNum;
}
void RandomGenerator::randomIDGen()
{
	int min = 20000, max = 1000000;
	int randomInt = getRandom(min, max);
	setRandomNum(to_string(randomInt));
}
string** RandomGenerator::randomDestinations()
{
	string** chosenDestinations = new string * [3];
	int length = sizeof(destinations) / sizeof(destinations[0]);
	int min = 0, max = length - 1;
	int randomCity1 = getRandom(min, max);
	int randomCity2 = getRandom(min, max);
	string fromWhichCity = destinations[randomCity1][0];
	string fromWhichCityLat = destinations[randomCity1][1];
	string fromWhichCityLong = destinations[randomCity1][2];
	while (randomCity2 == randomCity1)
	{
		randomCity2 = getRandom(min, max);
	}
	string toWhichCity = destinations[randomCity2][0];
	string toWhichCityLat = destinations[randomCity2][1];
	string toWhichCityLong = destinations[randomCity2][2];
	for (int i = 0;i < 2;i++)
	{
		chosenDestinations[i] = new string[3];
	}
	chosenDestinations[0][0] = fromWhichCity;
	chosenDestinations[0][1] = fromWhichCityLat;
	chosenDestinations[0][2] = fromWhichCityLong;
	chosenDestinations[1][0] = toWhichCity;
	chosenDestinations[1][1] = toWhichCityLat;
	chosenDestinations[1][2] = toWhichCityLong;
	return chosenDestinations;
}
void RandomGenerator::displayChosenDestinations(string** chosenDestinations)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << chosenDestinations[i][j] << " ";
		}
		cout << endl;
	}
}
int RandomGenerator::randomOfNumSeat()
{
	int min = 75, max = 500;
	int numOfSeat = getRandom(min, max);
	return numOfSeat;
}
string RandomGenerator::randomFlightNumGen(int uptoHowManyLettersRequired, int divisible)
{
	int min = 0, max = 25;
	string randomAlphabet;
	for (int i = 0; i < uptoHowManyLettersRequired; i++)
	{
		char temp = getRandom(min, max) + 65;
		randomAlphabet = randomAlphabet.append(to_string(temp));
	}
	randomAlphabet = randomAlphabet.append("-").append(to_string(randomOfNumSeat() / divisible));
	return randomAlphabet;
}