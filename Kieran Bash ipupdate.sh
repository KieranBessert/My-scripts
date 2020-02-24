#1/bin/bash

ifconfig > /home/kabessert1994/Scripts/ifconfig.txt
ip add show|grep inet|awk '{print $2}'


MYIP=`ip add show|grep inet|awk 'NR==3{print $2}'`

HOSTIP=`grep myserver /etc/hosts|awk '{print $1}'`

if [ $MYIP = $HOSTIP ]; then
	echo "nothing to change">/home/kabessert1994/Scripts/ifconfig.txt
else
	sed -i.log s/$HOSTIP/$MYIP/ /etc/hosts
fi
