//I take care of rendering things!

class RenderManager
{
public:

	static void StaticInit();
	static std::unique_ptr< RenderManager >	sInstance;

	void Render();
	void RenderComponents();

	//vert inefficient method of tracking scene graph...
	void AddComponent(SpriteComponent* inComponent);
	void RemoveComponent(SpriteComponent* inComponent);
	int	 GetComponentIndex(SpriteComponent* inComponent) const;

	sf::Vector2f FindPlayerCentrePoint();

private:

	RenderManager();

	uint8_t FindPlayerHealth();
	sf::Vector2f AlivePlayers();

	//this can't be only place that holds on to component- it has to live inside a GameObject in the world
	vector< SpriteComponent* >		mComponents;

	sf::View view;
	sf::Sprite m_city;
	sf::Sprite m_deathScreen;
	sf::Sprite m_winScreen;
	sf::Sprite m_lastPos;
};


