package com.lin.jni63;

import android.content.ComponentName;
import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    private TextView tv;
    private Jni jni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tv = findViewById(R.id.tv);
    }

    public void onClick01(View view) {
        jni = new Jni();
        String s = jni.sayHello("I am from Java");
        tv.setText(s);
    }

    public void onClick02(View view) {
        jni = new Jni();
        int add = jni.add(99, 1);
        tv.setText(add + "");
    }

    public void onClick03(View view) {
        jni = new Jni();
        int[] array = {1, 2, 3, 4, 5};
        jni.append(array);
        tv.setText("");
        for (int i = 0; i < array.length; i++) {
            tv.append(array[i] + "\n");
        }
    }

    public void onClick04(View view) {
        jni = new Jni();
        int check = jni.check(123 + "");
        tv.setText(check + "");
    }
}
