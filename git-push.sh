 #!/bin/bash
echo "Are you sure, you wanna commit all the changes? (Y, N)"
read yes
if [ $yes = "Y" ] || [$yes == "y"]; then
    echo "STAGGING FILES..."
    git add .
    echo "Type the commit message: "
    read message
    git commit -m "$message"
    echo "Pushing to branch master"
    git push origin master
    echo "We are done"
else
    echo "Fuck you!!"
fi
