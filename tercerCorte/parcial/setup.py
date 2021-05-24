from Cython.Distutils import build_ext
from distutils.extension import Extension
from distutils.core import setup
from Cython.Build import cythonize
import numpy

exts = (cythonize('cy_heat.pyx', annotate=True))

setup(ext_modules=exts)


ext_modules = [
    Extension('cy_heat',
              ['cy_heat.pyx'],
              libraries=['m'],
              extra_compile_args=['-ffast-math',
                                  '-fopenmp', '-march=native'],
              extra_link_args=['-fopenmp'],
              include_dirs=[numpy.get_include()],
              annotate=True
              )]

setup(
    name='cy_heat',
    cmdclass={'build_ext': build_ext},
    ext_modules=ext_modules
)
