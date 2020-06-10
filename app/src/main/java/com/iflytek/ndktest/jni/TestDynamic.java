package com.iflytek.ndktest.jni;

import android.util.Log;

/**
 * 文 件 名：TestDynamic
 * 创 建 人：李跃龙
 * 创建日期：2020/4/27 14:08
 * 邮    箱：ylli10@iflytek.com
 * 功    能：
 * 修 改 人：
 * 修改时间：
 * 修改备注：
 */
public class TestDynamic {
    static {
        Log.e("ylli10", "static Test_dynamic: " );
        System.loadLibrary("Test_dynamic");
    }
    
    public native String sayHello();
}
