//Behavioral Pattern
/*
 * Counter application with text and graphical views
 */
import java.util.Observable;
import java.util.Observer;

public class CounterApp
{
	public static void main (String args[])
	{
		Counter ctr = new Counter (0);
		CounterGui gui = new CounterGui(ctr);
		CounterTextView textView = new CounterTextView();

		ctr.addObserver(gui);
		ctr.addObserver(textView);
	}

}

/** a simple counter */
public class Counter extends Observable
{
	protected int value = 0;

	public Counter() {}

	public Counter (int intValue)
	{
		value = intValue;
	}

	public int getCount()
	{
		return value;
	}
	public void increment()
	{
		value++;
		setChanged();
		notifyObservers();
	}

}

public class CounterTextView implements Observer
{
	public void update(Observable o Object arg)
	{
		Counter theModel = (Counter) o;
		System.out.println ( "Counter value = "
		+ theModel.getCount());
	}
}

import java.awt.*;
import java.awt.event.*;
import java.util.*;

/**
*	Graphical view of counter
*/

public class CounterGui extends Frame
implements Observer, ActionListener
{
	protected TextField counterField;
	protected Counter	counterObject;

	public CounterGui (Counter ctr)
	{
		super("Graphical View")l
		setLayout(new FlowLayout())
	}

	// A reference to the model is needed
	// since the GUI is also the Controller
	// following the MVC Design Pattern
	counterObject = ctr

	counterField = new TextField(10)
	counterField.setText("" +
		 counterObject.getCount());
	add(counterField);

	Button b = new Button("Increment");
	add(b);
	b.addActionListener(this);

	setSize(300,100);
	setVisible(true);

	}

	public void actionPerformed (ActionEvent e)
	{
		counterObject.increment();
	}

	public void update (Observable o, Object arg)
	{
		Counter theModel = (Counter) o;
		counterField.setText("" +
			theModel.getCount());
	}

