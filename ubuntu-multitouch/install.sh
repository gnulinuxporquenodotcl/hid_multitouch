#!/bin/bash

if [[ `id -u` != 0 ]]
then
  echo "Must be run as root"
  exit 1
fi

WORKING_DIR=$(pwd)

INSTALL_PATH=/lib/modules/`uname -r`/kernel/drivers/hid

# check if the modules are compiled
if [[ ! -e $WORKING_DIR/drivers/hid/hid.ko ||
      ! -e $WORKING_DIR/drivers/hid/hid-multitouch.ko ||
      ! -e $WORKING_DIR/drivers/hid/usbhid/usbhid.ko ]]
then
  echo "please run make before install."
  echo "Aborting"
  exit 1
fi

# check if using the original hid.ko
HID_PATH_MODINFO=$(modinfo hid | grep filename | awk '{ print $2 }')
if [[ "$HID_PATH_MODINFO" != "$INSTALL_PATH/hid.ko" ]]
then
  echo "ERROR: non standard hid detected, please remove any hid-dkms stuff before using hid-multitouch, or wait for an official support."
  echo "Aborting"
  exit 1
fi


MODULES=$(lsmod | grep ^hid | awk '{ print $4 }')
MODULES=${MODULES//,/ }
MODULES="$MODULES hid"

REV_MODULES=""
REV_MODULES="hid-multitouch"

for i in $MODULES
do
  echo "rmmod $i"
  rmmod $i
  if [[ x"$i" != x"hid_multitouch" &&
    x"$i" != x"hid_cando" &&
    x"$i" != x"hid_3m_pct" &&
    x"$i" != x"hid_mosart" &&
    x"$i" != x"hid_quanta" &&
    x"$i" != x"hid_stantum" &&
    x"$i" != x"usbhid" &&
    x"$i" != x"hid" ]]
  then
    REV_MODULES="${i/_/-} $REV_MODULES"
  fi
done
REV_MODULES="$REV_MODULES"

echo "insmod $WORKING_DIR/drivers/hid/hid.ko"
insmod $WORKING_DIR/drivers/hid/hid.ko
echo "insmod $WORKING_DIR/drivers/hid/usbhid/usbhid.ko"
insmod $WORKING_DIR/drivers/hid/usbhid/usbhid.ko

# test if the modules are the new ones
CRC_LOCAL_HID=$(modinfo $WORKING_DIR/drivers/hid/hid.ko | grep srcversion | awk -F": *" '{print $2}')
CRC_HID=$(cat /sys/module/hid/srcversion)

if [[ $CRC_LOCAL_HID != $CRC_HID ]]
then
  echo "******************** WARNING ********************"
  echo "***** I was not able to load the new drivers ****"
  echo "*** you will have to reboot to see the changes **"
  echo "*************************************************"
fi


for i in $REV_MODULES
do
  echo "insmod $WORKING_DIR/drivers/hid/$i.ko"
  insmod $WORKING_DIR/drivers/hid/$i.ko
done

INSTALL="N"

# check if hid_multitouch has been loaded
if [[ ! -e /sys/module/hid_multitouch ]]
then
  read -p "hid_multitouch is not loaded are you sure do you want to continue? [y/N]" answer
  case $answer in
    y) INSTALL="Y";;
    Y) INSTALL="Y";;
    *) ;;
  esac
else
  echo "hid_multitouch successfully loaded, please test it before continuing"
  read -p "Do you want to continue? [y/N]" answer
  case $answer in
    y) INSTALL="Y";;
    Y) INSTALL="Y";;
    *) ;;
  esac
fi

if [[ x"$INSTALL" == x"N" ]]
then
	echo "aborting"
	exit 1
fi

# backup shipped modules
cd $INSTALL_PATH
for i in *.ko usbhid/*.ko
do
  if [[ ! -e $i.orig && x"$i" != x"hid-multitouch.ko" ]]
  then
    mv $i $i.orig
  fi
done

cd $WORKING_DIR/drivers/hid
for i in *.ko usbhid/*.ko
do
  echo $i "->" ${INSTALL_PATH}/$i
  cp $i ${INSTALL_PATH}/$i
done

echo "depmod -a"
depmod -a

echo "update-initramfs -u"
update-initramfs -u

cd $WORKING_DIR

if [[ ! -e /lib/udev/rules.d/41-hid-multitouch.rules ]]
then
  echo "install -m644 -C 41-hid-multitouch.rules /lib/udev/rules.d/"
  install -m644 -C 41-hid-multitouch.rules /lib/udev/rules.d/
  echo "reload udev"
  reload udev
fi

if [[ ! -e /lib/udev/load_hid_multitouch.sh ]]
then
  echo "install -m644 -C load_hid_multitouch.sh /lib/udev/"
  install -m744 -C load_hid_multitouch.sh /lib/udev/
fi




