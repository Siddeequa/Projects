/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CCPAssignmentTerminal;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

/**
 *
 * @author User
 */
public class recordBus implements Runnable{
    File f;
    FileWriter fw;
    // Future monitors the progress of task execution by threads.
    // Future checks status of Callable and get result from Callable once thread is done.
    LinkedList<Future<bus>> buses;
    bus b = null;
    Future<bus> fut;

    // Constructor
    public recordBus(LinkedList<Future<bus>> buses, String filename) 
    {
        this.buses = buses;
        f = new File(filename);
    }
    
    @Override
    public void run()
    {
        try
        {
            fw = new FileWriter(f, false);
            fw.write("");
            fw.close();
        }
        catch(IOException e){}
        
        while(true)
        {
            try
            {
                // Retrieve first element from buses linkedlist
                fut = buses.getFirst();
                // Get bus details
                b = fut.get();
                // Iterate over passengerss in bus
                b.customers.forEach(c -> {
                    try
                    {
                        fw = new FileWriter(f, true);
                        fw.write("Bus(" + b.busId + ") Passenger(" + c.customerID + ") Ticket(" + c.t.ticketNum + ")\n");
                        fw.close();
                    }
                    catch(IOException e){
                        System.out.println("");
                    }
                });
                
                buses.removeFirst();
                b = null;
            }
            catch(InterruptedException | ExecutionException e){}
        }    
    }        
}
