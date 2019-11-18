/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#ifndef SMS_H_
#define SMS_H_

/**
 * @file sms.h
 *
 * @defgroup sms SMS subscriber manager
 *
 * @{
 *
 * @brief Public APIs of the SMS subscriber manager module.
 */

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/types.h>
#include <sys/types.h>

/* Forward declaration. */
struct sms_data;

/**
 * @brief SMS listener callback function.
 * 
 * @param data    Read-only pointer to the SMS data. Cannot be null.
 * @param context Pointer to the user context, if any. Same context used
 *                in the register function.
 */
typedef void (*sms_callback_t)(const struct sms_data *data, void *context);

/**
 * @brief Initialize the SMS subscriber module.
 *
 * @return Zero on success, or a negative error code. The -EBUSY error
 *         indicates that one SMS client has already been registered.
 */
int sms_init(void);

/**
 * @brief Register a new listener.
 *
 * A listener is identified by a unique handle value. This handle should be used
 * to unregister the listener. A listener can be registered multiple times with
 * the same or a different context.
 *
 * @param listener Callback function. Cannot be null.
 * @param context User context. Can be null if not used.
 * @return A unique handle identifying the listener, 
 *         or a negative value if an error occurred.
 * @retval -EINVAL Invalid parameters.
 * @retval -ENOMEM No space to register new listeners.
 */
int sms_register_listener(sms_callback_t listener, void *context);

/**
 * @brief Unregister a listener.
 *
 * @param handle Handle identifying the listener to unregister.
 */
void sms_unregister_listener(int handle);

/**
 * @brief Uninitialize the SMS subscriber module.
 */
void sms_uninit(void);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* SMS_H_ */
