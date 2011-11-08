//import java.io.File;
import java.io.IOException;

import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.LineEvent;
import javax.sound.sampled.LineListener;
import javax.sound.sampled.LineUnavailableException;
import java.net.*;

public class ClipPlayer extends Thread implements LineListener
{
	private Clip m_clip;
	private URL clipName;
	private int loopNum;
	
	 //	The clip will be played nLoopCount + 1 times.
	 
	public ClipPlayer(URL clipFile, int nLoopCount)
	{
		clipName=clipFile;
		loopNum=nLoopCount;
	}
	public void update(LineEvent event)
	{
		if (event.getType().equals(LineEvent.Type.STOP))
		{
			m_clip.close();
		}
		else if (event.getType().equals(LineEvent.Type.CLOSE))
		{
			//System.exit(0);
		}
	}
	public void run()
	{
		AudioInputStream audioInputStream = null;
		try
		{
			//System.out.println("Audio Name: "+clipName);
			audioInputStream = AudioSystem.getAudioInputStream(clipName);
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
		if (audioInputStream != null)
		{
			AudioFormat	format = audioInputStream.getFormat();
			DataLine.Info	info = new DataLine.Info(Clip.class, format);
			try
			{
				m_clip = (Clip) AudioSystem.getLine(info);
				m_clip.addLineListener(this);
				m_clip.open(audioInputStream);
			}
			catch (LineUnavailableException e)
			{
				e.printStackTrace();
			}
			catch (IOException e)
			{
				e.printStackTrace();
		}
			m_clip.loop(loopNum);
		}
		else
		{
			out("ClipPlayer.<init>(): can't get data from file " + clipName.getFile());
		}
	}
	private static void out(String strMessage)
	{
		System.out.println(strMessage);
	}
}