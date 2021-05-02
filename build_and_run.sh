clear
rm -rf build

source venv/bin/activate

export OMP_STACKSIZE=1G

mkdir build
cd build

cmake ../
make CC="time g++"

FILE=./radium
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

if [ -f "$FILE" ]; then

    clear
    time ./radium
    cd ../

    DIRECTORY=./dump
    if [ -d "$DIRECTORY" ]; then
        rm -rf ./dump/*
    else
        mkdir ./dump
    fi

    if compgen -G "./build/*.ppm" > /dev/null; then
      mv ./build/*.ppm ./dump
    else
      printf "\n${RED}Image not Found\n"
    fi

    if compgen -G "./build/*world.csv" > /dev/null; then
      mv ./build/*world.csv ./scenes/worlds
    else
      printf "${RED}World File not Found\n"
    fi

    if compgen -G "./build/*camera.csv" > /dev/null; then
      mv ./build/*camera.csv ./scenes/cameras
    else
      printf "${RED}Camera File not Found\n"
    fi

    printf "\n\n\n${GREEN}Compilation Successful!!!\n"
    python3 plot_image.py

else
    printf "\n\n\n${RED}Compilation Failure!!!\n"
fi

deactivate