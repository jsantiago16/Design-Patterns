//Behavioral Pattern
class Observer
{
	protected:
		Observer() {}
	public:
		virtual ~Observer() {}
		virtual void update (Subject* s ) = 0;
		//might need to assign
		//delete or default instead of 0

};

//for demo
const int MAX_OBSERVERS = 10;

class Subject
{
	private:
		Observer** theObservers;
		int 	   count;

	protected:
		Subject();

	public:
		virtual ~Subject();
		virtual void attach (Observer* o);
		virtual void detach (Observer* o);
		virtual void notify();
};

Subject:: Subject()
{
	//better to use a dynamic data structure like
	//List or Vector that grows and shrinks based on its size

	the Observers = new Observer*[MAX_OBSERVERS]
	count = 0;
}

Subject::~Subject()
{
	delete[] theObservers;
}

void Subject::detach (Observer* o)
{
	//not implemented
}
void Subject::notify()
{
	for (int i - 0; i <count; i++)
	{
		theObservers[i] -> update(this)
	}
}

/*
	Counter is the example
*/

class Counter :: public Subject
{
		protected:
			int value;

		public:
			Counter() { value = 0;}
			Counter(int initValue)
			{
				value = initValue;
			}
			int getCount() { return value;)

			void increment()
			{
				value++;
				notify();
			}
};

/* Text view of counter

*/
class CounterTextView: public Observer
{
	public:
		CounterTextView (Counter* theCounter)
		{
			theCounter->attach(this)
		}

		void update (Subject * theSubject)
		{
			Counter* theCounter = (Counter *) theSubject;
			cout << "Counter value = "<< theCounter ->getCount()<<endl;
		}
};

/*
	Pseudo-Graphical View of counter
*/
class CounterGraohicalView: public Observer
{
	public:
		CounterGraphicalView (Counter* theCounter)
		{
			theCounter->attach(this);
		}
		void update (Subject * theSubject);
};

void CounterGraphicalView::update(Subject* theSubject)
{
	Counter* theCounter = (Counter*) theSubject;
	int value = theCounter->getCount();

	for(int i = 1; i <= value; ++i)
	{
		cout << "* ";
	}
	cout <<endl;
}
/*
	Counter app with text and pseudo-graphical views
*/

void main()
{

}