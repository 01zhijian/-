#pragma once
class Clock
{
public:
	Clock();
	
	void run();

private:
	void tick();
	void show();

private:
	int _hour;
	int _minute;
	int _second;
};

