/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CCPAssignmentTerminal;

import java.util.Random;
import java.util.concurrent.Semaphore;

/**
 *
 * @author User
 */
public class scanner {
    // Use semaphore to control access to temperature scanner 
    Semaphore scannerSem = new Semaphore(1,true);
    
    // Access checkTemperature method from ticket class for scanner to use
    public ticket checkTemperature(customer cust)
    {
        if(scannerSem.availablePermits()==0) // A customer already using scanner 
        {
            System.out.println("\nTemperature scanner busy! Customer " + cust.customerID + " is waiting in line for temperature scanner!\n");
        }
        try
        {
            // Try accessing scanner
            scannerSem.acquire();
            System.out.println("\nCustomer "+cust.customerID+" is using scanner!\n");
            // Get customer temperature before boarding bus
            Random r = new Random();
            int tempGen = r.nextInt(10) + 30; // Generating a random temperature for the customer
            Thread.sleep(5000); // Customer takes 5 seconds with scanner, as stated in question requirements
  
            if (tempGen <= 37){ // If normal temperature, can proceed.
                System.out.println("\nCustomer " + cust.customerID + " has normal temperature! Can board bus!\n");
            }
            else{ // high temperature
                cust.t.proceed = false; // Cannot proceed
                System.out.println("\nCustomer running fever! Cannot board bus!\n");
            }
        }
        catch(InterruptedException e){}
        
        //cust.t.checkTemperature(); // Check temperature
        System.out.println("\nCustomer " + cust.customerID + "(" + cust.t.ticketNum + ") has checked temperature!\n");
        scannerSem.release(); // Free scanner permit so others can use
        
        return cust.t;
    }
}
