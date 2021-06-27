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
public class ticketingMachine {
    // Semaphore to control access to ticketing machine. One person at a time.
    Semaphore tmachineSem = new Semaphore(1,true);
    ticket t;
    boolean working;
    getTicketNumber tnum;
    
    // Constructor
    public ticketingMachine(getTicketNumber tnum)
    {
        this.tnum = tnum;
        working = true; // Initialise machine to working fine first
    }
    
    // Using getTicket method from ticket class for ticketing machine
    public ticket getTicket(customer cust, String dest)
    {
        if(tmachineSem.availablePermits() == 0) // If mmachine is busy, no permit given
        {
            System.out.println("Ticketing Machine busy! Customer " + cust.customerID + " is in line.");
        }
        try
        {
            // try to get access
            tmachineSem.acquire();
        }
        catch(Exception e){}
        
        // If not working
        if(working == false)
        {
            System.out.println("Customer " + cust.customerID + " leaves the ticketing machine line.");
            // Release permit
            tmachineSem.release();
            return null;
        }
        else
        {
            System.out.println("Customer "+cust.customerID+" using the Ticketing Machine!");
            try
            {
                Thread.sleep(4000); // Customer takes 4 seconds at machine, as per question requirement
            }
            catch(Exception e){}
            
            // In case machine breaks upon using
            // Giving machine a 50% chance of breaking
            int broken = new Random().nextInt(2);
            if(broken == 0)
            {
                machineBreakDown();
                System.out.println("Customer " + cust.customerID + " received no ticket!\nCustomer " + cust.customerID + " is leaving the Ticketing Machine line.\n");
                // Free permit
                tmachineSem.release();
                return null;
            }
            try
            {
                Thread.sleep(4000);
            }
            catch(InterruptedException e){}
            
            // If machine worked fine
            // Get ticket number and destination
            int ticketNum = tnum.getTicketNumber();
            t = new ticket(ticketNum, dest);
            System.out.println("Ticketing Machine has issued ticket: " + t.ticketNum + " (Destination: " + t.dest + ") for customer " + cust.customerID);
            System.out.println("Customer " + cust.customerID + " is done with ticketing machine.");
            // free semaphore permit so others can use
            tmachineSem.release();
            return t;
        }
    }
    
    public void machineBreakDown()
    {
        working = false;
        System.out.println("\n\nTicketing Machine broke down!\n");
    }
    
    public void machineRepair()
    {
        System.out.println("\n\nTicket Machine is fixed! Can be used again!\n");
        working = true;
    }
}
