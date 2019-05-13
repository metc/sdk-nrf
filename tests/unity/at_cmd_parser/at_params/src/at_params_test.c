/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#include <unity.h>
#include <at_params.h>
#include <errno.h>

//#include "mempool/mock_mempool.h"
//#include "kernel/mock_kernel.h"

void setUp(void)
{
	/* Empty. */
}

void test_at_params_list_init_null_param(void)
{
	int err = at_params_list_init(NULL, 0);
	TEST_ASSERT_EQUAL(-EINVAL, err);
}

void test_at_params_list_init_no_mem(void)
{
	/* TODO: */
}

/* void test_at_params_list_init(void)
{
	const size_t MAX_PARAMS = 4;

	// Null memory
	// __wrap_k_calloc_ExpectAndReturn(MAX_PARAMS, sizeof(struct at_param), NULL);

	struct at_param_list list;
	int err = at_params_list_init(&list, MAX_PARAMS);
	TEST_ASSERT_EQUAL(0, err);
} */
