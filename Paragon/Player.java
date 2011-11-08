public class Player
{
	int life=3;
	int score;
	
	public Player()
	{
		
	}
	public int getScore()
	{
		return score;
	}
	public void addScore(int num)
	{
		score += num;
	}
	public void reset()
	{
		score = 0;
		life = 3;
	}
	public int getLife()
	{
		return life;
	}
	public void removeLife()
	{
		life--;
	}
	public void addLife()
	{
		life++;
	}
}