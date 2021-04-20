#%%
import Py11Module as p11m
import matplotlib.pyplot as plt
import numpy as np
import time
import copy

#%%
a = p11m.QuickFind(100)
b = p11m.MonteCarloSimulation(a)
print("initial a and b.")

# c = copy.copy(a)

time.sleep(2)
print("delete b.")
del b
time.sleep(2)
time.sleep(2)
print("delete a.")
del a
time.sleep(2)
time.sleep(2)
print("terminate the program.")
