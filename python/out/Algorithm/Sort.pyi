from typing import Iterable, Iterator

from typing import overload

def inputAClass(arg0: Base) -> None: ...
def inputList(arg0: list) -> list: ...
@overload
def returnAClass(arg0: int) -> C: ...
@overload
def returnAClass(*args, **kwargs) -> Any: ...

class B(Base):
    def __init__(self) -> None: ...

class Base:
    def __init__(self) -> None: ...

class Buffer:
    def __init__(self, arg0: buffer) -> None: ...

class C(Base):
    def __init__(self) -> None: ...

class InsertSortDouble(SortBaseDouble):
    def __init__(self) -> None: ...
    def sort(self, array: VectorDouble) -> None: ...

class InsertSortFloat(SortBaseFloat):
    def __init__(self) -> None: ...
    def sort(self, array: VectorFloat) -> None: ...

class InsertSortInt(SortBaseInt):
    def __init__(self) -> None: ...
    def sort(self, array: VectorInt) -> None: ...

class SelectSortDouble(SortBaseDouble):
    def __init__(self) -> None: ...
    def sort(self, array: VectorDouble) -> None: ...

class SelectSortFloat(SortBaseFloat):
    def __init__(self) -> None: ...
    def sort(self, array: VectorFloat) -> None: ...

class SelectSortInt(SortBaseInt):
    def __init__(self) -> None: ...
    def sort(self, array: VectorInt) -> None: ...

class SortBaseDouble:
    def __init__(self, *args, **kwargs) -> None: ...
    def isSorted(self, array: VectorDouble) -> bool: ...
    def sort(self, array: VectorDouble) -> None: ...

class SortBaseFloat:
    def __init__(self, *args, **kwargs) -> None: ...
    def isSorted(self, array: VectorFloat) -> bool: ...
    def sort(self, array: VectorFloat) -> None: ...

class SortBaseInt:
    def __init__(self, *args, **kwargs) -> None: ...
    def isSorted(self, array: VectorInt) -> bool: ...
    def sort(self, array: VectorInt) -> None: ...

class VectorDouble:
    __hash__: Any = ...
    @overload
    def __init__(self) -> None: ...
    @overload
    def __init__(self, arg0: VectorDouble) -> None: ...
    @overload
    def __init__(self, arg0: Iterable) -> None: ...
    @overload
    def __init__(*args, **kwargs) -> Any: ...
    def append(self, x: float) -> None: ...
    def clear(self) -> None: ...
    def count(self, x: float) -> int: ...
    @overload
    def extend(self, L: VectorDouble) -> None: ...
    @overload
    def extend(self, L: Iterable) -> None: ...
    @overload
    def extend(*args, **kwargs) -> Any: ...
    def insert(self, i: int, x: float) -> None: ...
    @overload
    def pop(self) -> float: ...
    @overload
    def pop(self, i: int) -> float: ...
    @overload
    def pop(*args, **kwargs) -> Any: ...
    def remove(self, x: float) -> None: ...
    def __bool__(self) -> bool: ...
    def __contains__(self, x: float) -> bool: ...
    @overload
    def __delitem__(self, arg0: int) -> None: ...
    @overload
    def __delitem__(self, arg0: slice) -> None: ...
    @overload
    def __delitem__(*args, **kwargs) -> Any: ...
    def __eq__(self, arg0: VectorDouble) -> bool: ...
    @overload
    def __getitem__(self, s: slice) -> VectorDouble: ...
    @overload
    def __getitem__(self, arg0: int) -> float: ...
    @overload
    def __getitem__(*args, **kwargs) -> Any: ...
    def __iter__(self) -> Iterator: ...
    def __len__(self) -> int: ...
    def __ne__(self, arg0: VectorDouble) -> bool: ...
    @overload
    def __setitem__(self, arg0: int, arg1: float) -> None: ...
    @overload
    def __setitem__(self, arg0: slice, arg1: VectorDouble) -> None: ...
    @overload
    def __setitem__(*args, **kwargs) -> Any: ...

