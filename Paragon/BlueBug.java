import java.util.ArrayList;

public class BlueBug
{
	ArrayList<Integer> cordX;
	int START=2;
	int x;
	
	public BlueBug()
	{
		cordX=new ArrayList<Integer>();
		for(int i=1; i<=10; i++)
		{
			x=START+i*40;
			cordX.add(x);
		}
		for(int i=1; i<=10; i++)
		{
			x=START+i*40;
			cordX.add(x);
		}
	}
	public ArrayList<Integer> getArrayX ()
	{
		return cordX;
	}
	public void hit(int index)
	{
		cordX.set(index,-100);
	}
}
