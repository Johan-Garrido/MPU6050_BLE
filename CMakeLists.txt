# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
set(DTC_OVERLAY_FILE "nrf52dk_nrf52832.overlay")
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(mpu6250_sample)

zephyr_library_sources_ifdef(CONFIG_MPU6050 mpu6050.c)
zephyr_library_sources_ifdef(CONFIG_MPU6050_TRIGGER mpu6050_trigger.c)
FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE src/main.c
    src/I2C.c
    src/bluetooth.c)