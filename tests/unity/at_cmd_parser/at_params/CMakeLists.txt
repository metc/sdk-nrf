#
# Copyright (c) 2019 Nordic Semiconductor
#
# SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
#

cmake_minimum_required(VERSION 3.13.1)
include($ENV{ZEPHYR_BASE}/cmake/app/boilerplate.cmake NO_POLICY_SCOPE)
project(test_at_params)

# generate runner for the test
test_runner_generate(src/at_params_test.c)

# create mock for mempool module
# cmock_handle(${ZEPHYR_BASE}/include/misc/mempool.h mempool)
cmock_handle(${ZEPHYR_BASE}/include/kernel.h kernel)

# add test file
target_sources(app PRIVATE src/at_params_test.c)
target_include_directories(app PRIVATE .)
