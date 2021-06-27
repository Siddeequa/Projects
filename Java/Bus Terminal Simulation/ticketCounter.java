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
public class ticketCounter {
    // Semaphore to control access
    Semaphore tcounterSem = new Semaphore(1,true);
    ticket t;
    String ticketCounterName; // A or B
    boolean open; // To check whether staff went on toilet break
    boolean counterInUse; // To know if the counter is currently in use
    getTicketNumber tnum;
    
    // Constructor
    public ticketCounter(getTicketNumber tnum, String ticketCounterName)
    {
        this.tnum = tnum;
        this.ticketCounterName = ticketCounterName;
        open = true; // Initialise to true first
    }
    
    public void toiletBreak()
    {
        // If staff goes to washroom, set open to false
        open = false;
        System.out.println("\nStaff member from Ticket Counter " + ticketCounterName + " is taking a toilet break!");
        System.out.println("\nTicket counter " + ticketCounterName + " is currently closed!\n");
    }
    
    public void backFromBreak()
    {
        // Open counter once back
        open = true;
        System.out.println("\nStaff member from Ticket Counter " + ticketCounterName + " is back to work!");
        System.out.println("\nTicket counter " + ticketCounterName + " is open again!\n");
    }
    
    // Access getTicket method from ticket class to use for ticket counters
    public ticket getTicket(customer cust, String dest)
    {
        if(tcounterSem.availablePermits()==0) // If no permit, busy
        {
            System.out.println("Ticket Counter " + ticketCounterName + " is busy! Next Customer " +cust.customerID + " is in line!\n");
        }
        try
        {
            // Get access to counter
            tcounterSem.acquire();
        }
        catch(InterruptedException e){}
        
        if(open == false)
        {
            // Leave line if counter closed
            System.out.println("Customer "+cust.customerID+" leaves the line at Ticket Counter " + ticketCounterName);
            // Free permit
            tcounterSem.release();
            return null;
        }
        else
        {
            // Customer at counter
            counterInUse = true;
            System.out.println("\nCustomer " + cust.customerID + " is at Ticket Counter " + ticketCounterName);
            try
            {
                Thread.sleep(8000);// Customer take 8 seconds at counter according to question requirements
            }
            catch(InterruptedException e){}
            
            // Get ticket and destination
            int ticketNumber = tnum.getTicketNumber();
            t = new ticket(ticketNumber,dest);
            System.out.println("Customer "+cust.customerID+" has obtained ticket: " + t.ticketNum + " ("+t.dest+") and left counter\n");
            // Counter now free
            counterInUse = false;
            tcounterSem.release();
            return t;
        }
        
    }
}
