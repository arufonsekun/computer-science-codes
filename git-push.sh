 #!/bin/bash
echo "Are you sure, you wanna push? (Y, N)"
read yes
if [ $yes = "Y" ]; then
    echo "STAGGING FILES"
    git add .
    echo "Type the commit message: "
    read message
    git commit -m "$message"
    echo "PUSHING TO MASTER"
    git push origin master
else
    echo "Fuck you!!"
fi
