all: drivers/hid/hid-multitouch.ko

drivers/hid/hid-multitouch.ko: drivers/hid/hid-multitouch.c
	/bin/bash compile.sh

clean:
	/bin/bash compile.sh clean

install: drivers/hid/hid-multitouch.ko
	/bin/bash install.sh

uninstall:
	/bin/bash restore.sh

