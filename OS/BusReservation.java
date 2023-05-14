public class BusReservation extends Thread{
	int vacant=2,required;
	BusReservation(int r){
		required=r;
	}
	
	public synchronized void run(){
	
	System.out.println("Welcome "+ Thread.currentThread().getName()+"!");
 	System.out.println("No. of seats left: " + vacant);
	if(required<=vacant){
	
	System.out.println(required + " Tickets have been booked");
	try{
		Thread.sleep(1000);
	}catch(Exception e){
		e.printStackTrace();
	}
	vacant=vacant-required;
	}else{
	System.out.println("All Tickets have been booked");
	}
	}

	public static void main (String arg[]){
	BusReservation br=new BusReservation (2);
	Thread t1=new Thread(br);
	Thread t2=new Thread(br);
	t1.setName("Akshay");
	t2.setName("Suresh");
	t1.start();
	t2.start();
	}

}