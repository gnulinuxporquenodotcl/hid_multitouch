#!/bin/env python
import os
import sys
import re
# First commit
# first, check the user id
if int(os.popen("id -u").read()) != 0:
	print "Must be run with root privileges"
	sys.exit(1)



os.chdir("/sys/bus/usb/drivers/usbhid")

USB_PATH = []
USB = []

for file in os.listdir("."):
	m = re.match(r".*\:.*", file)
	if not m:
		continue
	# we now have only the links to the devices

	uevent = ""
	name = ""
	usb = ""
	# find the name and path of the device
	for subfile in os.listdir(file):
		m = re.match(r"\d*\:.*", subfile)
		if not m:
			continue
		uevent = file + "/" + subfile + "/uevent"

	uevent_f = open(uevent,'r')
	for l in uevent_f:
		m = re.match(r"(HID_ID|HID_NAME)=(.*)",l)
		if m:
			var, value = m.groups()
			if var == "HID_NAME":
				name = value
			elif var == "HID_ID":
				usb = ":".join(value.split(":")[1:])

	if usb not in USB:
		print "found device", name
		USB.append(usb)

	USB_PATH.append(file)
	cmd = "echo " + file + " > unbind"
	print cmd
	os.popen(cmd)

for usb in USB:
	cmd = "lsusb -v -d " + usb
	print cmd
	print os.popen(cmd).read()

for file in USB_PATH:
	cmd = "echo " + file + " > bind"
	print cmd
	os.popen(cmd)
