/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CCPAssignmentTerminal;

import java.util.LinkedList;
import java.util.Random;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Future;

/**
 *
 * @author User
 */
public class manageBus implements Runnable {
    String dest;
    waitingRoom w;
    getBusNumber bnum;
    boolean waitFull;
    ExecutorService term;
    LinkedList<Future<bus>> buses;
    
    // Constructor
   public manageBus(getBusNumber bnum, String dest, waitingRoom w, ExecutorService term, LinkedList<Future<bus>> buses)
   {
       this.bnum = bnum;
       this.dest = dest;
       this.w = w;
       this.term = term;
       this.buses = buses;
   }
   
   @Override
   public void run()
   {
       while(true)
       {
           CountDownLatch latch=new CountDownLatch(6); // Half max size people in bus. Max = 12, Half = 6
           // Get bus number
           int busId = bnum.getBusNumber();
           int capacity = new Random().nextInt(2);
           // Bus will leave either when it has reached max capacity (here 6), or has waited its needed time.
           waitFull = capacity == 0;
           while(true)
           {
               if(w.busLimit.hasQueuedThreads() == true) // Other bus waiting
               {
                   try
                   {
                        Thread.sleep(10000);
                   }
                   catch(InterruptedException e){}
               }
               else
               {
                   break;
               }
           }
           
           Future<bus> f = term.submit(new bus(busId, dest, w, latch, waitFull));
           buses.addLast(f); // Add to linkedlist
           try
           {
               Thread.sleep(10000);
           }
           catch(InterruptedException e){}
       }
   }
}
