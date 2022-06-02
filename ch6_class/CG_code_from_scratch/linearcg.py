import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import MaxNLocator
from itertools import product
from warnings import warn
from sklearn.datasets import make_spd_matrix

def LinearCG(A, b, x0, tol=1e-5):
    xk = x0
    A = A*b
    xk += 2