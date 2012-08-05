#include "test_sms.h"

#include <ctime>

void demo0(SpringMassSystem& sms)
{
	for (int i = -3; i <= 3; i++)
		for (int j = -3; j <= 3; j++)
			sms.addMass(abs(i*j) == 9 ? 0.0 : 1.0, 
				Vector2<>(j * 0.2, i * 0.2));
	for (int i = 0; i < 6; i++)
		for (int j = 0; j <= 6; j++)
			sms.addSpring(7 * j + i, 7 * j + i + 1, 100.0);
	for (int j = 0; j < 6; j++)
		for (int i = 0; i <= 6; i++)
			sms.addSpring(7 * j + i, 7 * (j + 1) + i, 100.0);
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			sms.addSpring(7 * j + i, 7 * j + i + 8, 100.0);

	sms.addMass(0.5, Vector2<>(0.0, 0.8));
	sms.addSpring(44, 49, 200.0, -0.3);
	sms.addSpring(46, 49, 200.0, -0.25);
}

void demo1(SpringMassSystem& sms)
{
	for (int i = -3; i <= 3; i++)
		for (int j = -3; j <= 3; j++)
			sms.addMass(1.0, Vector2<>(j * 0.2, i * 0.2));
	for (int i = 0; i < 6; i++)
		for (int j = 0; j <= 6; j++)
			sms.addSpring(7 * j + i, 7 * j + i + 1, 250.0);
	for (int j = 0; j < 6; j++)
		for (int i = 0; i <= 6; i++)
			sms.addSpring(7 * j + i, 7 * (j + 1) + i, 250.0);
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			sms.addSpring(7 * j + i, 7 * j + i + 8, 250.0);

	sms.addMass(0.0, Vector2<>(0.0, 0.8));
	for (int i = 0; i < 5; i++)
	{
		sms.addMass(1.0, Vector2<>(-0.1 * (i + 1), 0.8 - 0.02 * i));
		sms.addSpring(49 + i, 50 + i, 250.0, 0.0);
	}
	sms.addSpring(42, 54, 250.0, 0.0);
}

void demo2(SpringMassSystem& sms)
{
	const double BRIDGE_K = 500.0;
	const double STRING_K = 100.0;
	
	// Bridge
	sms.addMass(0.0, Vector2<>(-0.8, 0.0)); // mass 0
	sms.addMass(0.0, Vector2<>( 0.8, 0.0)); // mass 1
	for (int i = 0; i < 7; i++)
		sms.addMass(1.0, Vector2<>(-0.6 + 0.2 * i, 0.0)); // masses 2 to 8
	for (int i = 0; i < 8; i++)
		sms.addMass(1.0, Vector2<>(-0.7 + 0.2 * i, 0.2)); // masses 9 to 16
	sms.addSpring(0, 2, BRIDGE_K);
	sms.addSpring(8, 1, BRIDGE_K);
	for (int i = 0; i < 6; i++)
		sms.addSpring(2 + i, 2 + i + 1, BRIDGE_K);
	for (int i = 0; i < 7; i++)
		sms.addSpring(9 + i, 9 + i + 1, BRIDGE_K);
	sms.addSpring(0, 9, BRIDGE_K);
	sms.addSpring(16, 1, BRIDGE_K);
	for (int i = 0; i < 7; i++)
	{
		sms.addSpring(2 + i, 9 + i, BRIDGE_K);
		sms.addSpring(2 + i, 9 + i + 1, BRIDGE_K);
	}

	// Stone
	sms.addMass(0.2, Vector2<>(0.0, 0.4)); // mass 17
	for (int i = 0; i < 15; i++)
		sms.addMass(5.0, Vector2<>(-0.1 + 0.1 * (i % 2),
			0.4 / 14.0 * i)); // masses 18 to 32
	sms.addSpring(17, 32, STRING_K);
	for (int i = 0; i < 14; i++)
		sms.addSpring(18 + i, 18 + i + 1, STRING_K);
	sms.addSpring(5, 18, STRING_K);
}

