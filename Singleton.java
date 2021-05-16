//creational pattern
class Singleton
{
	private static Singleton instance = null;

	protected Singleton() { // not preconstructed}

	public static Singleton getSingleton()
	{
		if (instance == null)
		{
			instance = new Singleton();
		}
		return instance;
	}

}

//Variation where the sole instance is constructed as soon as class is loaded
class Singleton
{
	private static Singleton instance = new Singleton();

	protected Singleton () {//preconstructed }

	public static Singleton getSingleton()
	{
		return instance;
	}
}