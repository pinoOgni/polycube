#!/bin/bash

#source "helpers.bash"
source "${BASH_SOURCE%/*}/helpers.bash"

function cleanup {
  set +e
  polycubectl simplebridge del br1
  polycubectl lbdsr del lb1
  sudo pkill -SIGTERM netcat
  delete_veth 9
  delete_link 2
}

trap cleanup EXIT

set -x
set -e

TYPE="TC"

if [ -n "$1" ]; then
  TYPE=$1
fi

create_veth 9
create_link 2

polycubectl simplebridge add br1
polycubectl lbdsr add lb1 type=$TYPE

# backend servers
simplebridge_add_port br1 veth1
simplebridge_add_port br1 veth2
simplebridge_add_port br1 veth3

# clients
simplebridge_add_port br1 veth4
simplebridge_add_port br1 veth5
simplebridge_add_port br1 veth6
simplebridge_add_port br1 veth7
simplebridge_add_port br1 veth8
simplebridge_add_port br1 veth9

#lbdsr ports
simplebridge_add_port br1 link12
simplebridge_add_port br1 link22

#config lb
polycubectl lbdsr lb1 ports add link11 type=FRONTEND
polycubectl lbdsr lb1 ports add link21 type=BACKEND
polycubectl lbdsr lb1 ports link11 set peer=link11
polycubectl lbdsr lb1 ports link21 set peer=link21

# configure webservers not to responde to arp requests
mac1=$(sudo ip netns exec ns1 ifconfig | grep veth1_ | awk '{print $5}')
polycubectl lbdsr lb1 backend pool add 1 mac=$mac1
sudo ip netns exec ns1 sudo ifconfig lo 10.0.0.100 netmask 255.255.255.255 up
sudo ip netns exec ns1 sudo sysctl -w net.ipv4.conf.all.arp_ignore=1
sudo ip netns exec ns1 sudo sysctl -w net.ipv4.conf.all.arp_announce=2

mac2=$(sudo ip netns exec ns2 ifconfig | grep veth2_ | awk '{print $5}')
polycubectl lbdsr lb1 backend pool add 2 mac=$mac2
sudo ip netns exec ns2 sudo ifconfig lo 10.0.0.100 netmask 255.255.255.255 up
sudo ip netns exec ns2 sudo sysctl -w net.ipv4.conf.all.arp_ignore=1
sudo ip netns exec ns2 sudo sysctl -w net.ipv4.conf.all.arp_announce=2

mac3=$(sudo ip netns exec ns3 ifconfig | grep veth3_ | awk '{print $5}')
polycubectl lbdsr lb1 backend pool add 3 mac=$mac3
sudo ip netns exec ns3 sudo ifconfig lo 10.0.0.100 netmask 255.255.255.255 up
sudo ip netns exec ns3 sudo sysctl -w net.ipv4.conf.all.arp_ignore=1
sudo ip netns exec ns3 sudo sysctl -w net.ipv4.conf.all.arp_announce=2

sudo ip netns exec ns1 netcat -l -u 2021 &
sudo ip netns exec ns2 netcat -l -u 2021 &
sudo ip netns exec ns3 netcat -l -u 2021 &

for i in `seq 4 9`;
do
  for j in `seq 1 3`;
  do
    sudo ip netns exec ns$j nc -u -n -z 10.0.0.100 2021
  done
done
