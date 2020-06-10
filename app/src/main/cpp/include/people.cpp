//
// Created by ylli10 on 2020/4/16.
//
#include <jni.h>
#include <string>
//导入People.h文件
#include <people.h>
#include <android/log.h>

#define TAG "people-lib" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

std::string people::getString() {
    return "this is people";
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_iflytek_ndktest_jni_TestJni_getA(JNIEnv *env, jobject thiz) {
    // TODO: implement getA()
    LOGD("success");

    
    jclass jclass1 = env->GetObjectClass(thiz);
    jmethodID jmethodId = env->GetMethodID(jclass1, "test", "()V");
    jmethodID jmethodId1 = env->GetMethodID(jclass1, "show", "(Ljava/lang/String;)V");
    LOGD("success 2");
    env->CallVoidMethod(thiz, jmethodId);
    //注意这里，java中的String类型，在这里要重新定义
    jstring charst = env->NewStringUTF("hello");
    
    env->CallVoidMethod(thiz, jmethodId1, charst);
    //手动回收
    env->DeleteLocalRef(jclass1);
    LOGD("success 3");
    return env->NewStringUTF("123");
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGI("enter JNI_OnLoad");

    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    return JNI_VERSION_1_4;
}

void JNI_OnUnload(JavaVM *vm, void *reserved) {
    LOGI("enter JNI_OnUnload");
}

