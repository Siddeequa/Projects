/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CCPAssignmentTerminal;

import java.util.concurrent.Semaphore;

/**
 *
 * @author User
 */
public class busInspector {
    // Use semaphore to control access
    Semaphore inspSem = new Semaphore(1);
    // Initialise at which gate inspector is at first
    String location = "A";
    
    // Access inpectingTicket method from ticket class to use for bus inpector
    public ticket checkTicket(customer cust)
    {
        if(!location.equals(cust.t.dest)) // If inspector is not at same gate as customer
        {
            System.out.println("\nCustomer " + cust.customerID + " is waiting for ticket inspector to get ticket checked!\n");
        }
        else // Inspector is at same gate as customer
        {
            if(inspSem.availablePermits()==0) // If inspector is busy with other customer 
            {
                System.out.println("Inspector is busy with another customer!\nCustomer " + cust.customerID + " is waiting!\n");
            }
        }
        try
        {
            // Try to access ticket inspector
            inspSem.acquire();
        }
        catch(InterruptedException e){}
        
        if(!location.equals(cust.t.dest)) // If inspector at different gate, needs to displace to other gate
        {
            System.out.println("\nInspector is heading towards gate: " + cust.t.dest);
            location = cust.t.dest;
            try
            {
                Thread.sleep(1000); // Time taken to move between gates
            }
            catch(InterruptedException e){}
            
            System.out.println("\nInspector is at gate: " + cust.t.dest);
        }
        System.out.println("\nInspector is checking Customer " + cust.customerID + "'s ticket!\n");
        try
        {
            Thread.sleep(2000); //Inspector checks ticket for 2 seconds, as stated in question requirements
        }
        catch(InterruptedException e){}
        // Check ticket
        cust.t.checkTicket();
        System.out.println("Customer " + cust.customerID + "'s ticket ("+cust.t.ticketNum+") checked!\n");
        // Free semaphore so others can access
        inspSem.release();
        return cust.t;
    }
}
