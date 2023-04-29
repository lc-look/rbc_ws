# bin/bash
echo "Sync git files to local"
cd /home/lc/rbc_2023/
git pull origin master
sudo rm -rf /home/lc/ros_work/rbc_ws/src/rbc_2023
sudo cp -r /home/lc/rbc_2023/src/rbc_2023 /home/lc/ros_work/rbc_ws/src/