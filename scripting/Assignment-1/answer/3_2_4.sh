awk '

BEGIN{max=0; sum=0; }

{
  if(NR>1)
 { x= $3+$4+$5;
  sum=sum +x;
  if(x>max)
  {
    max=x;
    name= $1;
  }
 }
  
 
}
END{ 
avg= sum/(NR-1);

print avg;
print name;
  

}
' marks.txt
