package de.dfki.resc28.realsense4j;


public class Context 
{
	public static synchronized Context getInstance()
	{
		if (inst == null)
		{
			inst = new Context();
			inst.initialise();
		}
		
		return inst;
	}
	
	//================================================================================
    // Public Methods
    //================================================================================

	/**
	 * Counts available devices
	 * @return
	 */
	public native int getDeviceCount();
	
	/**
	 * Gets Device with given index
	 * @param index
	 * @return
	 * @throws Exception
	 */
	public Device getDevice(int index) throws Exception
	{
		long handle = getDeviceNative(index);
		
		if (handle != 0) 
			return new Device(handle);
		else 
			throw new Exception();
	}
	
	//================================================================================
    // Private Methods
    //================================================================================

	private Context() { initialise(); }
	private native void initialise();	
	private native long getDeviceNative(int index);
	
	//================================================================================
    // Private Members
    //================================================================================
	
	private long nativeHandle;
	private static Context inst;
	
	static { de.dfki.resc28.realsense4j.nar.NarSystem.loadLibrary(); }
//	static { System.loadLibrary("realsense4j"); }
}
