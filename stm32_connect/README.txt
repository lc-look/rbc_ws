$ls -l /dev/ttyUSB* #检查是否连接
crw-rw---- 1 root dialout 188, 0 Aug  3 21:46 /dev/ttyUSB0 #如果出现这个说明被成功连接
#设置权限
$sudo chmod 777 /dev/ttyUSB0 #按照自己的设备名字对ttyUSB0进行更改

