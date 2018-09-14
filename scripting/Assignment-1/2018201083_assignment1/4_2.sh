#!/bin/bash

pass=$1
flag=1
flag1=1
flag3=1
len=${#pass}
if((len>8)); then
   echo "$pass" | grep -q "[@#$%&+-=]"
   if(($?!=0)); then
    let flag1=0 
    echo -e "password must contain atleast one special character\n"
   fi
   echo "$pass" | grep -q "[0-9]"
   
   if(($?!=0)); then
    let flag=0 
    echo -e "password must contain atleast one digit\n"
   fi
fi

if((len<8)); then
let flag3=0
echo -e "length must be min 8 char\n";
fi
if(($flag==1&&$flag1==1&&$flag3==1)); then
     echo -e "Password set\n"
   fi

#echo

