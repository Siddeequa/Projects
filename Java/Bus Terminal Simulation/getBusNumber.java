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
public class getBusNumber {
    private static int busNumber = 0;
    
    public synchronized int getBusNumber()
    {
        // Increment bus numberr by 1 each time method is called
        busNumber++;
        return busNumber;
    }
}
