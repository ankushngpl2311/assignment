awk '{if(NR>1){printf("%s %s %s\n",$1,$2,$5)};}' marks.txt
