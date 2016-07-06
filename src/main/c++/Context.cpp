#include "de_dfki_resc28_realsense4j_Context.h"
#include "rs.hpp"
#include "handle.h"
#include <stdio.h>

void Java_de_dfki_resc28_realsense4j_Context_initialise (JNIEnv *env, jobject obj)
{
    setHandle(env, obj, new rs::context);
}


jint Java_de_dfki_resc28_realsense4j_Context_getDeviceCount (JNIEnv *env, jobject obj)
{
    return getHandle<rs::context>(env,obj)->get_device_count();
}



jlong Java_de_dfki_resc28_realsense4j_Context_getDeviceNative (JNIEnv *env, jobject obj, jint i)
{
    auto dev = getHandle<rs::context>(env,obj)->get_device(i);
    return (jlong)dev;
/*
    jclass devClass = env->FindClass("de/dfki/resc28/realsense4j/Device");
    jmethodID ctor = env->GetMethodID(devClass, "<init>", "()V");
    jobject device = env->NewObject(devClass, ctor);
    
    return device;
 */
}