class VectorFloat:
    __hash__: Any = ...
    @overload
    def __init__(self) -> None: ...
    @overload
    def __init__(self, arg0: VectorFloat) -> None: ...
    @overload
    def __init__(self, arg0: Iterable) -> None: ...
    @overload
    def __init__(*args, **kwargs) -> Any: ...
    def append(self, x: float) -> None: ...
    def clear(self) -> None: ...
    def count(self, x: float) -> int: ...
    @overload
    def extend(self, L: VectorFloat) -> None: ...
    @overload
    def extend(self, L: Iterable) -> None: ...
    @overload
    def extend(*args, **kwargs) -> Any: ...
    def insert(self, i: int, x: float) -> None: ...
    @overload
    def pop(self) -> float: ...
    @overload
    def pop(self, i: int) -> float: ...
    @overload
    def pop(*args, **kwargs) -> Any: ...
    def remove(self, x: float) -> None: ...
    def __bool__(self) -> bool: ...
    def __contains__(self, x: float) -> bool: ...
    @overload
    def __delitem__(self, arg0: int) -> None: ...
    @overload
    def __delitem__(self, arg0: slice) -> None: ...
    @overload
    def __delitem__(*args, **kwargs) -> Any: ...
    def __eq__(self, arg0: VectorFloat) -> bool: ...
    @overload
    def __getitem__(self, s: slice) -> VectorFloat: ...
    @overload
    def __getitem__(self, arg0: int) -> float: ...
    @overload
    def __getitem__(*args, **kwargs) -> Any: ...
    def __iter__(self) -> Iterator: ...
    def __len__(self) -> int: ...
    def __ne__(self, arg0: VectorFloat) -> bool: ...
    @overload
    def __setitem__(self, arg0: int, arg1: float) -> None: ...
    @overload
    def __setitem__(self, arg0: slice, arg1: VectorFloat) -> None: ...
    @overload
    def __setitem__(*args, **kwargs) -> Any: ...

class VectorInt:
    __hash__: Any = ...
    @overload
    def __init__(self) -> None: ...
    @overload
    def __init__(self, arg0: VectorInt) -> None: ...
    @overload
    def __init__(self, arg0: Iterable) -> None: ...
    @overload
    def __init__(*args, **kwargs) -> Any: ...
    def append(self, x: int) -> None: ...
    def clear(self) -> None: ...
    def count(self, x: int) -> int: ...
    @overload
    def extend(self, L: VectorInt) -> None: ...
    @overload
    def extend(self, L: Iterable) -> None: ...
    @overload
    def extend(*args, **kwargs) -> Any: ...
    def insert(self, i: int, x: int) -> None: ...
    @overload
    def pop(self) -> int: ...
    @overload
    def pop(self, i: int) -> int: ...
    @overload
    def pop(*args, **kwargs) -> Any: ...
    def remove(self, x: int) -> None: ...
    def __bool__(self) -> bool: ...
    def __contains__(self, x: int) -> bool: ...
    @overload
    def __delitem__(self, arg0: int) -> None: ...
    @overload
    def __delitem__(self, arg0: slice) -> None: ...
    @overload
    def __delitem__(*args, **kwargs) -> Any: ...
    def __eq__(self, arg0: VectorInt) -> bool: ...
    @overload
    def __getitem__(self, s: slice) -> VectorInt: ...
    @overload
    def __getitem__(self, arg0: int) -> int: ...
    @overload
    def __getitem__(*args, **kwargs) -> Any: ...
    def __iter__(self) -> Iterator: ...
    def __len__(self) -> int: ...
    def __ne__(self, arg0: VectorInt) -> bool: ...
    @overload
    def __setitem__(self, arg0: int, arg1: int) -> None: ...
    @overload
    def __setitem__(self, arg0: slice, arg1: VectorInt) -> None: ...
    @overload
    def __setitem__(*args, **kwargs) -> Any: ...