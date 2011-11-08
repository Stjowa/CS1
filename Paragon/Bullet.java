//import java.awt.event.*;
import java.awt.Graphics2D;
//import java.awt.image.*;
//import java.awt.image.*;
//import java.awt.image.*;

public class Bullet
{
	Graphics2D g2;
	int x,y=-10;
	
	public Bullet()
	{
	}
	public void update(int count)
	{
		if(count%2==0)
		{
			y--;
		}
	}
	public void shoot(int x1)
	{
			y=440;
			x=x1;
	}
	public int getY()
	{
		return y;
	}
	public int getX()
	{
		return x+12;
	}
	public void changeY()
	{
		y=-100;
	}
}
