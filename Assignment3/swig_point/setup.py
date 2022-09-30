#!/usr/bin/env python

"""
setup.py file for SWIG example
"""

from distutils.core import setup, Extension


point_module = Extension('_point',
                           sources=['../CompPhys/ReviewCpp/ClassExample/Point.cc', 'swig_point/point_wrap.cxx' ],
                           extra_compile_args=["-std=c++11", "-I../"],
                           )

setup (name = 'point',
       version = '0.1',
       author      = "SWIG Docs",
       description = """Simple swig point from docs""",
       ext_modules = [point_module],
       py_modules = ["point"],
       )
