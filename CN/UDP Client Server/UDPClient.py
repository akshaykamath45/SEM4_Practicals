import socket;
s=socket.socket(type=socket.SOCK_DGRAM,family=socket.AF_INET);
host=socket.gethostname();
port=7000;
vote=input("Enter A/B/C : ");
s.sendto(vote.encode(),(host,port))
print(s.recvfrom(1024)[0].decode());
s.close();