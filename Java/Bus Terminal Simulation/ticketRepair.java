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
public class ticketRepair implements Runnable {
    ticketingMachine tMachine; // To be repaired when broken
    
    // Constructor
    public ticketRepair(ticketingMachine tMachine)
    {
        this.tMachine = tMachine;
    }
    
    @Override
    public void run()
    {
        while(true)
        {
            //if machine is functioning properly
            if(tMachine.working == true)
            {
                // Do nothing
                ;
            }
            else // Broken machine
            {
                try
                {
                    System.out.println("\nTechnician coming to fix Machine");
                    Thread.sleep(4000); // Time taken to reach machine
                    System.out.println("\nFixing Machine!");
                    Thread.sleep(6000); // Time taken to fix machine
                }
                catch(InterruptedException e){}
                // Machine fixed
                tMachine.machineRepair();
            }
        }
    }
}
