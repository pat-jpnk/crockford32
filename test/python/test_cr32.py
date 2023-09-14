import crockford32 as cr32
import pytest as py

'''

The functionality is test in more depth in the C++ source code. These
tests are intended to ensure the funtionality of the bindings.

'''


var_one = "8DM6ASBKCNHP2TV5"    # decoded input without checksum
var_two = "8DM6ASBKCNHP2TV5Z"   # decoded input with correct checksum
var_three = "Cheesecake"        # encode input
var_four = "8DM6ASBKCNHP2TV5="  # decoded input with wrong checksum
var_five = "jcaoncnjaojaoacjdoaijcdmaoijdoacajdoaijdaoijdaoidjaoidjadoiajdoiajdcojdcojcaoncnjaojaoacjdoaijcdmaoijdoacajdoaijdaoijdaoidjaoidjad"  # too large encoding/decoding input
var_six = "L8DM6ASBKCNHP2TV5="  # decode with illegal characters



def test_encode_without_checksum():
  assert cr32.encode(var_three, False) == var_one


def test_encode_with_checksum():
  assert cr32.encode(var_three, True) == var_two


def test_decode_without_checksum():
  assert cr32.decode(var_one, False) == var_three


def test_decode_with_checksum():
  assert cr32.decode(var_two, True) == var_three

def test_decode_with_invalid_checksum():
  with py.raises(ValueError):
    cr32.decode(var_four, True)

def test_decode_with_illegal_characters():
  with py.raises(ValueError):
    cr32.decode(var_six, True)


if __name__ == "__main__":
  print(cr32.decode("A9GP6SB3C5S0"))
  print(cr32.encode("Racecar"))
