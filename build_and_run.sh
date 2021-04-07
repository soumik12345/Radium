clear
rm -rf build

if [ $COLAB_GPU -ne 1 ]; then
  source venv/bin/activate
fi

mkdir build
cd build

CUDACXX=/usr/local/cuda-${1}/bin/nvcc cmake ../
make

FILE=./radium
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

if [ -f "$FILE" ]; then

    clear
    ./radium
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
    
    if compgen -G "./dump/*.ppm" > /dev/null; then
      python3 plot_image.py
    fi

else
    printf "\n\n\n${RED}Compilation Failure!!!\n"
fi

if [ $COLAB_GPU -ne 1 ]; then
  deactivate
fi
