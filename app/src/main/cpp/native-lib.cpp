#include <jni.h>
#include <string>
//导入People.h文件
#include <people.h>

extern "C" JNIEXPORT jstring JNICALL
Java_com_iflytek_ndktest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    people people;
    return env->NewStringUTF(people.getString().c_str());
}
