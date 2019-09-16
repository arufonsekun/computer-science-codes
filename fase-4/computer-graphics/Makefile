
install:
	sudo apt install build-essential cmake xorg-dev libglu1-mesa-dev libglfw3 libglfw3-dev freeglut3 freeglut3-dev libglew-dev mesa-utils mesa-common-dev
compile:
	g++ -g -Wall -Wno-deprecated $(filter-out $@,$(MAKECMDGOALS)) -lglfw -lGL -lm -lX11 -lglut -lGLU -ldl