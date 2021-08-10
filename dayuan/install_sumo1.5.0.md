# Install SUMO 1.5.0
Created by Dayuan, refer to  https://sumo.dlr.de/docs/Installing/Linux_Build.html

## Step 1
 Download sumo-src-1.5.0.tar.gz from https://sourceforge.net/projects/sumo/files/sumo/version%201.5.0/

## Step 2 Build sumo from source: 
Run below commands one by one:
``` $ sudo apt-get install git cmake python3 g++ libxerces-c-dev libfox-1.6-dev libgdal-dev libproj-dev libgl2ps-dev```
``` $ tar xzf sumo-src-1.5.0.tar.gz```
``` $ ls ``` you should see a directory called sumo-1.5.0
``` $ mv sumo-1.5.0 ~ ``` #or you move it to the path you want

 Go to your HOME folder, and find one of the next three files (depending of your Linux distribution): .bash_profile, .bash_login, .bashrc or .profile (Note that these files can be hidden). Then edit the file, add the below line at the end of the file:
 export SUMO_HOME="/home/<user>/sumo-<version>" # in my case I added "export SUMO_HOME="/home/dayuan/sumo-1.5.0" " at the end of ~/.bashrc

 $  source filename_youchoose # in my case it is: source ~/.bashrc 
 
 You can check that SUMO_HOME was successfully set if you type
 $ echo $SUMO_HOME
 and console shows "/home/<user>/sumo-<version>" #in my case it shows: /home/dayuan/sumo-1.5.0

 $  cd $SUMO_HOME
 ~/sumo-1.5.0$ mkdir build/cmake-build
 ~/sumo-1.5.0$ cd build/cmake-build
 ~/sumo-1.5.0$ cmake ../..
 ~/sumo-1.5.0$ make -j $(nproc)
