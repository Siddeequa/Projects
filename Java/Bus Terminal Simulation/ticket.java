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
public class ticket {
    int ticketNum;
    String dest; //A, B or C
    boolean scanned; // To check if temperature scanned.
    boolean proceed; // To check whether temperature of normal. Proceed if yes.
    boolean checked; // To check if bus inspector has checked ticket.
    
    // Constructor
    public ticket(int ticketNum, String dest) // Ticket comprises a number and destination place.
    {
        this.ticketNum = ticketNum;
        this.dest = dest;
    }
    
    // Method to check temperaure 
    // Must check temperature according to question requirement because of health concerns
    public void checkTemperature()
    {
        // Initialise both to true first
        scanned = true;
        proceed = true;
    }
    
    // Method for bus inspector to check ticket
    public void checkTicket()
    {
        // Initialise to true first
        checked = true;
    }
}
