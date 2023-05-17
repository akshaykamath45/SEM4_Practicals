import socket
s=socket.socket();
host=socket.gethostname();
port=7000;
s.connect((host,port));
vote=input("\nEnter A\B\C : ");
s.send(vote.encode());
print(s.recv(1024).decode());
s.close();

