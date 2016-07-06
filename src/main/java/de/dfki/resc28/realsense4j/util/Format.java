/**
 * 
 */
package de.dfki.resc28.realsense4j.util;

/**
 * @author resc01
 *
 */
public enum Format 
{
	ANY (0),
	/**
	 * 16 bit linear depth values. The depth is meters is equal to depth scale * pixel value
	 */
	Z16 (1),
	/**
	 * 16 bit linear disparity values. The depth in meters is equal to depth scale / pixel value
	 */
	DISPARITY16 (2),
	/**
	 * 32 bit floating point 3D coordinates.
	 */
	XYZ32F (3),
	YUYV (4),
	RGB8 (5),
	BGR8 (6),
	RGBA8 (7),
	BGRA8 (9),
	Y8 (9),
	Y16 (10),
	/**
	 * Four 10-bit luminance values encoded into a 5-byte macropixel
	 */
	RAW10 (11);
	
	Format(int formatCode) 
	{
		m_formatCode = formatCode;
	}
	
	private final int m_formatCode;
}
