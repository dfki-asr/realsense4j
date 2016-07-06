#include "de_dfki_resc28_realsense4j_Device.h"
#include "rs.hpp"
#include "handle.h"


jstring Java_de_dfki_resc28_realsense4j_Device_getName (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    return env->NewStringUTF(d->get_name());
}


jstring Java_de_dfki_resc28_realsense4j_Device_getSerial (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    return env->NewStringUTF(d->get_serial());
}

jstring Java_de_dfki_resc28_realsense4j_Device_getUsbPortID (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    return env->NewStringUTF(d->get_usb_port_id());
}

jstring Java_de_dfki_resc28_realsense4j_Device_getFirmwareVersion (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    return env->NewStringUTF(d->get_firmware_version());
}

jfloat Java_de_dfki_resc28_realsense4j_Device_getDepthScale (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    return d->get_depth_scale();
}

jboolean Java_de_dfki_resc28_realsense4j_Device_supportsOption (JNIEnv *env, jobject obj, jobject option)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    jmethodID optionGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Option"), "ordinal", "()I");
    jint value = env->CallIntMethod(option, optionGetValueMethod);
    
    return d->supports_option(static_cast<rs::option>(value));
}

jint Java_de_dfki_resc28_realsense4j_Device_getStreamModeCount (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint value = env->CallIntMethod(stream, streamGetValueMethod);
    
    return d->get_stream_mode_count(static_cast<rs::stream>(value));
}

void Java_de_dfki_resc28_realsense4j_Device_enableStream__Lde_dfki_resc28_realsense4j_util_Stream_2Lde_dfki_resc28_realsense4j_util_Preset_2 (JNIEnv *env, jobject obj, jobject stream, jobject preset)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    jmethodID presetGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Preset"), "ordinal", "()I");
    jint presetValue = env->CallIntMethod(preset, presetGetValueMethod);
    
    d->enable_stream(static_cast<rs::stream>(streamValue), static_cast<rs::preset>(presetValue));
}

void Java_de_dfki_resc28_realsense4j_Device_disableStream (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    d->disable_stream(static_cast<rs::stream>(streamValue));
}

jboolean Java_de_dfki_resc28_realsense4j_Device_isStreamEnabled (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    return d->is_stream_enabled(static_cast<rs::stream>(streamValue));
}

jint Java_de_dfki_resc28_realsense4j_Device_getStreamWidth (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    return d->get_stream_width(static_cast<rs::stream>(streamValue));
}

jint Java_de_dfki_resc28_realsense4j_Device_getStreamHeight (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    return d->get_stream_height(static_cast<rs::stream>(streamValue));
}

jobject Java_de_dfki_resc28_realsense4j_Device_getStreamFormat (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    // compare and switch (THIS SUCKS!)
    jclass formatClass = env->FindClass("de/dfki/resc28/realsense4j/util/Format");
    jfieldID javaFormat ;
    
    switch (static_cast<rs::format>(d->get_stream_format(static_cast<rs::stream>(streamValue))))
    {
        case rs::format::any:
            javaFormat = env->GetStaticFieldID(formatClass, "ANY", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::z16:
            javaFormat = env->GetStaticFieldID(formatClass, "Z16", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::disparity16:
            javaFormat = env->GetStaticFieldID(formatClass, "DISPARITY16", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::xyz32f:
            javaFormat = env->GetStaticFieldID(formatClass, "XYZ32F", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::yuyv:
            javaFormat = env->GetStaticFieldID(formatClass, "YUYV", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::rgb8:
            javaFormat = env->GetStaticFieldID(formatClass, "RGB8", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::bgr8:
            javaFormat = env->GetStaticFieldID(formatClass, "BGR8", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::rgba8:
            javaFormat = env->GetStaticFieldID(formatClass, "RGBA8", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::bgra8:
            javaFormat = env->GetStaticFieldID(formatClass, "BGRA8", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::y8:
            javaFormat = env->GetStaticFieldID(formatClass, "Y8", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::y16:
            javaFormat = env->GetStaticFieldID(formatClass, "Y16", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        case rs::format::raw10:
            javaFormat = env->GetStaticFieldID(formatClass, "RAW10", "Lde/dfki/resc28/realsense4j/util/Format;");
            break;
        default:
            javaFormat = env->GetStaticFieldID(formatClass, "ANY", "Lde/dfki/resc28/realsense4j/util/Format;");
    }
 
    return env->GetStaticObjectField(formatClass, javaFormat);
}

jint Java_de_dfki_resc28_realsense4j_Device_getStreamFramerate (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    return d->get_stream_framerate(static_cast<rs::stream>(streamValue));
}

void Java_de_dfki_resc28_realsense4j_Device_start (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    d->start();
}

void Java_de_dfki_resc28_realsense4j_Device_stop (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    d->stop();
}


jboolean Java_de_dfki_resc28_realsense4j_Device_isStreaming (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    return d->is_streaming();
}

void Java_de_dfki_resc28_realsense4j_Device_waitForFrames (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    d->wait_for_frames();
}

jboolean Java_de_dfki_resc28_realsense4j_Device_pollForFrames (JNIEnv *env, jobject obj)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    return d->poll_for_frames();
}

jint Java_de_dfki_resc28_realsense4j_Device_getFrameTimestamp (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    return d->get_frame_timestamp(static_cast<rs::stream>(streamValue));
}

jobject Java_de_dfki_resc28_realsense4j_Device_getFrameData (JNIEnv *env, jobject obj, jobject stream)
{
    rs::device *d = getHandle<rs::device>(env, obj);
    
    jmethodID streamGetValueMethod = env->GetMethodID(env->FindClass("de/dfki/resc28/realsense4j/util/Stream"), "ordinal", "()I");
    jint streamValue = env->CallIntMethod(stream, streamGetValueMethod);
    
    // returns void pointer
    int imageByteSize = d->get_stream_height(static_cast<rs::stream>(streamValue)) * d->get_stream_width(static_cast<rs::stream>(streamValue));
    
    int pixelByteSize;
    switch (static_cast<rs::format>(d->get_stream_format(static_cast<rs::stream>(streamValue))))
    {
        case rs::format::any:
            pixelByteSize = 4;
            break;
        case rs::format::z16:
            pixelByteSize = 2;
            break;
        case rs::format::disparity16:
            pixelByteSize = 2;
            break;
        case rs::format::xyz32f:
            pixelByteSize = 4;
            break;
        case rs::format::rgb8:
            pixelByteSize = 3;
            break;
        default:
            pixelByteSize = 2;
            break;
    }
    
    
    
    void *data = (void*)d->get_frame_data(static_cast<rs::stream>(streamValue));
    
    return env->NewDirectByteBuffer(data, (jlong)((long)(imageByteSize*pixelByteSize)));
}






