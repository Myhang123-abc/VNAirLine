#include "RandomGenerator.h"

string RandomGenerator::destinations[MAX][3] = 
{
	{"Ha Noi", "21.03333", "105.85000"},
	{"Ho Chi Minh", "10.83333", "106.63278"},
	{"Hai Phong", "20.86194", "106.68028"},
	{"Da Nang", "16.05194", "108.21528"},
	{"Can Tho", "10.03278", "105.78389"},
	{"Da Nang", "16.05194", "108.21528"},
	{"Bien Hoa", "10.95694", "106.84306"},
	{"Thanh Hoa", "19.80750", "105.77639"},
	{"Nha Trang", "12.23889", "109.19694"},
	{"Vung Tau", "10.34583", "107.08472"},
	{"Thu Duc", "10.88333", "106.72694"},
	{"Hue", "16.46278", "107.58472"},
	{"Buon Ma Thuot", "12.66667", "108.03889"},
	{"Thai Nguyen", "21.56750", "105.82556"},
	{"Vinh", "18.68083", "105.68167"},
	{"Hai Duong", "20.93972", "106.31250"},
	{"Nam Dinh", "20.42000", "106.16833"},
	{"Ha Long", "20.97194", "107.04528"},
	{"My Tho", "10.35417", "106.36528"},
	{"Quy Nhon", "13.77500", "109.23333"},
	{"Thai Binh", "20.44750", "106.33750"},
	{"Da Lat", "11.94556", "108.44222"},
	{"Phan Thiet", "10.92222", "108.10944"},
	{"Ca Mau", "9.18361", "105.15000"}
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
