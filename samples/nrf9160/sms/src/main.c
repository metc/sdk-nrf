/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <zephyr.h>
#include <stdio.h>
#include <uart.h>
#include <string.h>

/* SMS subscriber module. */
#include <sms.h>

/**@brief Recoverable BSD library error. */
void bsd_recoverable_error_handler(uint32_t err)
{
	printk("bsdlib recoverable error: %u\n", err);
}

/** @brief Configures modem to provide LTE link. */
static void modem_configure(void)
{
#if defined(CONFIG_LTE_LINK_CONTROL)
	BUILD_ASSERT_MSG(IS_ENABLED(CONFIG_LTE_AUTO_INIT_AND_CONNECT),
			"LTE init and connect need to be enabled");

	// int err = at_notif_init();
	// __ASSERT(err == 0, "AT Notify could not be initialized.");
	// err = at_cmd_init();
	// __ASSERT(err == 0, "AT CMD could not be established.");
	// printk("LTE Link Connecting ...\n");
	// err = lte_lc_init_and_connect();
	// __ASSERT(err == 0, "LTE link could not be established.");
	// printk("LTE Link Connected!\n");
#endif
}

void sms_handler(struct sms_data *const data, void *context)
{
	printk("SMS data\n");
	printk("Data: %d\n", data->length);
}

int context = 42;

void main(void)
{
	printk("SMS sample started\n");

	/* LTE link is established automatically. */
	modem_configure();

	int ret = sms_init();
	if (ret) {
		printk("Unable to register SMS client: %d\n", ret);
		return;
	}

	bool registered = sms_register_listener(sms_handler, &context);

	(void)registered;
	(void)ret;

//	while(true) {
//		k_sleep(1);
//	}
}
