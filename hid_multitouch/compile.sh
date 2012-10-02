#!/bin/bash

WORKING_DIR=$(pwd)

cd /usr/src/linux-headers-`uname -r`
make M=$WORKING_DIR/drivers/hid $@
