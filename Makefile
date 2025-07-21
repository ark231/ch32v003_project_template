PROJECT_DIR:= $(dir $(lastword $(MAKEFILE_LIST)))

all : flash

CH32V003FUN:= ${PROJECT_DIR}/external/ch32fun/ch32fun
TARGET:=Template
TARGET_MCU?=CH32V003
# CH32V003_lib_i2c:=${HOME}/.local/include/CH32V003_lib_i2c
# ch32v003_lib_sensors:=${HOME}/projects/ch32v003/libs/ch32v003_lib_sensors/

EXTRA_CFLAGS+=-std=gnu23

#libraries
# include ${CH32V003_lib_i2c}/CH32V003_lib_i2c.mk
# include ${ch32v003_lib_sensors}/ch32v003_lib_sensors.mk

include ${CH32V003FUN}/ch32fun.mk

flash : cv_flash
clean : cv_clean


