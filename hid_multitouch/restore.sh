#!/bin/bash

if [[ `id -u` != 0 ]]
then
  echo "Must be run as root"
  exit 1
fi

WORKING_DIR=$(pwd)

INSTALL_PATH=/lib/modules/`uname -r`/kernel/drivers/hid

cd $INSTALL_PATH
for i in *.ko usbhid/*.ko
do
  rm $i
  if [[ ! -e $i.orig ]]
  then
    mv $i.orig $i
  fi
done


echo "depmod -a"
depmod -a

echo "update-initramfs -u"
update-initramfs -u

