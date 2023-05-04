#include "RoboCatServerPCH.hpp"


MouseServer::MouseServer()
{
}

void MouseServer::HandleDying()
{
	NetworkManagerServer::sInstance->UnregisterGameObject(this);
}


bool MouseServer::HandleCollisionWithCat(RoboCat* inCat)
{
	//unalive yourself!
	SetDoesWantToDie(true);

	ScoreBoardManager::sInstance->IncScore(inCat->GetPlayerId(), 1);

	return false;
}






