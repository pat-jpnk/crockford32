## Description 

An implementation of [Crockford's Base32](https://www.crockford.com/base32.html) encoding, including checksums. Intended for use on unique resource identifiers in APIs. Does not apply automatic conversions on decode input as described in "[API Design Patterns](https://www.manning.com/books/api-design-patterns)" by JJ Geewax p.92.

Python bindings created using [pybind11](https://github.com/pybind/pybind11). Built with [setuptools](https://pypi.org/project/setuptools/), [manylinux](https://github.com/pypa/manylinux), [wheel](https://github.com/pypa/wheel) and [auditwheel](https://github.com/pypa/auditwheel).

## Usage 

**encode**(string input [, checksum = False])

```python
import crockford32 as cr32

encode_input_one = "Hello"
encode_input_two = "Tree"

a = cr32.encode(encode_input_one)

b = cr32.encode(encode_input_two, True)

```

**decode**(string input [, checksum = False])

*throws ValueError* - invalid input characters

*throws ValueError* - invalid checksum (**requires checksum=True**)

```python
import crockford32 as cr32

decode_input_one = "91JPRV3F"
decode_input_two = "AHS6AS8U"

try:
	a = cr32.decode(decode_input_one)
except ValueError:
	pass    

try:
	b = cr32.decode(decode_input_two, True)
except ValueError:
	pass    

```