package com.lin.jni63;

/**
 * @author lin
 * 创建日期：2019/6/3 08
 * 描述：Jni
 */
public class Jni {
    static {
        System.loadLibrary("hello");
    }
    public native String sayHello(String s);
    public native int add(int a, int b);
    public native int[] append(int[] array);
    public native int check(String pwd);
}
