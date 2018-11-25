gcc -c BST.c
gcc -c treeMain.c
gcc -o run BST.o treeMain.o
./run < input
