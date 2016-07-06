/**
 * 
 */
package de.dfki.resc28.realsense4j.util;

/**
 * @author resc01
 *
 */
public enum Preset 
{
	BEST_QUALITY (0),
	LARGEST_IMAGE (1),
	HIGHEST_FRAMERATE (2);
	
	Preset(int presetCode)
	{
		m_presetCode = presetCode;
	}
	
	private final int m_presetCode;
}
