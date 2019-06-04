package com.lin.ccalljava;

import android.util.Log;

/**
 * @author lin
 * 创建日期：2019/6/4 09
 * 描述：Jni
 */
public class Jni {

    {
        System.loadLibrary("hi");
    }

    public native void addCCallJava();

    public native void sayHelloCCallJava();

    public native void printStringCCallJava();

    public native void staticCCallJava();

    public int add(int a, int b) {
        Log.d("-------lin---------", "add: x=" + a + ", y=" + b);
        return a + b;
    }

    public void sayHello() {
        Log.d("-------lin---------", "sayHello: 无参调用");
    }

    public void printString(String s) {
        Log.d("-------lin---------", "printString: 有参调用 content==" + s);
    }
    public static void staticMethod(String s) {
        Log.d("-------lin---------", "staticMethod: 静态有参调用 content==" + s);
    }
}
