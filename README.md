# Python 3 Network Packet Sniffer

![C++ Version](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OS](https://img.shields.io/badge/OS-GNU%2FLinux-red?style=for-the-badge&logo=linux)
[![CodeFactor Grade](https://img.shields.io/codefactor/grade/github/musediqolamilekan/packet-sniffer?label=CodeFactor&logo=codefactor&style=for-the-badge)](https://www.codefactor.io/repository/github/musediqolamilekan/packet-sniffer)
[![License](https://img.shields.io/github/license/musediqolamilekan/packet-sniffer?style=for-the-badge)](https://github.com/musediqolamilekan/packet-sniffer/blob/main/LICENSE)

[![Linkedin](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](www.linkedin.com/in/olamilekan-musediq-a2b10b234)


A Network Packet Sniffer developed in C++. Packets are disassembled
as they arrive at a given network interface controller and their information
is displayed on the screen.

## Demo
![sniffer_demo](https://user-images.githubusercontent.com/15611424/178045423-067df4ec-1853-400e-9b5a-10154cb6fcc1.gif)

## Running the Application
### I. Development Mode
Simply clone this repository with `git clone`, install the dependencies and execute the 
`sniffer.py` file.
```
user@host:~$ git clone https://github.com/musediqolamilekan/Packet-sniffer.git
user@host:~$ cd Packet-Sniffer
user@host:~/packet-sniffer$ g++ -o sniffer main.cpp packetSniffer.cpp outputToScreen.cpp -lpcap
user@host:~/packet-sniffer$ sudo ./sniffer -i eth0 -d
```

*The `sudo` command is required due to the use of `socket.SOCK_RAW`,
which needs administrative privileges to run on GNU/Linux. Notice
that the existence of dependencies may require the execution of the interpreter contained in
the virtual environment in which the dependencies have been installed (if you use one),
instead of just using the system interpreter.*


## Legal Disclaimer
The use of code contained in this repository, either in part or in its totality,
for engaging targets without prior mutual consent is illegal. **It is
the end user's responsibility to obey all applicable local, state and
federal laws.**

Developers assume **no liability** and are not
responsible for misuses or damages caused by any code contained
in this repository in any event that, accidentally or otherwise, it comes to
be utilized by a threat agent or unauthorized entity as a means to compromise
the security, privacy, confidentiality, integrity, and/or availability of
systems and their associated resources. In this context the term "compromise" is
henceforth understood as the leverage of exploitation of known or unknown vulnerabilities
present in said systems, including, but not limited to, the implementation of
security controls, human- or electronically-enabled.

The use of this code is **only** endorsed by the developers in those
circumstances directly related to **educational environments** or
**authorized penetration testing engagements** whose declared purpose is that
of finding and mitigating vulnerabilities in systems, limiting their exposure
to compromises and exploits employed by malicious agents as defined in their
respective threat models.