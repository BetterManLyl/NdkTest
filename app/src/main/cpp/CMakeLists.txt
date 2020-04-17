# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

#指定cmake的最小版本
cmake_minimum_required(VERSION 3.4.1)
project(NdkTest)
#设置生成的so文件路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../../jniLibs/${ANDROID_ABI})

message(${PROJECT_SOURCE_DIR}/../../jniLibs/${ANDROID_ABI})

IF (TRUE)
    message("this is true")
ENDIF ()

set(var hello)
#打印信息 测试
message(${var})
set(var 111)
message(${var})
include_directories(include)

aux_source_directory(. SRC_LIST) # 搜索当前目录下的所有.cpp文件
message(${SRC_LIST})

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

#将native-lib.cpp编译成动态库
add_library( # Sets the name of the library.
        #第一个参数是库的名字，例如取名为 native-lib，将会生成一个命名为 libnative-lib.so 的库。
        #可随便取名，不一定要跟.cpp名称一致。不过为了保持一致，最好跟.cpp文件名一致
        native-lib

        #SHARED即动态库（以 .so 为后缀），还有一种是静态库 STATIC，即静态库（以 .a 为后缀）。
        # Sets the library as a shared library.
        SHARED

        #指定该库使用的源文件路径。
        # Provides a relative path to your source file(s).
        native-lib.cpp)

add_library(
        people-lib
        SHARED
        include/people.cpp
)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
#查找到指定的预编译库，并将它的路径存储在变量中。
find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        #这里链接的是生成的动态库的名称，不是.cpp文件的名称
        native-lib
        people-lib
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})

#每个so库使用log的时候，都需要进行关联
target_link_libraries( # Specifies the target library.
        #这里链接的是生成的动态库的名称，不是.cpp文件的名称
        people-lib
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})