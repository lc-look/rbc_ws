# bin/bash
echo "Sync files to git"
sudo rm -rf /home/lc/rbc_2023/src/rbc_2023
sudo cp -r /home/lc/ros_work/rbc_ws/src/rbc_2023  /home/lc/rbc_2023/src/
cd /home/lc/rbc_2023/
git add .
git commit -m "This from Dell"
git push origin master