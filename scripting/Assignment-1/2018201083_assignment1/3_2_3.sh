awk '{

if(NR>1)
{
  x=$3 + $4 + $5
  
  printf("%s %d\n",$1,x);

}

}' marks.txt
