from setuptools import setup 
from pybind11.setup_helpers import Pybind11Extension

ext_modules = [
  Pybind11Extension("crockford32",
  ["src/Crockford32.cpp","src/pybind11_wrapper.cpp"]
  )
]

with open('PYPI.md') as f:
    readme = f.read()

setup(
name="crockford32",
version="1.0.2",
author="Patrick Japink",
url="https://github.com/pat-jpnk/crockford32",
author_email="jpnk.pat@gmail.com",
description="An implementation of Crockford's Base32 encoding for resource identifiers",
long_description_content_type="text/markdown",
long_description=readme,
license="MIT",
extras_require={"test": "pytest"},
python_requires=">=3.7",
ext_modules=ext_modules
)