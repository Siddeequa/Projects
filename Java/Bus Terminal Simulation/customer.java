/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CCPAssignmentTerminal;

import java.util.Random;

/**
 *
 * @author User
 */
public class customer implements Runnable{
    int customerID;
    scanner s;
    customer cust;
    ticket t = null;
    String dest;
    terminal term;
    busInspector insp;
    ticketingMachine M; 
    // 2 ticket counters
    ticketCounter A;
    ticketCounter B;
    // 3 waiting room gates
    waitingRoom wA;
    waitingRoom wB;
    waitingRoom wC;
    waitingRoom current; // Waiting room gate to go to
    
    // Constructor
    public customer(int custID, terminal term, ticketingMachine M, ticketCounter A, ticketCounter B, waitingRoom wA, waitingRoom wB, waitingRoom wC, busInspector insp)
    {
        this.customerID = custID;
        this.term = term;
        this.M = M;
        this.A = A;
        this.B = B;
        this.wA = wA;
        this.wB = wB;
        this.wC = wC;
        this.insp = insp;

    }
    
    @Override
    public void run()
    {
        System.out.println("\nNew customer "+customerID+" coming to bus terminal\n");
        
        // Entering bus terminal
        term.enterTerminal(this);
        
        // Choosing destination location at random
        int loc = new Random().nextInt(3); 
        // Pass loc number generated in switch statement for destination choice
        switch (loc) {
            case 0:
                dest="A";
                current = wA;
                break;
            case 1:
                dest="B";
                current = wB;
                break;
            default:
                dest="C";
                current = wC;
                break;
        }
        
        try
        {
            Thread.sleep(1000);
        }
        catch(InterruptedException e){}
        
        // Getting tickets
        while(t == null) 
        {
            // Generate 3 random numbers to choose getting ticket mode
            int mode = new Random().nextInt(3); 
            switch (mode) {
                // Ticketing Machine
                case 0:
                    if(M.working == true)
                    {
                        t = M.getTicket(this, dest);
                    }   break;
                // Counter A
                case 1:
                    if(A.open == true)
                    {
                        t = A.getTicket(this, dest);
                    }   break;
                // Counter B    
                case 2:
                    if(B.open == true)
                    {
                        t = B.getTicket(this, dest);
                    }   break;
                default:
                    try
                    {
                        Thread.sleep(10);
                    }
                    catch(InterruptedException e){}
                    break;
            }
        }
        
        try
        {
            Thread.sleep(3000);
        }
        catch(InterruptedException e){}
        
        //enter waiting area
        System.out.println("Customer " + customerID + " going to waiting room gate " + t.dest + "\n");
        current.enteringWaitingRoom(this);
        
        // Scanning temperature and checking ticket
        // Generate order in which to scan and check
        int order = new Random().nextInt(2);
        if(order == 0) // Check temperauture first, then check ticket
        {
            s.checkTemperature(this); // Check temperature
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException e){}
            insp.checkTicket(this); // Check ticket by inspector
        }
        else // Check ticket first, then check temperature
        {
            insp.checkTicket(this); // Get ticket checked by inspector
            try
            {
                Thread.sleep(1000);
            }
            catch(InterruptedException e){}
            s.checkTemperature(this); // Check temperature at scanner
        }
        
        // Board bus if temperature is normal (if proceed == true)
        if (s.checkTemperature(this).proceed == true){
            current.boardBus(this);
        }
    }
}
