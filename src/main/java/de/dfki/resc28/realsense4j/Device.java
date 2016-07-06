package de.dfki.resc28.realsense4j;

import java.nio.ByteBuffer;

import de.dfki.resc28.realsense4j.util.Format;
import de.dfki.resc28.realsense4j.util.Option;
import de.dfki.resc28.realsense4j.util.Preset;
import de.dfki.resc28.realsense4j.util.Stream;

public class Device 
{
	//================================================================================
    // Constructor
    //===============================================================================

	protected Device(long handle)
	{
		nativeHandle = handle;
	}

	//================================================================================
    // Public Methods
    //================================================================================
	
	/**
	 * Retrieve a human readable device model string
	 * @return the model string, such as "Intel RealSense F200" or "Intel RealSense R200"
	 */
	public native String getName();
	
	/**
	 * Retrieve the unique serial number of the device
	 * @return the serial number, in a format specific to the device model
	 */
	public native String getSerial();
	
	/**
	 * Retrieve the USB port number of the device
	 * @return the USB port number, in a format specific to the device model
	 */
	public native String getUsbPortID();
	
	/**
	 * Retrieve the version of the firmware currently installed on the device
	 * @return   firmware version string, in a format is specific to device model
	 */
	public native String getFirmwareVersion();
	
	/**
	 * Retrieve extrinsic transformation between the viewpoints of two different streams
	 * @param from stream whose coordinate space we will transform from
	 * @param to stream whose coordinate space we will transform to
	 * @return the transformation between the two streams
	 */
	// FIXME
//	public native Extrinsics getExtrinsics(Stream from, Stream to);

	/**
	 * Retrieve mapping between the units of the depth image and meters
	 * @return depth in meters corresponding to a depth value of 1
	 */
	public native float getDepthScale();
	
	/**
	 * Determine if the device allows a specific option to be queried and set
	 * @param option the option to check for support
	 * @return true if the option can be queried and set
	 */
	public native boolean supportsOption(Option option);
	
	/**
	 * Determine the number of streaming modes available for a given stream
	 * @param stream the stream whose modes will be enumerated
	 * @return the count of available modes
	 */
	public native int getStreamModeCount(Stream stream);
	
	/**
	 * Determine the properties of a specific streaming mode
	 * @param stream the stream whose mode will be queried
	 * @param index the zero based index of the streaming mode
	 * @return
	 */
	// FIXME
//	public native StreamMode getStreamMode(Stream stream, int index);
	
	/**
	 * Enable a specific stream and request specific properties using a preset
	 * @param stream stream the stream to enable
	 * @param preset the preset to use to enable the stream
	 */
	public native void enableStream(Stream stream, Preset preset);
	
	/**
	 * Enable a specific stream and request specific properties
	 * @param stream the stream to enable
	 * @param width the desired width of a frame image in pixels, or 0 if any width is acceptable
	 * @param height the desired height of a frame image in pixels, or 0 if any height is acceptable
	 * @param format the pixel format of a frame image, or ANY if any format is acceptable
	 * @param framerate the number of frames which will be streamed per second, or 0 if any framerate is acceptable
	 */
	public native void enableStream(Stream stream, int width, int height, Format format, int framerate);
	
	/**
	 * Disable a specific stream	
	 * @param stream the stream to disable
	 */
	public native void disableStream(Stream stream);
	
	/**
	 * Determine if a specific stream is enabled
	 * @param stream the stream to check
	 * @return true if the stream is currently enabled
	 */
	public native boolean isStreamEnabled(Stream stream);
	
	/**
	 * Retrieve the width in pixels of a specific stream, equivalent to the width field from the stream's intrinsics
	 * @param stream the stream whose width to retrieve
	 * @return the width in pixels of images from this stream
	 */
	public native int getStreamWidth(Stream stream);
	
	/**
	 * Retrieve the height in pixels of a specific stream, equivalent to the height field from the stream's intrinsics
	 * @param stream the stream whose height to retrieve
	 * @return the height in pixels of images from this stream
	 */
	public native int getStreamHeight(Stream stream);
	
	/**
	 * Retrieve the pixel format for a specific stream
	 * @param stream the stream whose format to retrieve
	 * @return the pixel format of the stream
	 */
	public native Format getStreamFormat(Stream stream);
	
	/**
	 * Retrieve the framerate for a specific stream
	 * @param stream the stream whose framerate to retrieve
	 * @return the framerate of the stream, in frames per second
	 */
	public native int getStreamFramerate(Stream stream);
	
	/**
	 * Retrieve intrinsic camera parameters for a specific stream
	 * @param stream the stream whose parameters to retrieve
	 * @return the intrinsic parameters of the stream
	 */
	// FIXME
//	public native Intrinsics getStreamIntrinsics(Stream stream);
	
	/**
	 * Begin streaming on all enabled streams for this device
	 */
	public native void start();
	
	/**
	 * End streaming on all streams for this device
	 */
	public native void stop();
	
	/**
	 * Determine if the device is currently streaming
	 * @return true if the device is currently streaming
	 */
	public native boolean isStreaming();

	// FIXME
//	public native void getOptionRange(option option, double & min, double & max, double & step);
//	void get_options(const option * options, int count, double * values)
//	void set_options(const option * options, int count, const double * values)
	
	/**
	 * Retrieve the current value of a single option
	 * @param option the option whose value should be retrieved
	 * @return the value of the option
	 */
	public native double getOption(Option option);
	
	/**
	 * Set the current value of a single option
	 * @param option the option whose value should be set
	 * @param value the value of the option
	 */
	public native void setOption(Option option, double value);
	
	/**
	 * Block until new frames are available
	 */
	public native void waitForFrames();
	
	/**
	 * Check if new frames are available, without blocking
	 * @return true if new frames are available, false if no new frames have arrived
	 */
	public native boolean pollForFrames();
	
	/**
	 * Retrieve the time at which the latest frame on a stream was captured
	 * @param stream the stream whose latest frame we are interested in
	 * @return the timestamp of the frame, in milliseconds since the device was started
	 */
	public native int getFrameTimestamp(Stream stream);
	
	// FIXME
//	const void * get_frame_data(stream stream) const
	public native ByteBuffer getFrameData(Stream stream);
	
	//================================================================================
    // Private Members
    //================================================================================
	
	private long nativeHandle;
	
	static { de.dfki.resc28.realsense4j.nar.NarSystem.loadLibrary(); }
//	static { System.loadLibrary("realsense4j"); }
}
