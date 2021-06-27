/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CCPAssignmentTerminal;

import java.util.LinkedList;
import java.util.concurrent.Callable;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

/**
 *
 * @author User
 */
public class bus implements Callable<bus> {
    int busId;
    CountDownLatch latch;
    waitingRoom w;
    LinkedList<customer> customers = new LinkedList<>();
    String dest;
    boolean waitFull; // To know when bus should leave
    
    // Constructor with parameters
    public bus(int busId, String dest, waitingRoom w, CountDownLatch latch, boolean waitFull)
    {
        this.busId = busId;
        this.dest = dest;
        this.w = w;
        this.latch = latch;
        this.waitFull = waitFull;
    }
     
    public void boardBus(customer cust)
    {
        // Leave gate to board bus
        w.leavingWaitingRoom(cust);
        // Add customer to list of customers in bus
        customers.addFirst(cust);
        // Update latch as number of passengers in bus increases
        latch.countDown(); 
        System.out.println("Customer " + cust.customerID + " entered Bus: " + busId + "\n(bus " + busId + " num of people: "+(6-latch.getCount())+")\n");
        try
        {
            Thread.sleep(1000);
        }
        catch(InterruptedException e){}
    }
    
    @Override
    public bus call() throws Exception
    {
        System.out.println("\nBus: " + busId + " is at terminal\n");
        w.busArrival(this);
        if(waitFull == true)
        {
            System.out.println("\nBus: " + busId + " is waiting for max capacity before departing\n");
            latch.await();
            System.out.println("\nBus: " + busId + " is full\n");
            System.out.println("\nAll customers currently in Bus " + busId + ":");
            // List customers in bus
            customers.stream().map(c -> {
                System.out.println("\nCustomer  " + c.customerID + " is in Bus: " + busId);
                return c;
            }).forEachOrdered(c -> {
                c.term.bterminalSem.release();
            });
            w.busLeaving();
        }
        else //waitFull == false
        {
            //System.out.println("\nBus: " + busId + " is full!\n");
            latch.await(10, TimeUnit.SECONDS); // Bus waits for 10 seconds as stated in question requirements
            if(customers.size()==6) // number of customers half capacity of bus (for social distancing) as said in question
            {
                System.out.println("\nBus: " + busId + " is full!\n");
            }
            else
            {
                System.out.println("\nBus: " + busId + " has waited for 10 seconds already!\n");
            }
            
            System.out.println("\nAll ("+(6-latch.getCount())+") customers in Bus: " + busId + ":");
            // Lits customers in bus
            customers.stream().map(c -> {
                System.out.println("\tCustomer " + c.customerID + " is in Bus: " + busId);
                return c;
            }).forEachOrdered(c -> {
                c.term.bterminalSem.release();
            });
            w.busLeaving();
        }
        return this;
    }
}
