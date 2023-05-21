class ConnectionDetails
{
public:
	static void StaticInit();
	static std::unique_ptr<ConnectionDetails> sInstance;


	ConnectionDetails();
	void Load();
	string GetClientName();
	string GetClientDestination();
	uint16_t GetServerPort();

private:
	string m_clientName;
	uint16_t m_clientPort;
	uint16_t m_serverPort;

};