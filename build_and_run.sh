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
    ./radium
    cd ../
    DIRECTORY=./dump
    if [ -d "$DIRECTORY" ]; then
        rm -rf ./dump/*
    else
        mkdir ./dump
    fi
    mv ./build/*.ppm ./dump
    mv ./build/*.csv ./scenes
    printf "\n\n\n${GREEN}Compilation Successful!!!\n"
    python plot_image.py
else
    printf "\n\n\n${RED}Compilation Failure!!!\n"
fi

deactivate
