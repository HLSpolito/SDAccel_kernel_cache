// Copyright 2014, Xilinx Inc.
// All rights reserved.

#ifndef _OCL_HELP_H_
#define _OCL_HELP_H_

#include <CL/cl.h>

struct oclHardware {
    cl_platform_id mPlatform;
    cl_context mContext;
    cl_device_id mDevice;
    cl_command_queue mQueue;
    short mMajorVersion;
    short mMinorVersion;
};

struct oclSoftware {
    cl_program mProgram;
    cl_kernel mKernel;
    char mKernelName[128];
    char mFileName[1024];
    char mCompileOptions[1024];
};

oclHardware getOclHardware(cl_device_type type, const char *target_device);

int getOclSoftware(oclSoftware &software, const oclHardware &hardware);

void release(oclSoftware& software);

void release(oclHardware& hardware);

const char *oclErrorCode(cl_int code);

#endif

// XSIP watermark, do not delete 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
