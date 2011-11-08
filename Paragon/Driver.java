import javax.swing.*;
import java.awt.*;
//import java.awt.geom.*;
//import java.util.*;
import java.awt.image.*;
//import java.io.File;
//import java.net.*;
//import java.io.*;
import java.awt.event.*;
//import java.applet.Applet;
//import java.applet.AudioClip;
//import java.io.File;
//import java.net.MalformedURLException;
//import java.net.URL;

//Stephen Walentik and Justin McIssac
//Galaga created by Namco
//Remade by Paragon

public class Driver extends JApplet implements KeyListener
{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int countLife, countShot=1000;
	int x=235,y,z;
	int bullx, bully;
	boolean left, right;
	Player player1 = new Player();
	Player player2 = new Player();
	BufferedImage bb;
	Graphics2D g2;
	ImageIcon background, spaceship, enemy1, enemy2, enemy3, enemy12, enemy22, enemy32, bullet;
	ClipPlayer beginingAudio, shoot;
	Bullet bullet1, bullet2;
	BlueBug bluebug = new BlueBug();
	RedBug redbug = new RedBug();
	
	public void init()
	{
		setSize(500,500);
		addKeyListener(this);
		background = new ImageIcon(getClass().getResource("background.gif"));
		spaceship = new ImageIcon(getClass().getResource("spaceship1.png"));
		enemy1 = new ImageIcon(getClass().getResource("enemy1.png"));
		enemy2 = new ImageIcon(getClass().getResource("enemy2.png"));
		enemy3 = new ImageIcon(getClass().getResource("enemy3.png"));
		enemy12 = new ImageIcon(getClass().getResource("enemy12.png"));
		enemy22 = new ImageIcon(getClass().getResource("enemy22.png"));
		enemy32 = new ImageIcon(getClass().getResource("enemy32.png"));
		bullet = new ImageIcon(getClass().getResource("bullet.png"));
		bb = new BufferedImage(500,500,BufferedImage.TYPE_INT_RGB);
 		g2 = bb.createGraphics();
 		beginingAudio = new ClipPlayer(getClass().getResource("GalagaStart.wav"),0);
 		bullet1=new Bullet ();
 		bullet2=new Bullet ();
	}
	public void paint (Graphics g)
	{
		//super.paint(g);
		if(z==0)
		{
			beginingAudio.start();
		}
		if(z==10000)
		{
			z=1;
		}
		g.drawImage(bb,0,0,this);
		if(z%15==0||z==0)
		{
			g2.drawImage(background.getImage(),0,y-500,this);
			y++;
			if(y-500==0)
			{
				y=0;
			}
		}
		if(z%8==0)
		{
			if(left)
			{
				x-=1;
				if(x<=0)
				{
					x=0;
				}
			}
			if(right)
			{
				x+=1;
				if(x>=470)
				{
					x=470;
				}
			}
		}
		g2.drawImage(spaceship.getImage(),x,450,this);
		//Green Guys
		if((z/1000)%2==0)
		{
			g2.drawImage(enemy3.getImage(),160,50,this);
			g2.drawImage(enemy3.getImage(),198,50,this);
			g2.drawImage(enemy3.getImage(),241,50,this);
			g2.drawImage(enemy3.getImage(),279,50,this);
		}
		else
		{
			g2.drawImage(enemy32.getImage(),160,50,this);
			g2.drawImage(enemy32.getImage(),198,50,this);
			g2.drawImage(enemy32.getImage(),241,50,this);
			g2.drawImage(enemy32.getImage(),279,50,this);
		}
		//Red Guys Row 1
		if((z/1000)%2==0)
		{
			for(int i=0; i<8; i++)
			{
				g2.drawImage(enemy2.getImage(),redbug.getArrayX().get(i),90,this);
				if(bullet1.getX()>=redbug.getArrayX().get(i)-4&&bullet1.getX()<=redbug.getArrayX().get(i)+30&&bullet1.getY()==70)
				{
					bullet1.changeY();
					redbug.hit(i);
				}
				if(bullet2.getX()>=redbug.getArrayX().get(i)-4&&bullet2.getX()<=redbug.getArrayX().get(i)+30&&bullet2.getY()==70)
				{
					bullet2.changeY();
					redbug.hit(i);
				}
			}
		}
		else
		{
			for(int i=0; i<8; i++)
			{
				g2.drawImage(enemy22.getImage(),redbug.getArrayX().get(i)+4,90,this);
				if(bullet1.getX()>=redbug.getArrayX().get(i)&&bullet1.getX()-1<=redbug.getArrayX().get(i)+25&&bullet1.getY()==70)
				{
					bullet1.changeY();
					redbug.hit(i);
				}
				if(bullet2.getX()>=redbug.getArrayX().get(i)&&bullet2.getX()-1<=redbug.getArrayX().get(i)+25&&bullet2.getY()==70)
				{
					bullet2.changeY();
					redbug.hit(i);
				}
			}
		}
		//Red Guys Row 2
		if((z/1000)%2==0)
		{
			// Width 26
			for(int i=8; i<16; i++)
			{
				g2.drawImage(enemy2.getImage(),redbug.getArrayX().get(i),120,this);
				if(bullet1.getX()>=redbug.getArrayX().get(i)-4&&bullet1.getX()<=redbug.getArrayX().get(i)+30&&bullet1.getY()==100)
				{
					bullet1.changeY();
					redbug.hit(i);
				}
				if(bullet2.getX()>=redbug.getArrayX().get(i)-4&&bullet2.getX()<=redbug.getArrayX().get(i)+30&&bullet2.getY()==100)
				{
					bullet2.changeY();
					redbug.hit(i);
				}
			}
		}
		else
		{
			//Width 18
			for(int i=8; i<16; i++)
			{
				g2.drawImage(enemy22.getImage(),redbug.getArrayX().get(i)+4,120,this);
				if(bullet1.getX()>=redbug.getArrayX().get(i)&&bullet1.getX()<=redbug.getArrayX().get(i)+24&&bullet1.getY()==100)
				{
					bullet1.changeY();
					redbug.hit(i);
				}
				if(bullet2.getX()>=redbug.getArrayX().get(i)&&bullet2.getX()<=redbug.getArrayX().get(i)+24&&bullet2.getY()==100)
				{
					bullet2.changeY();
					redbug.hit(i);
				}
			}
		}
		//Blue Guys Row 1
		if((z/1000)%2==0)
		{
			//Width 26
			for(int i=0; i<10; i++)
			{
				g2.drawImage(enemy1.getImage(),bluebug.getArrayX().get(i),150,this);
				if(bullet1.getX()>=bluebug.getArrayX().get(i)-4&&bullet1.getX()<=bluebug.getArrayX().get(i)+30&&bullet1.getY()==130)
				{
					bullet1.changeY();
					bluebug.hit(i);
				}
				if(bullet2.getX()>=bluebug.getArrayX().get(i)-4&&bullet2.getX()<=bluebug.getArrayX().get(i)+30&&bullet2.getY()==130)
				{
					bullet2.changeY();
					bluebug.hit(i);
				}
			}
		}
		else
		{
			//Width 18
			for(int i=0; i<10; i++)
			{
				g2.drawImage(enemy12.getImage(),bluebug.getArrayX().get(i)+4,150,this);
				if(bullet1.getX()>=bluebug.getArrayX().get(i)-1&&bullet1.getX()<=bluebug.getArrayX().get(i)+25&&bullet1.getY()==130)
				{
					bullet1.changeY();
					bluebug.hit(i);
				}
				if(bullet2.getX()>=bluebug.getArrayX().get(i)-1&&bullet2.getX()<=bluebug.getArrayX().get(i)+25&&bullet2.getY()==130)
				{
					bullet2.changeY();
					bluebug.hit(i);
				}
			}
		}
		//Blue Guys Row 2
		if((z/1000)%2==0)
		{
			for(int i=10; i<20; i++)
			{
				g2.drawImage(enemy1.getImage(),bluebug.getArrayX().get(i),180,this);
				if(bullet1.getX()>=bluebug.getArrayX().get(i)-4&&bullet1.getX()<=bluebug.getArrayX().get(i)+30&&bullet1.getY()==160)
				{
					bullet1.changeY();
					bluebug.hit(i);
				}
				if(bullet2.getX()>=bluebug.getArrayX().get(i)-4&&bullet2.getX()<=bluebug.getArrayX().get(i)+30&&bullet2.getY()==160)
				{
					bullet2.changeY();
					bluebug.hit(i);
				}
			}
		}
		else
		{
			for(int i=10; i<20; i++)
			{
				g2.drawImage(enemy12.getImage(),bluebug.getArrayX().get(i)+4,180,this);
				if(bullet1.getX()>=bluebug.getArrayX().get(i)-1&&bullet1.getX()<=bluebug.getArrayX().get(i)+25&&bullet1.getY()==160)
				{
					bullet1.changeY();
					bluebug.hit(i);
				}
				if(bullet2.getX()>=bluebug.getArrayX().get(i)-1&&bullet2.getX()<=bluebug.getArrayX().get(i)+25&&bullet2.getY()==160)
				{
					bullet2.changeY();
					bluebug.hit(i);
				}
			}
		}
		g2.drawImage(bullet.getImage(),bullet1.getX(),bullet1.getY(),this);
		g2.drawImage(bullet.getImage(),bullet2.getX(),bullet2.getY(),this);
		bullet1.update(z);
		bullet2.update(z);
		updateScore();
		repaint(34,0,0,500,500);
		z++;
		countShot++;
	}
	public void updateScore()
	{
		if(player1.getScore()>=30000||((int)player1.getScore()/80000)>=1)
		{
			if(countLife==0)
			{
				player1.addLife();
				countLife++;
			}
			if(countLife!=(((int)player1.getScore()/80000)+1))
			{
				player1.addLife();
				countLife++;
			}
		}
	}
	public void keyPressed(KeyEvent e) 
 	{
 		if(e.getKeyCode()==KeyEvent.VK_LEFT)
 		{
 			left=true;
 		}
 		if(e.getKeyCode()==KeyEvent.VK_RIGHT)
 		{
 			right=true;
 		}
  	}
 	public void keyReleased(KeyEvent e) 
 	{
 		if(e.getKeyCode()==KeyEvent.VK_LEFT)
 		{
 			left=false;
 		}
 		if(e.getKeyCode()==KeyEvent.VK_RIGHT)
 		{
 			right=false;
 		}
 	}
 	public void keyTyped(KeyEvent e) 
 	{
 		if (countShot<=100)
 		{
 			return;
 		}
 		countShot=0;
 		if (e.getKeyChar() == 'z')
 		{
 			if (bullet1.getY()<0)
 			{
 				shoot = new ClipPlayer(getClass().getResource("shot.wav"),0);
 				shoot.start();
 				bullet1.shoot(x);
 				return;
 			}
 			if (bullet1.getY()>=0&&bullet2.getY()<0)
 			{
 				shoot = new ClipPlayer(getClass().getResource("shot.wav"),0);
 				shoot.start();
 				bullet2.shoot(x);
 				return;
 			}
 			if (bullet2.getY()>=0&&bullet1.getY()<0)
 			{
 				shoot = new ClipPlayer(getClass().getResource("shot.wav"),0);
 				shoot.start();
 				bullet1.shoot(x);
 				return;
 			}
 			if(bullet2.getY()>=0&&bullet1.getY()>=0)
 			{
 				return;
 			}
 		}
 		if (e.getKeyChar() == 'x')
 		{
 			if (bullet1.getY()<0)
 			{
 				shoot = new ClipPlayer(getClass().getResource("shot.wav"),0);
 				shoot.start();
 				bullet1.shoot(x);
 				return;
 			}
 			if (bullet1.getY()>=0&&bullet2.getY()<0)
 			{
 				shoot = new ClipPlayer(getClass().getResource("shot.wav"),0);
 				shoot.start();
 				bullet2.shoot(x);
 				return;
 			}
 			if (bullet2.getY()>=0&&bullet1.getY()<0)
 			{
 				shoot = new ClipPlayer(getClass().getResource("shot.wav"),0);
 				shoot.start();
 				bullet1.shoot(x);
 				return;
 			}
 			if(bullet2.getY()>=0&&bullet1.getY()>=0)
 			{
 				return;
 			}
 		}
 	}
 	public void out(Object obj)
 	{
 		System.out.println(obj);
 	}
}