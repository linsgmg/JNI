package com.lin.ccalljava;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {
    private Jni jni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        jni = new Jni();
    }

    public void onclick(View view) {
        jni.addCCallJava();
    }

    public void onclick2(View view) {
        jni.sayHelloCCallJava();
    }

    public void onclick3(View view) {
        jni.printStringCCallJava();
    }

    public void onclick4(View view) {
        jni.staticCCallJava();
    }
}
