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
	//if (!picked)
	//{
		if (inCat->GetHealth() <= 19)
		{
			inCat->GetHealth()++;
			//picked = true;

			// Hacked in here.
			int ECRS_Health = 1 << 3;
			//int ECRS_Health = 3 << 5;
			//int ECRS_Health = 5 << 6;
			NetworkManagerServer::sInstance->SetStateDirty(inCat->GetNetworkId(), ECRS_Health);
		}
	//}
	//unalive yourself!
	SetDoesWantToDie(true);

	//ScoreBoardManager::sInstance->IncScore(inCat->GetPlayerId(), 1);

	return false;
}






