import socket;
s=socket.socket();
host=socket.gethostname();
port=7000;
print("TCP Socket Created Successfully");
s.bind((host,port));
print("TCP Socket bnded to %s"%(port));
s.listen(5);
print("TCP Socket is listening");
A=0;
B=0;
C=0;
n=0;
while(n<3):
    c,addr=s.accept();
    print("Recieved Connection from : ",addr);
    k=c.recv(1024).decode();
    if(k=='A'):
        A+=1;
    elif(k=='B'):
        B+=1;
    elif(k=='C'):   
        C+=1;
    else:
        c.send("Wrong Vote".encode());
    c.send("\nVote Counted\nThank you for voting\n".encode());
    n+=1;
    c.close();
print("A = ",A,"B = ",B,"C = ",C);