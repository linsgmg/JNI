//
// Created by Mr.Chan on 2019/6/4.
//

#include "com_lin_ccalljava_Jni.h"
#include <android/log.h>

#define LOG_TAG "-------lin---------"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

JNIEXPORT void JNICALL Java_com_lin_ccalljava_Jni_addCCallJava
        (JNIEnv *env, jobject jobj) {
    //1. 得到字节码
    jclass jclass1 = (*env)->FindClass(env, "com/lin/ccalljava/Jni");
    //2. 得到方法  jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1 = (*env)->GetMethodID(env, jclass1, "add", "(II)I");
    //3. 实例化该类  jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject1 = (*env)->AllocObject(env, jclass1);
    //4. 调用方法  jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    jint value = (*env)->CallIntMethod(env, jobject1, jmethodID1, 99, 1);
    //成功调用了
    LOGD("value===%d\n", value);
}

JNIEXPORT void JNICALL Java_com_lin_ccalljava_Jni_sayHelloCCallJava
        (JNIEnv *env, jobject jobj) {
    //1. 得到字节码
    jclass jclass1 = (*env)->FindClass(env, "com/lin/ccalljava/Jni");
    //2. 得到方法  jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1 = (*env)->GetMethodID(env, jclass1, "sayHello", "()V");
    //3. 实例化该类  jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject1 = (*env)->AllocObject(env, jclass1);
    //4. 调用方法  jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env, jobject1, jmethodID1);
    //成功调用了
    LOGD("value===%s\n", "c sayHello无参调用java");
}

JNIEXPORT void JNICALL Java_com_lin_ccalljava_Jni_printStringCCallJava
        (JNIEnv *env, jobject jobj) {
//1. 得到字节码
    jclass jclass1 = (*env)->FindClass(env, "com/lin/ccalljava/Jni");
//2. 得到方法  jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1 = (*env)->GetMethodID(env, jclass1, "printString",
                                               "(Ljava/lang/String;)V");
//3. 实例化该类  jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobject1 = (*env)->AllocObject(env, jclass1);
//4. 调用方法  jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
//   新建一个字符串 jstring     (*NewStringUTF)(JNIEnv*, const char*);
    jstring s = (*env)->NewStringUTF(env, "I am from c");
    (*env)->CallVoidMethod(env, jobject1, jmethodID1, s);
    //成功调用了
    LOGD("value===%s\n", "c 有参调用java");
}

/**
 * 静态方法不需要实例化该类
 * @param env
 * @param jobj
 */
JNIEXPORT void JNICALL Java_com_lin_ccalljava_Jni_staticCCallJava
        (JNIEnv *env, jobject jobj) {
//1. 得到字节码
    jclass jclass1 = (*env)->FindClass(env, "com/lin/ccalljava/Jni");
//2. 得到方法  jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1 = (*env)->GetStaticMethodID(env, jclass1, "staticMethod",
                                                     "(Ljava/lang/String;)V");
//3. 调用方法  jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
//   新建一个字符串 jstring     (*NewStringUTF)(JNIEnv*, const char*);
    jstring s = (*env)->NewStringUTF(env, "I am from c");
    (*env)->CallStaticVoidMethod(env, jclass1, jmethodID1, s);
    //成功调用了
    LOGD("value===%s\n", "c 静态有参调用java");
}

JNIEXPORT void JNICALL
Java_com_lin_ccalljava_MainActivity_showToastCCallJava(JNIEnv *env, jobject instance) {

    // TODO
    //1. 得到字节码
    jclass jclass1 = (*env)->FindClass(env, "com/lin/ccalljava/MainActivity");
//2. 得到方法  jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodID1 = (*env)->GetMethodID(env, jclass1, "showToast", "()V");
//3. 调用方法  jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    (*env)->CallVoidMethod(env, instance, jmethodID1);//Activity中UI更新,不能实例化,所以用上下文 instance
    //成功调用了
    LOGD("value===%s\n", "c 无参调用java,更新UI");
}
