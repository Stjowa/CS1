import java.util.ArrayList;

public class MultiBug 
{
	ArrayList<Integer> cordX;
	int START=42;
	int x;
	
	public MultiBug() 
	{
		cordX=new ArrayList<Integer>();
		for(int i=1; i<=8; i++)
		{
			x=START+i*40;
			cordX.add(x);
		}
		for(int i=1; i<=8; i++)
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