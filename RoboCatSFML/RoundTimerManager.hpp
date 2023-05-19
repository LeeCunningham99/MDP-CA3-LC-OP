#pragma once
class RoundTimerManager
{
	//static void StaticInit();
	//static std::unique_ptr< RoundTimerManager >	sInstance;


	float GetTimer()		const { return mTimer; }


	void SetTimer(int inTimer);

	//static float	GetSerializedSize();

	const string& GetFormattedTimer()	const { return mFormattedTimer; }


	bool			Write(OutputMemoryBitStream& inOutputStream) const;
	bool			Read(InputMemoryBitStream& inInputStream);




private:
	float mTimer;
	string mFormattedTimer;
};

