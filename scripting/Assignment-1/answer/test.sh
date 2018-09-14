#!/bin/bash
RED='\033[0;31m'
NC='\033[0m'
function move(){
echo '\033\[10;10H'
#echo $1
}

#while((1));
#do

#echo "                ";
#echo ""

#done
move 10 10
echo '\033[50D\033[30C My Text Goes Here'
printf "I ${RED}love${NC} Stack Overflow\n"
