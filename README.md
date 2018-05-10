# 2048inC
Programming the game 2048 in purely C

To compile and run my code follow the following instructions:

Download Dependencies:

	sudo apt-get install gcc libgl1-mesa-dev libglu1-mesa-dev cmake build-essential make libxcursor-dev
	sudo apt-get install cmake g++ freeglut3-dev libxcursor-dev libpng12-dev libjpeg-dev libfreetype6-dev libgtk2.0-dev libasound2-dev libpulse-dev libopenal-dev libflac-dev libdumb1-dev libvorbis-dev libphysfs-dev

make a directory for the Library
	mkdir $HOME/Allegro-Git; cd $HOME/Allegro-Git

clone library from github and prep it

	git clone git://git.code.sf.net/p/alleg/allegro
	cd allegro
	git checkout 5.0
	mkdir build; cd build
	cmake -DCMAKE_INSTALL_PREFIX=/usr ..
	make
	sudo make install

then naviagate to the folder with my code and run make.
------------------------------------------------------------------------------------------------------------------------------------------
Game Description:

if you run ./Rami_2048 -n it will launch the game with colors and number the -c option runs
it with just colors.
------------------------------------------------------
The purpose of the game is to combine blocks to make the 2048 block. Everytime you
hit an arrow key all the blocks move to the side of the 4x4 grid. If two blocks are the same
in the direction that you pressed the arrow key they combine to make a new block and so on.

May the blocks be ever in your favour.

Thanks,
your favorite coder Ramallamadingdong
