#!/bin/sh

#Mark Davis   mjd85
#project 2, CS232
#Shell Scripting

filename='computers.txt' #file to store machine names
filelines=`cat $filename` #read out the lines
shutdown="No route to host" #substring to verify if machine is turned off
windows="Connection timed out" #substring to verify if machine is running windows

for line in $filelines ; do #loop through file containing machine names
	echo #whitespace
	echo #whitespace
	echo $line #output the machine name

	output=$(ssh -o StrictHostKeyChecking=no -o ConnectTimeout=5 $line "users && exit") 2> sshError.txt #ssh the machine and put error messages in txt file
	read error < sshError.txt #read error messages to a variable

	if echo "$error" | grep -q "$shutdown" #if the 'No route to host' message is in the error messaage,
	then
		echo "Machine is turned OFF" #then the computer is turned off
	else
		echo "Machine is turned ON" #else the machine is turned on, 
		if echo "$error" | grep -q "$windows" #if the 'Connection timed out' message is in the error message
		then
			echo "Machine is running WINDOWS" #output if it is in windows
		else
			echo "Machine is running GNU/LINUX" #else, output GNU/Linux
			if [ -z "$output" -a -z "$error" ]; then #if the error message is empty and the output is empty,
				echo "No users logged on" #there are no users logged on
		    else
				echo "User is logged on" #else there are users logged on
			fi
		fi
	fi

done



