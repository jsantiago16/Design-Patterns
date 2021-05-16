//structural pattern
class Component
{
	void operation() = ;
};
class Leaf: public Component
{
	void operation() {}

}
class Composite: public Component
{
	void add (Component* c ) {}
	void remove (Component* c) {}
	void operation ()
	{
		//for each child component c
		//  	c->operation()
	}

}