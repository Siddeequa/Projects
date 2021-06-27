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
public class terminalStaff implements Runnable {
    ticketCounter tCounter;
    
    // Constructor
    public terminalStaff(ticketCounter tCounter)
    {
        this.tCounter = tCounter;
    }
    
    @Override
    public void run()
    {
        while(true)
        {
            try
            {
                //Assuming staff wants to go toilet every 5 to 20 seconds (so it can be seen in simulation)
                Thread.sleep(5000+new Random().nextInt(20000));
            }
            catch(InterruptedException e){}
            
            while(true)
            {
                // If staff member manages to acquire permit, he can use washroom. Nobody else can accessc= counter.
                if(tCounter.tcounterSem.tryAcquire()==true)
                {
                    break;
                }
                
            }
            // Using washroom
            tCounter.toiletBreak();
            
            try
            {
                //the staffs toilet break is of 8 seconds as per question requirement
                Thread.sleep(8000);
            }
            catch(InterruptedException e){}
            // Returns from wasroom after 8 seconds
            tCounter.backFromBreak();
            tCounter.tcounterSem.release(); // Free permit so customers can use once back to work
        }
    }
}
