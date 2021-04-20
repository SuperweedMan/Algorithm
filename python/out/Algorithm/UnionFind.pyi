from typing import overload

class MonteCarloSimulation:
    @overload
    def __init__(self, NumOfElement: int) -> None: ...
    @overload
    def __init__(self, SharedPtrForUnionFindObj: UnionFindBase) -> None: ...
    @overload
    def __init__(*args, **kwargs) -> Any: ...
    def run(self) -> int: ...
    def step(self) -> None: ...

class QuickFind(UnionFindBase):
    def __init__(self, NumOfElement: int) -> None: ...
    def interLink(self, ElementIdx_i: int, ElementIdx_j: int) -> None: ...
    def isConnected(self, ElementIdx_i: int, ElementIdx_j: int) -> bool: ...

class QuickUnion(UnionFindBase):
    def __init__(self, NumOfElement: int) -> None: ...
    def interLink(self, ElementIdx_i: int, ElementIdx_j: int) -> None: ...
    def isConnected(self, ElementIdx_i: int, ElementIdx_j: int) -> bool: ...

class UnionFindBase:
    def __init__(self, *args, **kwargs) -> None: ...
    def interLink(self, ElementIdx_i: int, ElementIdx_j: int) -> None: ...
    def isConnected(self, ElementIdx_i: int, ElementIdx_j: int) -> bool: ...

class WeightedQuickUnion(UnionFindBase):
    def __init__(self, NumOfElement: int) -> None: ...
    def interLink(self, ElementIdx_i: int, ElementIdx_j: int) -> None: ...
    def isConnected(self, ElementIdx_i: int, ElementIdx_j: int) -> bool: ...