#include "RoboCatPCH.hpp"
#include "RoundTimerManager.hpp"

void RoundTimerManager::SetTimer(int inTimer)
{
	mTimer = inTimer;
	/*char	buffer[256];
	snprintf(buffer, 256, "%i", mTimer);
	mFormattedTimer = string(buffer);*/
}

bool RoundTimerManager::Write(OutputMemoryBitStream& inOutputStream) const
{
	inOutputStream.Write(mTimer);
	return true;
}

bool RoundTimerManager::Read(InputMemoryBitStream& inInputStream)
{
	inInputStream.Read(mTimer);
	return false;
}


