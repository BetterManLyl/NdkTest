package com.iflytek.ndktest.jni;

import android.util.Log;

/**
 * 文 件 名：TestJni
 * 创 建 人：李跃龙
 * 创建日期：2020/4/16 14:04
 * 邮    箱：ylli10@iflytek.com
 * 功    能：
 * 修 改 人：
 * 修改时间：
 * 修改备注：
 */
public class TestJni {
    public TestJni() {

    }

    public void test() {
        Log.e("ylli10", "test: ");
    }
    public void show(String msg) {
        System.out.println("ylli10: " + msg);
    }

    
    public native String getA();
    
}
