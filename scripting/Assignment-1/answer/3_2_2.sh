awk '{
if($2=="M") 
{ 
  print $0 >> "males.txt" 
   
}  

if($2=="F")
{
  print $0 >> "females.txt"
 

}
  
 }' marks.txt
