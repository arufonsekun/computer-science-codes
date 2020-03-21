echo "Type.."
read i

while [ $i != -1 ]
do
    echo $i
    echo "Type.."
    read i
done

i=0
while [ $i -le 10 ]
do
    echo $i
    i= $(($i+1))
done

##Maths
#i = 8
#i = $(bc <<< $i + 1)
