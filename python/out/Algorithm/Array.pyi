from typing import overload
import numpy

@overload
def array(arg0: numpy.ndarray[numpy.int32]) -> IntArray: ...
@overload
def array(arg0: numpy.ndarray[numpy.float64]) -> DoubleArray: ...
@overload
def array(*args, **kwargs) -> Any: ...

class ArrayBase:
    def __init__(self, *args, **kwargs) -> None: ...

class DoubleArray(ArrayBase):
    def __init__(self, arg0, std) -> None: ...
    def type(self) -> str: ...

class IntArray(ArrayBase):
    def __init__(self, arg0, std) -> None: ...
    def type(self) -> str: ...
