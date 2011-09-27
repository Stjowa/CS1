import java.util.ArrayList;

public class Enemy 
{
	ArrayList<Integer> enemiesX,enemiesY;
	int x,y;
	
	public Enemy(int x1, int y1) 
	{
		x=x1;
		y=y1;
		for (int i=0;i<40;i++)
		{
			
		}
	}
	public int enemyGetX()
	{
		for(int i=0; i<enemiesX.size(); i++)
		{
			if (x==enemiesX.get(i))
			{
				return enemiesX.get(i);
			}
		}
		return -100;
	}
	public int enemyGetY()
	{
		for(int i=0; i<enemiesY.size(); i++)
		{
			if (y==enemiesY.get(i))
			{
				return enemiesY.get(i);
			}
		}
		return -100;
	}
}
