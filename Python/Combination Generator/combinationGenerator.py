# -*- coding: utf-8 -*-
"""
Created on Thu Apr  8 16:41:40 2021

@author: Siddeequa
"""

# Write a generator that returns every arrangement of items 
# such that each is in one or none of two different bags. 
# Each combination should be given as a tuple of two lists, 
# the first being the items in bag1, and the second being the items in bag2.

def yieldAllCombos(items):
    """
        Generates all combinations of N items into two bags, whereby each 
        item is in one or zero bags.

        Yields a tuple, (bag1, bag2), where each bag is represented as a list 
        of which item(s) are in each bag.
    """
    # Get number of items in list
    num_items = len(items)
    
    # Since there are 3 options, there will be 3**num_items possible combinations
    # Enumerate the combinations
    for i in range(3**num_items):
        # Lists to hold items in bag1 and bag2
        bag1 = []
        bag2 = []
        
        for j in range(num_items):
            # Test bit jth of integer i
            if (i // 3**j) % 3 == 2:
                bag1.append(items[j])
            elif (i // 3**j) % 3 == 1:
                bag2.append(items[j])
        
        yield (bag1, bag2)


for i in yieldAllCombos(["yoyo", "me"]):
    print(i)