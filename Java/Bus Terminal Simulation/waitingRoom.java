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
// class for waiting room and gates
public class waitingRoom {
    // Using semaphores to control access to common resources: gates, buses and waiting room
    Semaphore busLimit = new Semaphore(1,true); // Control buses at gates
    Semaphore toBoardBus = new Semaphore(1,true); // Control people boarding bus
    Semaphore seat = new Semaphore(10,true); // Control people accessing waiting room
    String gateName; // Gates (A, B, C)
    //scanner tscan; // Temperature scanner at each gate
    bus b = null;
    
    // Class constructor
    public waitingRoom(String name/*, scanner tscan*/)
    {
        this.gateName = name;
        //this.tscan = tscan;
    }
    
    // methods dealing with buses at the gates
    
    public void busArrival(bus b)
    {
        if(busLimit.availablePermits()==0) //no permit from semaphore
        {
            System.out.println("\nThere is already a bus at gate: " + gateName + "\nBus " + b.busId + " is waiting in line!\n");
        }
        try
        {
            // try to get permit from semaphore
            busLimit.acquire();
            System.out.println("\nBus " + b.busId + " is at gate: " + gateName);
        }
        catch(InterruptedException e){}
        this.b = b;        
    }
    
    public void busLeaving()
    {
        System.out.println("\nBus " + b.busId + " is leaving gate: " + gateName);
        b = null;
        // free permit
        busLimit.release();
    }
    
    // methods dealing with customers at departure gates
    
    public void enteringWaitingRoom(customer cust)
    {
        if(seat.availablePermits()==0)
        {
            // No permit available if 10 people already in
            System.out.println("Gate area: " + gateName + " is full. Customer " + cust.customerID + " is waiting to enter waiting room.\n(Number of people at gate "+gateName+": " +(10-seat.availablePermits())+")");   
        }
        try
        {
            seat.acquire();
            System.out.println("Customer " + cust.customerID + " has entered gate: " + gateName + "\n(Number of people at gate " + gateName + ": "+(10-seat.availablePermits())+")");
        }
        catch(InterruptedException e){}
    }
    
    public void leavingWaitingRoom(customer cust)
    {
        System.out.println("Customer " + cust.customerID + " is leaving through gate: " + gateName);
        // free semaphore permit once left so other people can get in
        seat.release(); 
    }
    
    public void boardBus(customer cust)
    {          
        try
        {
            // get permit to board 
            toBoardBus.acquire();
        }
        catch(InterruptedException e){}
        while(true)
        {
            if(b != null)
            {
                // Customer boards
                b.boardBus(cust);
                // Free permit 
                toBoardBus.release();
                break;
            }
            else
            {
                try
                {
                    Thread.sleep(1000);
                }
                catch(InterruptedException e){}
            }
        }
    }
}
