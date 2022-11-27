'''
Author: Donya aka Niuklear
Niuklear@gmail.com 
twitch.tv/Niuklear Twiiter.com/Niuklear
'''
# The following script moves all the clips from the default folder to the desired folder.
# You can assing your shortcut button on for saving buffer replays in different direcotry other than the original one
# You can create an .exe file if your stream deck software or its alternative doesn't support 
# running the script, using the follwoing line in cmd: pyinstaller --onefile clippingScrpt.py

import os
 
source = r'C:\clips'  #replace this directory with where your clips are saved
destination = r'C:\category'    #replace this directory with your preferred categy
 
# gather all files
allfiles = os.listdir(source)
 
# iterate on all files to move them to destination folder
for f in allfiles:
    src_path = os.path.join(source, f)
    dst_path = os.path.join(destination, f)
    os.rename(src_path, dst_path)


