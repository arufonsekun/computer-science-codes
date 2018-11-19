#!/bin/bash
echo "Digite um numero"
read i

if [ $i -eq 0 ]
then
    echo "Zero"
elif [ $i -lt 5 ]
then
    echo "Menor que cinco"
else
    echo "Maior que cinco"
fi

case $i in "0" )
    echo "Zero"
    ;;
"1")
    echo "Cu"
esac

for i in {10..0}
do
    echo $i
done

