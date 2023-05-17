import socket;
s=socket.socket(family=socket.AF_INET,type=socket.SOCK_DGRAM);
print("UDP Socket Created Successfully");
host=socket.gethostname();
port=7000;
s.bind((host,port));    
print("UDP Socket is binded to %s"%(port));
print("UDP Socket is Listening \n");
A=0;
B=0;
C=0;
n=0;
while(n<3):
    data,addr=s.recvfrom(1024);
    k=data.decode();
    print("Got Connection from : ",addr);
    if(k=='A'):
        A+=1;
    elif(k=='B'):
        B+=1;
    elif(k=='C'):
        C+=1;
    else:
        s.sendto("Wrong Vote".encode(),addr);
    s.sendto("\nVote Counted\nThank you for voting\n".encode(),addr);
    n+=1;
s.close();
print("A = ",A,"B = ",B,"C = ",C);