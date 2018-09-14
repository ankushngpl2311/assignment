ifconfig -a | grep -io "hwaddr.*"|grep -Eo "([0-9A-Fa-f]{2}-){5}[0-9A-Fa-f]{2}|([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}"

