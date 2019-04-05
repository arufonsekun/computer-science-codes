import subprocess
import random
import sys

def subprocess_cmd(command):
    process = subprocess.Popen(command,stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)
    proc_stdout = process.communicate()[0].strip()


vetA=["'aaaaa'","'aa'","'AbabAbabab'","'casa'", "casa","fasdfdasfasfsafewajwejfwelfjsdlkfjsalkfsa","SSss", "AA","'casa casa'","asdffwewAEDFDSADA","eeeeeeeEEEEE","ewrwsffdes","42423sfsf"]
vetB=[1,2,3,4]

count=0;
count2=2;
for i in "abcdefghijlmn":
    filenameA="p5-"+i+".in"
    f1=  open(filenameA, "w")
    f1.write(vetA[count])
    filenameB="p5-"+i+".sol"
    f2=  open(filenameB, "w")

    try:
        subprocess_cmd("./a.out"+ " " + vetA[count] +" "+ str(vetB[count2]) +" > "+filenameB)
    except :
        e = sys.exc_info()[0]
        print( "<p>Error: %s</p>" % e )
    count+=1






    f1.close()
    f2.close()
    #cost = random.randint(1, b)
    #p = random.randint(cost, c)
    #print(cost, p)
