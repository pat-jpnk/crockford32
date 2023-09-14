## Description 

An implementation of Crockford's Base32 encoding, including checksums. Intendedjj for use on unique resource identifiers in APIs.

Created using [pybind11](https://github.com/pybind/pybind11) and [setuptools](https://pypi.org/project/setuptools/).

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

*throws ValueError* - invalid input characters 

```python
import crockford32 as cr32

decode_input_one = "91JPRV3F"
decode_input_two = "AHS6AS8U"

try:
	a = cr32.encode(decode_input_one)
except ValueError:
	pass    

try:
	b = cr32.encode(decode_input_two, True)
except ValueError:
	pass    

```