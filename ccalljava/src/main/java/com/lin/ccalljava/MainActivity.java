package com.lin.ccalljava;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

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

    public void onclick5(View view) {
        showToastCCallJava();
    }

    public native void showToastCCallJava();

    public void  showToast(){
        Log.d("-------lin---------", "showToast: -------------");
        Toast.makeText(this, "showToast: -------------", Toast.LENGTH_SHORT).show();
    }
}
