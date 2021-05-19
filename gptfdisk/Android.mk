LOCAL_PATH := $(call my-dir)

sgdisk_src_files := \
    sgdisk.cc \
    gptcl.cc \
    crc32.cc \
    support.cc \
    guid.cc \
    gptpart.cc \
    mbrpart.cc \
    basicmbr.cc \
    mbr.cc \
    gpt.cc \
    bsd.cc \
    parttypes.cc \
    attributes.cc \
    diskio.cc \
    diskio-unix.cc \
    android_popt.cc \

gdisk_src_files := \
     gdisk.cc \
	 gpttext.cc \
	 crc32.cc \
	 support.cc \
	 guid.cc \
	 gptpart.cc \
     mbrpart.cc \
	 basicmbr.cc \
     mbr.cc \
     gpt.cc \
     bsd.cc \
	 parttypes.cc \
	 attributes.cc \
	 diskio.cc \
	 diskio-unix.cc \
	 android_popt.cc \


include $(CLEAR_VARS)

LOCAL_CPP_EXTENSION := .cc

LOCAL_C_INCLUDES := $(LOCAL_PATH) external/e2fsprogs/lib
LOCAL_SRC_FILES := $(gdisk_src_files)
LOCAL_CFLAGS += -Wno-unused-parameter -Wno-pragma-pack -Werror
LOCAL_MODULE_TAGS := debug
LOCAL_SHARED_LIBRARIES := libext2_uuid

#LOCAL_MODULE := sgdisk
LOCAL_MODULE := gdisk
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)

LOCAL_CPP_EXTENSION := .cc

ifeq ($(HOST_OS),darwin)
LOCAL_CFLAGS := -D_FILE_OFFSET_BITS=64 -Doff64_t=off_t
endif

LOCAL_C_INCLUDES := $(LOCAL_PATH) external/e2fsprogs/lib
LOCAL_SRC_FILES := $(gdisk_src_files)
LOCAL_CFLAGS += -Wno-unused-parameter -Wno-pragma-pack -Werror

LOCAL_SHARED_LIBRARIES := libext2_uuid

LOCAL_MODULE := gdisk_host
LOCAL_MODULE_STEM := gdisk

include $(BUILD_HOST_EXECUTABLE)
