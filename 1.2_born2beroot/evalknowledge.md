# Born2BeRoot Evaluation Knowledge

## Table of contents
- [Q&A](#qa)
    - [How does a virtual machine work?](#how-does-a-virtual-machine-work)
    - [Why I chose Debian as OS](#why-i-chose-debian-as-os)
    - [Differences between Debian and CentOS](#differences-between-debian-and-centos)
    - [The purpose of Virtual Machines](#the-purpose-of-virtual-machines)
    - [Differences between aptitude and apt](#differences-between-aptitude-and-apt)
    - [What is AppArmor?](#what-is-apparmor)
    - [How I set up password rules](#how-i-set-up-password-rules)
    - [Advantages of our password policy](#advantages-of-our-password-policy)
    - [Advantages & disadvantages of our password policy implementation](#advantages--disadvantages-of-our-password-policy-implementation)
    - [How does LVM work?](#how-does-lvm-work)
    - [Why use sudo and how does it work?](#why-use-sudo-and-how-does-it-work)
    - [What is UFW and why use it?](#what-is-ufw-and-why-use-it)
    - [What is SSH and why use it?](#what-is-ssh-and-why-use-it)
    - [How does my monitoring.sh work?](#how-does-my-monitoringsh-work)
    - [What is cron?](#what-is-cron)
    - [How did I make the script run every 10 minutes upon server start?](#how-did-i-make-the-script-run-every-10-minutes-upon-server-start)
- [Useful commands](#useful-commands)
- [Password Policy variables](#password-policy-variables)
- [Network adapter configuration](#network-adapter-configuration)

## Q&A

#### How does a virtual machine work?
- a hypervisor emulates a whole computer inside of the physical “host” computer
- it’s a separate independent machine but functions as if it was the only system to use the hardware
- when setting up, we have to assign parts of the physical hardware (CPU, RAM, Memory) for the VM, which makes it virtual hardware that the VM uses

#### Why I chose Debian as OS
- I chose Debian because it’s easier to work with compared to CentOS
- Being a beginner at network/system administration, I don't possess the knowledge to work with CentOS

#### Differences between Debian and CentOS
|    |  Debian  |  CentOS  |
|----|----------|----------|
|  Architecture support  |  - AArch64/ARM64<br>- armhf/armhfp<br>- i386<br>- ppc64el/ppc64le<br>- MIPSel<br>- MIPS64el<br>- s390x  |  - AArch64/ARM64<br>- armhf/armhfp<br>- i386<br>- ppc64el/ppc64le<br><br>CentOS 7: <br>- additionally supports POWER9<br>- focused on x86_64/AMD64<br>- other archs released through the AltArch SIG  |
|  Package management  |  - DEB package format<br>- dpkg/APT as the package manager  |  - RPM package format<br>- YUM/DNF as the package manager  |
|  Filesystems  |  - EXT4 default<br>- ext2/3<br>- NFSv3/4<br>- btrfs<br>- SMB<br>- GFS2<br>- ZFS through DKMS contribution  |  - XFS default<br>- ext2/3<br>- NFSv3/4<br>- btrfs<br>- SMB<br>- GFS2<br>does not officially support some filesystems that Debian offers (most notably ZFS)  |
|  Kernel  |  - 4.19 kernel<br>backports security fixes from newer kernels to current kernels -> falling behind with regards to security isn’t usually a concern  |  - ships with kernel 3.10 (CentOS 7) or 4.18 (CentOS 8)<br>- kernel-lt-5.4 and kernel-ml-5.10 packages available through 3rd party repos  |
|  Upgrading  |  - major version upgrades<br>- able to upgrade from one stable release to another<br>- 2-year release cycle with 3 years of full support and an additional 2 years of LTS (Long Term Support)  |  - minor version upgrades<br>- major releases typically have 10-year lifespan  |
|  Support  |  - primarily community supported<br>- offers a bug tracker<br>- offers a list of consultants that can be hired to resolve issues<br>- some downstream distros based on Debian have commercial support (most successful: Ubuntu)  |  - largely community supported<br>- commercial support not provided directly from CentOS Project (or Red Hat), but available through 3rd parties i.e. OpenLogic  |

#### The purpose of Virtual Machines
- to try a different OS without needing to buy new hardware
- to run software that requires a different operating system
- to develop software for other platforms
- to explore and experiment with an OS without fear of the consequences
- to use snapshots which makes it possible to restore the system even if something goes very wrong (doesn’t damage the hardware directly)
- to clone the system to another machine
- to accommodate different levels of processing power needs
- to test applications in a safe, sandboxed environment

#### Differences between aptitude and apt
|  Apt                          |  Aptitude                                          |
|-------------------------------|----------------------------------------------------|
|  lower-level package manager  |  higher-level package manager                      |
|  offers most commonly used commands of apt-get and apt-cache  |  offers apt-get, apt-mark, and apt-cache commands  |
|  command-line interface       |  command-line interface & interactive UI           |

#### What is AppArmor?
- effective and easy-to-use Linux application security system
- proactively protects the operating system and applications from external or internal threats, even zero-day attacks, by enforcing good behavior and preventing both known and unknown application flaws from being exploited
- allows the system administrator to restrict programs' capabilities with per-program profiles
- supplements the traditional Unix discretionary access control (DAC) model by providing mandatory access control (MAC)

#### How I set up password rules
- edited file /etc/login.defs for password expiration period
- installed libpam-pwquality
- edited file /etc/pam.d/common-password and added password policy variables ([Password Policy variables](#password-policy-variables))

#### Advantages of our password policy
- a strong password protects your computer from hackers and malicious software better
- the password policy ensures that the user sets a strong password

#### Advantages & disadvantages of our password policy implementation
|  Advantages  |  Disadvantages  |
|--------------|-----------------|
|  password expires every 30 days -> ensures that the user changes his password (safer)  |  harder to memorize for a human, making it more likely for the user to write down the password or use a password manager, which could be another threat  |
|  forcing uppercase, lowercase letters as well as digits increases the number of possible combinations, is therefore harder for a computer to crack  |  can contain whole meaningful words (if used less secure against hacking)  |
|  a password only needs to be as strong as the value of the data that is kept secret by it - in our case it wouldn’t make sense to make the policy harder because the data we have in our VM isn’t that valuable to others  |  doesn’t check for other personal information the user might use (like birth year)  |
|    |  character length of 10 is considered short among cyber security experts  |
|    |  doesn’t require any special characters such as !@#$%#&*  |

#### How does LVM work?
- LVM = Logical Volume Manager

It works by chunking the physical volumes (PVs) into physical extents (PEs). Extents are small, fixed-size chunks of memory and the size is determined by the volume group. The PEs are mapped onto logical extents (LEs) which are then pooled into volume groups (VGs). These groups are linked together into logical volumes (LVs) that act as virtual disk partitions and that can be managed as such by using LVM. The logical extents bring great flexibility because they are presented as a unified device by LVM but do not have to map to continuous physical extents. LVM can copy and reorganize the physical extents that compose a logical volume without any interruption to users. Logical volumes can also be easily expanded or shrunk by simply adding extents to or removing extents from the volume.

![LVM layout](https://cdn.thegeekdiary.com/wp-content/uploads/2014/10/LVM-basic-structure.png)

#### Why use sudo and how does it work?
- sudo = superuser do
- using sudo, the root user can grant a regular user access to perform root-privileged commands
- if a user has root-privileges using sudo, the root user can be disabled
- to set it up, a user can either be added to the “sudo” or “admin” group OR a custom user group can be added to the sudoers file
- example: a user does not have permissions to run ```apt update``` but with ```sudo apt update``` the user only has to enter their password (can be disabled in sudoers file) to run the command successfully

#### What is UFW and why use it?
- UFW = Uncomplicated Firewall
- utility designed to simplify the setup and management of firewall rules (ip-tables rules)
- gives us control of who or what is able to access the server and restrict traffic by only allowing certain ports
- protects from accidents -> example: an inexperienced user accidentally opens ports without knowing it
- it therefore adds extra layers of security

#### What is SSH and why use it?
- SSH = Secure (Socket) Shell
- secure protocol for sending encrypted information or setting up a secure connection between computers (based on IP address)
- uses public key pairs or asymmetric cryptography to authenticate hosts -> example: person A sends locked suitcase to person B who attaches his own lock and sends it back to person A who removes his own lock and sends it back to person B who can now remove his own lock and access the contents of the suitcase (suitcase was locked through the entire shipping procedure = secure from unwanted access)
- you should use it to maintain your privacy on the internet

#### How does my monitoring.sh work?
- wall command writes a message to all users across all logged in terminals
- a few commands and files give us the necessary information
- by using pipes as well as the commands grep, awk, uniq & wc, I formatted the output of these commands and files the way we want them to be displayed in the message
- to make everything more readable, I first save all the info in variables which are then used in the wall message

[My monitoring.sh file](https://github.com/aaron-22766/1.2_born2beroot/blob/main/monitoring.sh)

#### What is cron?
- it’s a scheduling tool
- it can perform commands and execute scripts at a specific time or in a specific interval

#### How did I make the script run every 10 minutes upon server start?
- I added the cron job “*/10 * * * * ./monitoring.sh” by editing the crontab file (```sudo crontab -u root -e```)
- the 5 asterisks stand for: min hour day month weekday -> on which the followed command will be run
- */XX means it will repeat every XX (min/hours/days/months ...) 

## Useful commands
|   Command                                             |   Function                                   |
|-------------------------------------------------------|----------------------------------------------|
|   ```/sbin/aa-status```                               |   Check if AppArmor is active                |
|   ```sudo ufw status```                               |   Check UFW service / rules                  |
|   ```sudo service ssh status```                       |   Check SSH service                          |
|   ```head -n 2 /etc/os-release```                     |   Check OS                                   |
|   ```getent passwd```                                 |   Check users                                |
|   ```getent group```                                  |   Check groups                               |
|   ```groups```                                        |   Check which group current user belongs to  |
|   ```sudo adduser <username>```                       |   Create new user                            |
|   ```sudo addgroup <name>```                          |   Create new group                           |
|   ```sudo adduser <username> <group name>```          |   Add user to group                          |
|   ```hostnamectl```                                   |   Display hostname                           |
|   ```sudo hostnamectl set-hostname <new>```           |   Change hostname                            |
|   ```sudo reboot```                                   |   Restart VM                                 |
|   ```dpkg -l \| grep <program>```                     |   Check if program is installed              |
|   ```sudo nano /etc/sudoers.d/sudoconfig```           |   Implementation of sudo rules               |
|   ```ls```                                            |   Check if folder exists                     |
|   ```sudo ufw allow 8080```                           |   Add ufw rule to open port 8080             |
|   ```sudo ufw status numbered```                      |   Check ufw rule numbered                    |
|   ```sudo ufw delete <number>```                      |   Delete ufw rule                            |
|   ```ssh <user>@127.0.0.1 -p 4242```                  |   Log in via ssh                             |
|   ```sudo crontab -u root -e```                       |   Edit crontab file                          |
|   ```dd if=/dev/zero of=/dev/null```<br>^C to cancel  |   Create CPU load (best on other user)       |
|   ```/etc/login.defs```                               |   Password expiration period file            |
|   ```sudo chage -l <username>```                      |   Check password expiry info of user         |

## Password Policy variables
(in /etc/pam.d/common-password)
| Variable            | Function                                            |
|---------------------|-----------------------------------------------------|
|   minlen=XX         |   min XX characters                                 |
|   ucredit=-XX       |   min XX upper-case letters                         |
|   lcredit=-XX       |   min XX lower-case letter                          |
|   dcredit=-XX       |   min XX digits                                     |
|   maxrepeat=XX      |   max XX same consecutive characters                |
|   reject_username   |   not allowed to contain username                   |
|   difok=XX          |   min XX of changes required from the old password  |
|   enforce_for_root  |   root also has to abide to the policy              |

[pam_pwquality(8) - Linux man page](https://linux.die.net/man/8/pam_pwquality)

## Network adapter configuration
You may not be able to connect to your VM via SSH with standard settings in
VirtualBox. Here’s how to fix it:
1. With VM off
2. Settings -> Network -> Adapter 1 -> Advanced -> Port forwarding
3. Add new rule like this:

|   Protocol  |    Host IP   |   Host Port  |    Guest IP  |   Guest Port  |
|:-----------:|:------------:|:------------:|:------------:|:-------------:|
|      TCP    |   127.0.0.1  |      4242    |   10.0.2.15  |      4242     |
