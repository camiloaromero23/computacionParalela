from distutils.core import setup
from Cython.Build import cythonize

exts = (cythonize('cy_gravity.pyx'))

setup(ext_modules=exts)
