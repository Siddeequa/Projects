/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CCPAssignmentTerminal;

import java.util.LinkedList;
import java.util.Random;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.Semaphore;

/**
 *
 * @author User
 */
public class terminal extends Thread {
    // Use semaphore to control access
    Semaphore bterminalSem = new Semaphore(50,true); //Customers half max capacity because of social distancing as per question requirement
    Semaphore gateSem = new Semaphore(1,true); //customer enter each gate waiting room one at a time
    boolean open;
    int customerID = 1;
    getBusNumber bnum;
    getTicketNumber tnum;
    busInspector insp;
    LinkedList<Future<bus>> busA;
    LinkedList<Future<bus>> busB;
    LinkedList<Future<bus>> busC;
    // 1 ticket machine (breaks often)
    ticketingMachine tMachine;
    // 2 ticket counters
    ticketCounter tcA;
    ticketCounter tcB;
    // 3 waiting rooms, one for each gate
    waitingRoom wA;
    waitingRoom wB;
    waitingRoom wC;
    // 3 temperature scanners, one at each departure gate
    scanner sA;
    scanner sB;
    scanner sC;
   
    
    // Constructor
    public terminal()
    {
        open = true;
        bnum = new getBusNumber();
        tnum = new getTicketNumber();
        insp = new busInspector();
        busA = new LinkedList<>();
        busB = new LinkedList<>();
        busC = new LinkedList<>();
        tMachine = new ticketingMachine(tnum);
        tcA = new ticketCounter(tnum, "A");
        tcB = new ticketCounter(tnum, "B");
        wA = new waitingRoom("A"/*, sA*/);
        wB = new waitingRoom("B"/*, sB*/);
        wC = new waitingRoom("C"/*,sC*/);
        sA = new scanner();
        sB = new scanner();
        sC = new scanner();
        
    } 
    
    @Override
    public void run()
    {
        // Set up thread pool
        // Thread pool will monitor the runnable threads.
        ExecutorService terminal=Executors.newCachedThreadPool();
        //submit threads inside thread pool
        terminal.submit(new terminalGuard(this));
        terminal.submit(new ticketRepair(tMachine));
        terminal.submit(new terminalStaff(tcA));
        terminal.submit(new terminalStaff(tcB));
        terminal.submit(new manageBus(bnum, "A", wA, terminal, busA)); 
        terminal.submit(new manageBus(bnum, "B", wB, terminal, busB));
        terminal.submit(new manageBus(bnum, "C", wC, terminal, busC));
        terminal.submit(new recordBus(busA,"A.txt"));
        terminal.submit(new recordBus(busB,"B.txt"));
        terminal.submit(new recordBus(busC,"C.txt"));
        
        while(true)
        {
            terminal.submit(new customer(customerID, this, tMachine, tcA, tcB, wA, wB, wC, insp)); 
            customerID++;
            try
            {
                // New customer arriving every 1 to4 seconds, as per question requirement
                Thread.sleep(1000*(1+new Random().nextInt(3))); 
            }
            catch(InterruptedException e){}
        }
    }
    
    public void terminalFull()
    {
        // Close entrance if full
        open = false;
        System.out.println("Bus Terminal entrance full! Entrance closed!\n");
        try 
        {
            // Entrance will remain closed until terminal capacity back to 70%
            bterminalSem.acquire(35); 
            System.out.println("Bus Terminal entrance is open again\n!");
            bterminalSem.release(35);
        }
        catch(InterruptedException e){}

        // Once entrance open again, set open to true
        open = true;
    }
    
    public void enterTerminal(customer cust)
    {
        if(open == false) // Terminal full, entrance closed.
        {
            System.out.println("\nTerminal entrance closed! Customer "+cust.customerID+" is waiting outside!\n(Number of people in terminal: "+(50-bterminalSem.availablePermits())+")\n");
        }
        try
        {
            // If terminal is full, a customer can only enter building once another leaves 
            gateSem.acquire(); // Leaves through gate
            bterminalSem.acquire(); // Try to get permit to enter
            Thread.sleep(20);
            System.out.println("Customer " + cust.customerID + " has entered Bus Terminal\n(Number of people in terminal: "+(50-bterminalSem.availablePermits())+")\n");
            Thread.sleep(2000); // Time taken to get permit and enter terminal when permit obtained
            gateSem.release();
        }
        catch(InterruptedException e){}  
    }
    
    public void exitingTerminal(customer cust)
    {
        System.out.println("\nCustomer "+cust.customerID+" is exiting the Bus Terminal!\n");
        // Free permit
        bterminalSem.release();
    }
}
