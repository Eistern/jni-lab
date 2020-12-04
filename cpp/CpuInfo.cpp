#include "nsu_fit_CpuInfo.h"

#include <string>
#include <iostream>

JNIEXPORT jobject JNICALL Java_nsu_fit_CpuInfo_getInstance
        (JNIEnv *java_env, jclass java_class) {
    FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
    char *arg = 0;
    size_t size = 0;

    jint cpu_cores;
    jstring cpu_model;

    while(getdelim(&arg, &size, '\n', cpuinfo) != -1) {
        std::string info_line(arg, size);
        if (info_line.rfind("cpu family") == 0) {
            cpu_cores = std::stoi(info_line.substr(info_line.find(':') + 1));
        }
        if (info_line.rfind("model name") == 0) {
            cpu_model = java_env->NewStringUTF(info_line.substr(info_line.find(':') + 1, info_line.length() - 1).c_str());
        }
    }
    fclose(cpuinfo);

    jmethodID constructor = java_env->GetMethodID(java_class, "<init>", "(ILjava/lang/String;)V");
    return java_env->NewObject(java_class, constructor, cpu_cores, cpu_model);
}