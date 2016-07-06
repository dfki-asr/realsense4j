package de.dfki.resc28.realsense4j;

import java.awt.FlowLayout;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.awt.image.ComponentSampleModel;
import java.awt.image.DataBuffer;
import java.awt.image.DataBufferByte;
import java.awt.image.Raster;
import java.awt.image.SampleModel;
import java.awt.image.WritableRaster;
import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.InputStream;
import java.nio.ByteBuffer;
import java.nio.IntBuffer;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

import de.dfki.resc28.realsense4j.util.Option;
import de.dfki.resc28.realsense4j.util.Preset;
import de.dfki.resc28.realsense4j.util.Stream;

public class BasicTest 
{

	public static void main(String[] args) 
	{
		Context c = Context.getInstance();
		
		try
		{
			int count = c.getDeviceCount();
			System.out.println(count);
			
			Device dev = c.getDevice(0);
			
			System.out.println(dev.supportsOption(Option.COLOR_BACKLIGHT_COMPENSATION));
			
			System.out.println(dev.getName());
			
			System.out.println(dev.getStreamModeCount(Stream.COLOR));
			
			dev.enableStream(Stream.COLOR, Preset.HIGHEST_FRAMERATE);
			System.out.println(dev.getStreamFormat(Stream.COLOR).name());
			
			dev.start();

	        JFrame frame=new JFrame();
	        frame.setLayout(new FlowLayout());
	        frame.setSize(200,300);
	        JLabel lbl=new JLabel();
	        frame.add(lbl);
	        frame.setVisible(true);
	        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	        
			while(true)
			{
				System.out.println(dev.getFrameTimestamp(Stream.COLOR));
				dev.waitForFrames();
				
				
				ByteBuffer frameData = dev.getFrameData(Stream.COLOR);
				byte[] bytes = new byte[frameData.capacity()];
				frameData.get(bytes);
				
				int width =  dev.getStreamWidth(Stream.COLOR);
				int height = dev.getStreamHeight(Stream.COLOR); 
				
				
				BufferedImage img = new BufferedImage(width, height, BufferedImage.TYPE_3BYTE_BGR);
				DataBuffer buffer = new DataBufferByte(bytes, bytes.length);
				SampleModel sampleModel = new ComponentSampleModel(DataBuffer.TYPE_BYTE, 
																   width,
																   height,
																   3,
																   width*3, 
																   new int[]{0,1,2});
		 
				Raster raster = Raster.createRaster(sampleModel, buffer, null);
				img.setData(raster);

				ImageIcon icon=new ImageIcon(img);

		        lbl.setIcon(icon);

				
//				ImageIO.write(img, "jpg", new File("/Users/resc01/Documents/workspace/Realsense4J/src/output.jpg"));
			}
		
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
}
