from distutils.core import setup
from Cython.Build import cythonize
import numpy

exts = (cythonize('cy_functionE.pyx'))

setup(ext_modules=exts,
      include_dirs=[numpy.get_include()]
      )
