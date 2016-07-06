/**
 * 
 */
package de.dfki.resc28.realsense4j.util;

/**
 * @author resc01
 *
 */
public enum Distortion 
{
	/**
	 * Rectilinear images, no distortion compensation required
	 */
	NONE (0),
	/**
	 * Equivalent to Brown-Conrady distortion, except that tangential distortion is applied to radially distorted points
	 */
	MODIFIED_BROWN_CONRADY (1),
	/**
	 * Equivalent to Brown-Conrady distortion, except undistorts image instead of distorting it
	 */
	INVERSE_BROWN_CONRADY (2);
	
	Distortion(int distortionCode)
	{
		m_distortionCode = distortionCode;
	}
	
	private final int m_distortionCode;
}
