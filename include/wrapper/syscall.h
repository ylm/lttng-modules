/* SPDX-License-Identifier: (GPL-2.0-only or LGPL-2.1-only)
 *
 * wrapper/syscall.h
 *
 * wrapper around asm/syscall.h.
 *
 * Copyright (C) 2019 Michael Jeanson <mjeanson@efficios.com>
 */

#ifndef _LTTNG_WRAPPER_SYSCALL_H
#define _LTTNG_WRAPPER_SYSCALL_H

#include <asm/syscall.h>
#include <lttng/kernel-version.h>

#define LTTNG_SYSCALL_NR_ARGS 6

#if (LTTNG_LINUX_VERSION_CODE >= LTTNG_KERNEL_VERSION(5,1,0))

#define lttng_syscall_get_arguments(task, regs, args) \
	syscall_get_arguments(task, regs, args)

#else /* LTTNG_LINUX_VERSION_CODE >= LTTNG_KERNEL_VERSION(5,1,0) */

static inline
void lttng_syscall_get_arguments(struct task_struct *task,
		struct pt_regs *regs, unsigned long *args)
{
	syscall_get_arguments(task, regs, 0, LTTNG_SYSCALL_NR_ARGS, args);
}

#endif /* LTTNG_LINUX_VERSION_CODE >= LTTNG_KERNEL_VERSION(5,1,0) */

#endif /* _LTTNG_WRAPPER_SYSCALL_H */
