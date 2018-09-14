awk 'BEGIN{x= $0
  print x} 
{
  if(x==$0)
  {  print NR
    printf("hello\n");
  }
  else
  { print NR
  printf("bye\n");
   }
}'

