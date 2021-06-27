/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package CCPAssignmentTerminal;

/**
 *
 * @author User
 */
public class terminalGuard implements Runnable {
    terminal term;
    
    // The guard's job is to check whether the terminal building is full, and to close its entrance if yes
    
    // Constructor
    public terminalGuard(terminal term)
    {
        this.term = term;
    }
    
    @Override
    public void run()
    {
        while(true)
        {   
            if(term.bterminalSem.availablePermits()==0)
            {
                // If no permit, terminal full
                term.terminalFull();
            }
        }
    }
}
