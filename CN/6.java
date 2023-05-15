import java.util.Scanner;

class Main {

  public static void main(String arg[]) {
    Scanner sc = new Scanner(System.in);
    String ip;
    System.out.print("Enter an IP Address : ");
    ip = sc.next();

    String ipClass;
    String mask;

    int val = Integer.parseInt(ip.substring(0, ip.indexOf(".")));

    if (val >= 0 && val <= 127) {
      mask = "255.0.0.0";
      ipClass = "Class A";
    } else if (val >= 128 && val <= 191) {
      mask = "255.255.0.0";
      ipClass = "Class B";
    } else if (val >= 192 && val <= 223) {
      mask = "255.255.255.0";
      ipClass = "Class C";
    } else if (val >= 224 && val <= 239) {
      mask = "Multicast";
      ipClass = "Class D";
    } else if (val >= 240 && val <= 255) {
      mask = "Reserved";
      ipClass = "Class E";
    } else {
      System.out.println("Invalid Input.IP Address must be less than 256");
      return;
    }
    System.out.println("Subnet Maksk of IP Address " + ip + " is " + mask);
    if (!mask.equals("Multicast") && !mask.equals("Reserved")) {
      String[] ipParts = ip.split("\\.");
      String[] maskParts = mask.split("\\.");

      String subnetAddress = "";
      for (int i = 0; i < 4; i++) {
        subnetAddress +=
          Integer.parseInt(ipParts[i]) & Integer.parseInt(maskParts[i]);
        if (i != 3) {
          subnetAddress += '.';
        }
      }
      System.out.println(
        "Subnet Address of the IP Address is " + subnetAddress
      );
    }

    System.out.println("Class of IP Address is " + ipClass);
  }
}
