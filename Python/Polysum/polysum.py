# -*- coding: utf-8 -*-
"""
Created on Wed Feb 24 13:50:14 2021

@author: Siddeequa
"""

# Library containing math functions
import math

def polysum(n,s):
    '''
    Parameters
    ----------
    n : int
        Number of sides of regular polygon.
    s : float
        Length of side.

    Returns
    -------
    Returns sum of area and square of perimeter of regular polygon

    '''
    # Area of polygon
    area = (0.25 * n * (s ** 2)) / math.tan(math.pi / n)

    # Perimeter of polygon
    perimeter = n * s
    
    return round(area + (perimeter ** 2), 4)
    
