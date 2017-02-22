#!/bin/sh

filename='computers.txt'
filelines=`cat $filename`
shutdown="No route to host"
windows="Connection timed out"

for line in $filelines ; do
	echo
	echo $line
	output=$(ssh -o StrictHostKeyChecking=no -o ConnectTimeout=5 $line "uname && users && exit")
	echo "$output"

	#case "$shutdown" in
	#	*$output*) echo "Machine turned off" ;;
	#esac

	#case "windows" in
	#	*$output*) echo "Maching is running WINDOWS" ;;
	#esac

	if echo "$output" | grep -q "$shutdown"
	then
		echo "Machine is off"
	fi

	if echo "$output" | grep -q "$windows"
	then
		echo "Machine is running Windows"
	fi

done



