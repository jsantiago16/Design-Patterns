//creational pattern
class Singleton
{
	private:
		static Singleton* _instance;

	protected:
		Singleton();

	public:
		static Singleton* getSingleton();

};

Singleton* Singleton::_instance = 0;

Singleton* Singleton::getSingleton()
{
	if (_instance == 0)
	{
		_instance = new Singleton;
	}
	return _instance;

}