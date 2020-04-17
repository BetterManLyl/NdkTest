#include <jni.h>
#include <string>
//导入People.h文件
#include <people.h>
#include <android/log.h>

#define TAG "native-lib" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

extern "C" JNIEXPORT jstring JNICALL
Java_com_iflytek_ndktest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    people people;
    return env->NewStringUTF(people.getString().c_str());
}
//
extern "C"
JNIEXPORT jstring JNICALL
Java_com_iflytek_ndktest_MainActivity_getA(JNIEnv *env, jobject thiz) {
    // TODO: implement getA()
    LOGE("version:%d", env->GetVersion());
  

    return env->NewStringUTF("111");
}