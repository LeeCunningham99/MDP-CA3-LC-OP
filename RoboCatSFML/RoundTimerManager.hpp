#pragma once
class RoundTimerManager
{
	float GetTimer()		const { return mTimer; }


	void SetTimer(int inTimer);



private:
	float mTimer;
};

