package com.iflytek.ndktest;

import androidx.appcompat.app.AppCompatActivity;
import me.jessyan.autosize.internal.CustomAdapt;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.iflytek.ndktest.jni.TestDynamic;
import com.iflytek.ndktest.jni.TestJni;

public class MainActivity extends AppCompatActivity implements CustomAdapt
{

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("people-lib");
    }

    private TestJni testJni;

    private TestDynamic testDynamic;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        testJni = new TestJni();
        testDynamic = new TestDynamic();
        String s = testJni.getA();
        tv.setText(testDynamic.sayHello());
    }

    public void test() {
        Log.e("ylli10", "test: ");
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String getA();
    
    /**
     * 是否按照宽度进行等比例适配 (为了保证在高宽比不同的屏幕上也能正常适配, 所以只能在宽度和高度之中选择一个作为基准进行适配)
     *
     * @return {@code true} 为按照宽度进行适配, {@code false} 为按照高度进行适配
     */
    @Override
    public boolean isBaseOnWidth() {
        return false;
    }

    @Override
    public float getSizeInDp() {
        return 0;
    }
}
