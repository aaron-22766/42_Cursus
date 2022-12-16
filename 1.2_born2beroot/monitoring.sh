#!/bin/bash

arch=$(uname -a)

pcpu=$(grep "physical id" /proc/cpuinfo | uniq | wc -l)

vcpu=$(grep -c "^processor" /proc/cpuinfo)

mtkb=$(($(free | awk '/Mem/ {print $2}')))
mukb=$(($(free | awk '/Mem/ {print $3}')))
memt=$(($mtkb / 1000))
memu=$(($mukb / 1000))
memp=$(($mukb / ($mtkb / 100))).$(($mukb / ($mtkb / 10000) % (100 * ($mukb / ($mtkb / 100)))))

dtkb=$(($(df -Bk | awk '/^\/dev\// && !/\/boot$/ {tt += $2} END {print tt}')))
dukb=$(($(df -Bk | awk '/^\/dev\// && !/\/boot$/ {ut += $3} END {print ut}')))
diskt=$(($dtkb / 1000000))
disku=$(($dukb / 1000))
diskp=$(($dukb / ($dtkb / 100)))

cpul=$(top -bn1 | awk '/^%Cpu\(s\):/ {printf("%.1f%%"), $1 + $4}')

boot=$(who -b | awk '{print $3 " " $4}')

lvmn=$(cat /etc/fstab | grep "/dev/mapper/" | wc -l)
lvmu=$(if [[ $lvmb == 0 ]]; then echo no; else echo yes; fi)

ctcp=$(awk '/TCP/ {print $3}' /proc/net/sockstat)

user=$(users | wc -w)

ip=$(hostname -I)
mac=$(ip link show | awk '/link\/ether/ {print $2}')

sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "  #Architecture: $arch
        #CPU physical: $pcpu
        #vCPU: $vcpu
        #Memory Usage: $memu/${memt}MB ($memp%)
        #Disk Usage: $disku/${diskt}Gb ($diskp%)
        #CPU load: $cpul
        #Last boot: $boot
        #LVM use: $lvmu
        #Connections TCP: $ctcp ESTABLISHED
        #User log: $user
        #Network: IP $ip($mac)
        #Sudo: $sudo cmd"
