#include "Clock.h"

#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

Clock::Clock()
{
	time_t t = time(nullptr);
	tm local = *localtime(&t);
	_hour = local.tm_hour;
	_minute = local.tm_min;
	_second = local.tm_sec;
}

void Clock::run()
{
	for (;;)
	{
		tick();
		show();
	}
}

void Clock::tick()
{
	std::this_thread::sleep_for(std::chrono::seconds(1));
	if (++_second == 60)
	{
		_second = 0;
		if (++_minute == 60)
		{
			_minute = 0;
			if (++_hour == 24)
			{
				_hour = 0;
			}
		}
	}
}

void Clock::show()
{
	system("cls");
	std::cout << _hour << ":" << _minute << ":" << _second << std::endl;
}



int main()
{
	wchar_t* str = nullptr;

	Clock c;
	c.run();

	return 0;
}
