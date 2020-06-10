#include <jni.h>
#include <people.h>
#include <stdio.h>
#include <stdlib.h>
#include <android/log.h>

using namespace std;

#ifdef __cplusplus
extern "C" {
#endif

static const char *className = "com/iflytek/ndktest/jni/TestDynamic";

static jstring sayHello(JNIEnv *env, jobject, jlong handle) {
    LOGI("native: say hello ###");
    return env->NewStringUTF("123");
}

static JNINativeMethod gJni_Methods_table[] = {
        {"sayHello", "()Ljava/lang/String;", (void *) sayHello},
};

static int jniRegisterNativeMethods(JNIEnv *env, const char *className,
                                    const JNINativeMethod *gMethods, int numMethods) {
    jclass clazz;

    LOGI("Registering %s natives\n", className);
    clazz = (env)->FindClass(className);
    if (clazz == NULL) {
        LOGE("JNI", "Native registration unable to find class '%s'\n", className);
        return -1;
    }

    int result = 0;
    if ((env)->RegisterNatives(clazz, gJni_Methods_table, numMethods) < 0) {
        LOGE("JNI", "RegisterNatives failed for '%s'\n", className);
        result = -1;
    }

    (env)->DeleteLocalRef(clazz);
    return result;
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGI("enter jni_onload");

    JNIEnv *env = NULL;
    jint result = -1;

    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return result;
    }

    jniRegisterNativeMethods(env, className, gJni_Methods_table,
                             sizeof(gJni_Methods_table) / sizeof(JNINativeMethod));

    return JNI_VERSION_1_4;
}

#ifdef __cplusplus
}
#endif