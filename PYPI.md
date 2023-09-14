## Description 

An implementation of Crockford's Base32 encoding, including checksums. Intended for use on unique resource identifiers in APIs.
Does not apply automatic conversions on decode input as described in "API Design Patterns" by JJ Geewax p.92.

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