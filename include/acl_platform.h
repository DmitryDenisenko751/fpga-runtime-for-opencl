// Copyright (C) 2010-2021 Intel Corporation
// SPDX-License-Identifier: BSD-3-Clause

#ifndef ACL_PLATFORM_H
#define ACL_PLATFORM_H

#include <CL/opencl.h>

#ifdef __GNUC__
#pragma GCC visibility push(protected)
#endif

#if defined(__cplusplus)
extern "C" {
#endif

// ID of the thread that created platform.
// Used to detect if user is doing mulithreading.
extern int platform_owner_tid;

void acl_init_platform(void);
void acl_finalize_init_platform(unsigned int num_devices,
                                const cl_device_id *devices);
const char *acl_platform_extensions(void);
acl_device_op_queue_t *get_device_op_queue(unsigned int physical_device_id);
acl_device_op_queue_t *get_device_op_queue_from_context(cl_context context);

acl_locking_data_t *get_device_op_queue_locking_data(cl_device_id device);
acl_locking_data_t *get_device_op_queue_locking_data_from_context(cl_context context);
acl_locking_data_t *get_device_op_queue_locking_data_from_command_queue(cl_command_queue command_queue);
acl_locking_data_t *get_device_op_queue_locking_data_from_kernel(cl_kernel kernel);

#if defined(__cplusplus)
} /* extern "C" */
#endif

#ifdef __GNUC__
#pragma GCC visibility pop
#endif

#endif
