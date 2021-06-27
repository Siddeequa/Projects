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
public class getTicketNumber {
    private static int ticketNumber = 0;
    
    public synchronized int getTicketNumber()
    {
        // Increment ticket number by 1 each time method is called
        ticketNumber++; 
        return ticketNumber;
    }
}
