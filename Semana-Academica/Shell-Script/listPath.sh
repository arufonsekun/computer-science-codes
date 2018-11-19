#!/bin/bash
#ps -e lista processor

for i in $@
do
    echo $i
done

sum(){
    i=$(($1+$2))
    echo $i
}
sum 2 3
