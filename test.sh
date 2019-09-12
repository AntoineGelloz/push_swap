#!/bin/bash

printf "\n======== Basic Test ========\n"
printf "1. Expect OK         : " ; printf "" | ./checker 1
printf "2. Expect OK         : " ; printf "" | ./checker -1
printf "3. Expect OK         : " ; printf "" | ./checker 0
printf "4. Expect OK         : " ; printf "sa\n" | ./checker 2 1
printf "5. Expect OK         : " ; printf "" | ./checker 1 2
printf "6. Expect OK         : " ; printf "" | ./checker -1 1
printf "7. Expect OK         : " ; printf "pb\npa\n" | ./checker 1
printf "8. Expect OK         : " ; printf "" | ./checker -2147483648 0 2147483647
printf "9. Expect OK (*)     : " ; printf "" | ./checker 01 002
printf "11.Expect OK (*)     : " ; printf "" | ./checker +1 +02
printf "12.Expect KO         : " ; printf "" | ./checker 2 1
printf "13.Expect KO         : " ; printf "sa\n" | ./checker 1 2
printf "14.Expect KO         : " ; printf "pb\n" | ./checker 1
printf "15.Expect Nothing    : " ; printf "" | ./checker

printf "\n\n======== Error Arg ========\n"
printf "1. Expect Error      : " ; printf "" | ./checker A
printf "2. Expect Error (*)  : " ; printf "" | ./checker -
printf "3. Expect Error      : " ; printf "" | ./checker 0 0
printf "4. Expect Error      : " ; printf "" | ./checker 1 0 1
printf "5. Expect Error      : " ; printf "" | ./checker -1 -1
printf "6. Expect Error      : " ; printf "" | ./checker 2147483648
printf "7. Expect Error      : " ; printf "" | ./checker -2147483649
printf "8. Expect Error      : " ; printf "" | ./checker 100000000000000
printf "9. Expect Error      : " ; printf "" | ./checker 1a
printf "10.Expect Error      : " ; printf "" | ./checker a0
printf "11.Expect Error  (*) : " ; printf "" | ./checker "\01"
printf "12.Expect Error  (*) : " ; printf "" | ./checker "1\01"
printf "13.Expect Error  (*) : " ; printf "" | ./checker "1\0"
printf "14.Expect Error      : " ; printf "" | ./checker 1-
printf "15.Expect Error      : " ; printf "" | ./checker 1+

printf "\n\n======== Error Cmd ========\n"
printf "1. Expect Error      : " ; printf "sas\n" | ./checker 1 2
printf "2. Expect Error      : " ; printf "s\n" | ./checker 1 2
printf "5. Expect Error  (*) : " ; printf "sa\0\n" | ./checker 1 2
printf "6. Expect Error      : " ; printf "sas ls\n" | ./checker 1 2
printf "7. Expect Error      : " ; printf "sas ls\n" | ./checker 1 2
printf "8. Expect Error      : " ; printf "      ss\n" | ./checker 2 1
printf "9. Expect Error      : " ; printf "ss      \n" | ./checker 2 1
printf "10.Expect Error      : " ; printf "      ss      \n" | ./checker 2 1
printf "11.Expect Error      : " ; printf "\tss\n" | ./checker 2 1
printf "12.Expect Error      : " ; printf "ss \n" | ./checker 2 1
printf "13.Expect Error      : " ; printf "rra" | ./checker 2 1
printf "14.Expect Error      : " ; printf "rra\nrra" | ./checker 1 2
printf "15.Expect Error      : " ; printf "sa\nrra" | ./checker 1 2
printf "16.Expect Error      : " ; printf "ra\nrra" | ./checker 1 2
printf "17.Expect Error      : " ; printf "sa\nrra\nls\n" | ./checker 1 2
printf "18.Expect Error      : " ; printf "\n" | ./checker 1 2
printf "19.Expect Error      : " ; printf "ss\nls\n" | ./checker 2 1

printf "\n\n======== Useless Cmd ======\n"
printf "1. Expect OK         : " ; printf "pa\nsb\nsa\nss\nra\nrb\nrr\nrra\nrrb\nrrr\n" | ./checker 1
printf "2. Expect OK         : " ; printf "pb\nsb\nsa\nss\nra\nrb\nrr\nrra\nrrb\nrrr\npa\n" | ./checker 1 2
printf "3. Expect OK         : " ; printf "pb\npb\npa\npa\npa\npa\npa\npa\n" | ./checker 1 2
printf "\n"

echo -e '\033[0mTesting validity a Hundred Times in a range from 0 to 4'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi


echo -e '\033[0mTesting length a Hundred Times in a range from 0 to 4 '
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..4).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l`
		if [ $RET -gt 12 ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi


echo -e '\033[0mTesting a Hundred Times in a range from -50 to 49'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi


echo -e '\033[0mTesting a Hundred Times in a range from -99 to 0'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (-99..0).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi

echo -e '\033[0mTesting a Hundred Times in a range from 0 to 99'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi


echo -e '\033[0mTesting a Hundred Times in a range from 0 to 499'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ];
			then
			((ERR++))
			echo -en '\033[0;31m▓\033[0;0m'
		else
			echo -en '\033[0;32m▓\033[0;0m'
		fi
done

if [ $ERR -eq 0 ];
	then
	echo -e '\033[0;32m Success'
else
	echo -e "\033[0;31m Fail $ERR / 100"
fi

if [ -e "./res" ]
	then
	echo "\033[0merasing res file"
	rm res
fi

echo -e '\033[0mGetting an average in a range from 0 to 99'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res

rm res
echo -e '\033[0mGetting an average in a range from 0 to 499'
ERR=0
for i in range {1..99}
	do 
		ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | wc -l >> res`
done

./tester res
rm res
