 #!/bin/bash
echo "Are you sure, you wanna push? (Y, N)"
read yes
if [ $yes = "Y" ]; then
    git add .
    echo "Type the commit message"
    read message
    git commit -m "$message"
    git push
else
    echo "Fuck you"
fi