void demo3(SpringMassSystem& sms)
{
	const double BRIDGE_K = 500.0;
	const double BRIDGE_INV_S = 1.0 / 10.0;
	const double STRING_K = 100.0;
	
	// Bridge
	sms.addMass(0.0, Vector2<>(-0.8, 0.0)); // mass 0
	sms.addMass(0.0, Vector2<>( 0.8, 0.0)); // mass 1
	for (int i = 0; i < 7; i++)
		sms.addMass(1.0, Vector2<>(-0.6 + 0.2 * i, 0.0)); // masses 2 to 8
	for (int i = 0; i < 8; i++)
		sms.addMass(1.0, Vector2<>(-0.7 + 0.2 * i, 0.2)); // masses 9 to 16
	sms.addSpring(0, 2, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(8, 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 6; i++)
		sms.addSpring(2 + i, 2 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 7; i++)
		sms.addSpring(9 + i, 9 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(0, 9, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(16, 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 7; i++)
	{
		sms.addSpring(2 + i, 9 + i, BRIDGE_K, 0.0, BRIDGE_INV_S);
		sms.addSpring(2 + i, 9 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	}

	// Stone
	sms.addMass(0.2, Vector2<>(0.0, 0.4)); // mass 17
	for (int i = 0; i < 15; i++)
		sms.addMass(5.0, Vector2<>(-0.1 + 0.1 * (i % 2),
			0.4 / 14.0 * i)); // masses 18 to 32
	sms.addSpring(17, 32, STRING_K);
	for (int i = 0; i < 14; i++)
		sms.addSpring(18 + i, 18 + i + 1, STRING_K);
	sms.addSpring(5, 18, STRING_K);
}

void demo4(SpringMassSystem& sms)
{
	const double BRIDGE_K = 2000.0;
	const double BRIDGE_INV_S = 1.0 / 30.0;

	// Bridge
	sms.addCollMass(0.0, Vector2<>(-0.8, 0.0), 0.01); // mass 0
	sms.addCollMass(0.0, Vector2<>( 0.8, 0.0), 0.01); // mass 1
	for (int i = 0; i < 31; i++)
		sms.addCollMass(4.0, Vector2<>(-0.75 + 0.05 * i, 0.0), 0.01); // masses 2 to 32
	for (int i = 0; i < 32; i++)
		sms.addCollMass(4.0, Vector2<>(-0.775 + 0.05 * i, 0.2), 0.01); // masses 33 to 64

	sms.addSpring(0, 2, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(32, 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 30; i++)
		sms.addSpring(2 + i, 2 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 31; i++)
		sms.addSpring(33 + i, 33 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(0, 33, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(64, 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 31; i++)
	{
		sms.addSpring(2 + i, 33 + i, BRIDGE_K, 0.0, BRIDGE_INV_S);
		sms.addSpring(2 + i, 33 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	}

	// Stone
	sms.addCollMass(0.2, Vector2<>(0.1, 2.0), 0.05); // Mass 55
}

void demo5(SpringMassSystem& sms)
{
	const double BRIDGE_K = 2000.0;
	const double BRIDGE_INV_S = 1.0 / 15.0;

	// Bridge 1
	sms.addCollMass(0.0, Vector2<>(-0.8, 0.0), 0.0); // mass 0
	sms.addCollMass(0.0, Vector2<>( 0.8, 0.0), 0.0); // mass 1
	for (int i = 0; i < 31; i++)
		sms.addCollMass(4.0, Vector2<>(-0.75 + 0.05 * i, 0.0), 0.0); // masses 2 to 32
	for (int i = 0; i < 32; i++)
		sms.addCollMass(4.0, Vector2<>(-0.775 + 0.05 * i, 0.05), 0.0); // masses 33 to 64

	sms.addSpring(0, 2, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(32, 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 30; i++)
		sms.addSpring(2 + i, 2 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 31; i++)
		sms.addSpring(33 + i, 33 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(0, 33, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(64, 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 31; i++)
	{
		sms.addSpring(2 + i, 33 + i, BRIDGE_K, 0.0, BRIDGE_INV_S);
		sms.addSpring(2 + i, 33 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	}

	// Bridge 2
	sms.addCollMass(0.0, Vector2<>(-0.8, -0.4), 0.0); // mass 65
	sms.addCollMass(0.0, Vector2<>( 0.8, -0.4), 0.0); // mass 66
	for (int i = 0; i < 31; i++)
		sms.addCollMass(4.0, Vector2<>(-0.75 + 0.05 * i, -0.4), 0.0); // masses 67 to 97
	for (int i = 0; i < 32; i++)
		sms.addCollMass(4.0, Vector2<>(-0.775 + 0.05 * i, -0.35), 0.0); // masses 98 to 129

	sms.addSpring(65, 67, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(97, 66, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 30; i++)
		sms.addSpring(67 + i, 67 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 31; i++)
		sms.addSpring(98 + i, 98 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(65, 98, BRIDGE_K, 0.0, BRIDGE_INV_S);
	sms.addSpring(129, 66, BRIDGE_K, 0.0, BRIDGE_INV_S);
	for (int i = 0; i < 31; i++)
	{
		sms.addSpring(67 + i, 98 + i, BRIDGE_K, 0.0, BRIDGE_INV_S);
		sms.addSpring(67 + i, 98 + i + 1, BRIDGE_K, 0.0, BRIDGE_INV_S);
	}

	// Stone
	sms.addCollMass(0.1, Vector2<>(-0.2, 1.5), 0.07); // Mass 129
}

void (*demos[])(SpringMassSystem&) = {demo0, demo1, demo2, demo3, demo4, demo5};

void loadRandomDemo(SpringMassSystem& sms)
{
	srand(static_cast<unsigned>(time(0)));

	int numDemos = sizeof(demos) / sizeof(demos[0]);

	demos[rand() % numDemos](sms);
}

void loadDemo(SpringMassSystem& sms, const char* demoNumStr)
{
	std::istringstream iss(demoNumStr);
	int demoNum;
	iss >> demoNum;

	int numDemos = sizeof(demos) / sizeof(demos[0]);

	demos[demoNum % numDemos](sms);
}
