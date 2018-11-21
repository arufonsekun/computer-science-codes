#!/bin/bash

if [ ! -d log ]
then
    mkdir log
fi

process(){
    proc=$(ps -e -o pid --sort -size | head -n 11 | grep [a-z])
    for pid in $proc
    do
        nome=$(ps -p $pid -o comm=)
        echo -n $(date +%F' 'H=%H' 'M=%M' 'S=%S) >> log/$nome.log
        tamanho=$(ps -p pid -o size | grep [0-9])
        echo "$(bc <<< "scale=2;$tamanho/1024") MB" >> log/$nome.log

    done
}
process

if [ $? -eq 0 ]#verifica se nao deu erro
then
    echo "Salvou de boa"
else
    echo "Deu pau"
fi
