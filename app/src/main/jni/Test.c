//
// Created by Mr.Chan on 2019/6/3.
//
#include "com_lin_jni63_Jni.h"
#include <string.h>
#include <malloc.h>

/**
 * 把一个jstring转换成一个c语音的char* 类型
 * @param env
 * @param jstr
 * @return
 */
char *Jstring2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass clsstring = (*env)->FindClass(env, "java/lang/String");
    jstring strencode = (*env)->NewStringUTF(env, "GB2312");
    jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes",
                                        "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) (*env)->CallObjectMethod(env, jstr, mid,
                                                            strencode); // String .getByte("GB2312");
    jsize alen = (*env)->GetArrayLength(env, barr);
    jbyte *ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(alen + 1);         //"\0"
        memcpy(rtn, ba, alen);
        rtn[alen] = 0;
    }
    (*env)->ReleaseByteArrayElements(env, barr, ba, 0);  //
    return rtn;
}

JNIEXPORT jstring JNICALL Java_com_lin_jni63_Jni_sayHello
        (JNIEnv *env, jobject jobj, jstring js) {
    char *c = " add I am from c";
    char *java = Jstring2CStr(env, js);
    strcat(java, c);
    return (*env)->NewStringUTF(env, java);
}

JNIEXPORT jint JNICALL Java_com_lin_jni63_Jni_add
        (JNIEnv *env, jobject instance, jint a, jint b) {
    int result = a + b;
    return result;
}

JNIEXPORT jintArray JNICALL
Java_com_lin_jni63_Jni_append(JNIEnv *env, jobject instance, jintArray array_) {
//    jsize       (*GetArrayLength)(JNIEnv*, jarray);
    int length = (*env)->GetArrayLength(env, array_);
    jint *array = (*env)->GetIntArrayElements(env, array_, JNI_FALSE);
    int i=0;
    for (; i < length; i++) {
        *(array + i) += 5;
    }
    return array_;
}

JNIEXPORT jint JNICALL Java_com_lin_jni63_Jni_check
(JNIEnv *env, jobject jobj, jstring js) {
    char *c = "123";
    char *java = Jstring2CStr(env, js);
    int result = strcmp(c, java);
    return result;
}