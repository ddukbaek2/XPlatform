// XPlatform.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "XPlatform.h"

using namespace std;

//extern "C" JNIEXPORT jstring JNICALL
//Java_com_example_helloandroid_MainActivity_stringFromJNI(JNIEnv* env, jobject /* this */)
//{
//    std::string hello = "Hello, Android!";
//    __android_log_print(ANDROID_LOG_INFO, "HelloAndroid", "%s", hello.c_str());
//    return env->NewStringUTF(hello.c_str());
//}

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}