# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    debug.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulopez <aulopez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 13:36:20 by aulopez           #+#    #+#              #
#    Updated: 2019/07/17 17:51:58 by aulopez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
printf "3. Expect Error      : " ; printf "\0\n" | ./checker 1 2
printf "4. Expect Error      : " ; printf "\0sa\n" | ./checker 1 2
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

printf "\n\n======= Args Space ========\n"
printf "In my opinion, this is a bonus.\n"
printf "1. Expect Nothing/Err: " ; ./checker ""
printf "2. Expect Nothing/Err: " ; ./checker "        "
printf "3. Expect OK/Err     : " ; ./checker "" 1
printf "4. Expect OK/Err     : " ; ./checker "        " 1
printf "5. Expect OK/Err     : " ; ./checker 1 ""
printf "6. Expect OK/Err     : " ; ./checker 1 "        "
printf "7. Expect OK         : " ; printf "" | ./checker "1       "
printf "8. Expect OK         : " ; printf "" | ./checker "       1"
printf "9. Expect OK         : " ; printf "" | ./checker "       1      "
printf "10.Expect OK         : " ; printf "sa\n" | ./checker "2 1" 22
printf "11.Expect OK         : " ; printf "sa\n" | ./checker "2 "1 22
printf "12.Expect OK         : " ; printf "sa\n" | ./checker 2 " 1" 22
printf "13.Expect OK         : " ; printf "ra\n" | ./checker 2"1" 3 4
printf "14.Expect OK         : " ; printf "ra\n" | ./checker "1"2 3 4
printf "15.Expect OK         : " ; printf "sa\n" | ./checker 2" 1" 22
printf "16.Expect OK         : " ; printf "sa\n" | ./checker "2 "1 22
printf "17.Expect OK         : " ; printf "ra\n" | ./checker 1"2  " 3 4
printf "18.Expect OK         : " ; printf "ra\n" | ./checker "   1"2 3 4
printf "19.Expect OK         : " ; printf "sa\n" | ./checker 1"     "
printf "20.Expect OK         : " ; printf "" | ./checker "      "1
printf "21.Expect OK         : " ; printf "" | ./checker ""1
printf "22.Expect OK         : " ; printf "" | ./checker 1""
