python3 -m venv venv
source venv/bin/activate
if [ $1 == "mac" ]
then
   python3 -m pip install opencv-python==4.5.1.48 --no-cache-dir
else
   sudo apt-get install python3-opencv
   sudo apt-get install python3-tk
   python3 -m pip install opencv-python==4.5.1.48 --no-cache-dir
fi
python3 -m pip install -r requirements.txt --no-cache-dir
deactivate
