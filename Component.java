//structural pattern
abstract class Component
{
		abstract void operation();
}
class Button extends Component
{
	void operation () {}
}
class Composite extends Component
{
	void add (Component c ) {}
	void remove (Component d) {}
	void operation()
	{
		// for each child component c
		//		c.operation()
	}
}
