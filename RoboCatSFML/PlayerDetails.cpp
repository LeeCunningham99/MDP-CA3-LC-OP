#include "RoboCatPCH.hpp"

std::unique_ptr<ConnectionDetails> ConnectionDetails::sInstance;

void ConnectionDetails::StaticInit()
{
	ConnectionDetails* cd = new ConnectionDetails();
	cd->Load();
	sInstance.reset(cd);
}

ConnectionDetails::ConnectionDetails()
{
}

void ConnectionDetails::Load()
{
	uint16_t port = 50001;
	m_clientPort = port;
	m_serverPort = port;

	StringUtils::Log("TRYING TO OPEN FILES", 1);

	string line;
	std::ifstream nameFile("../Assets/inputs/name.txt");
	if (nameFile.good())
	{
		getline(nameFile, line);
		m_clientName = line;
	}
	nameFile.close();
}

string ConnectionDetails::GetClientName()
{
	return m_clientName;
}

uint16_t ConnectionDetails::GetServerPort()
{
	return m_serverPort;
}