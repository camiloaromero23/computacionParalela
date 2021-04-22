from distutils.core import setup
from Cython.Build import cythonize

externs = (cythonize("cyfib.pyx"))

setup(ext_modules=externs)
