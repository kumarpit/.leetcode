from vehicle import Vehicle
from typing import Optional

class ParkingSlot:
    def __init__(self, index: int):
        self.index = index
        self.is_empty = True
        self.occupant: Optional[Vehicle] = None

    def occupy(self, vehicle: Vehicle):
        if not self.is_empty:
            raise Exception(f"Slot number {self.index} is not empty")
        self.occupant = vehicle
        self.is_empty = False

    def vacate(self):
        if self.is_empty:
            raise Exception(f"Slot number {self.index} is already free")
        self.occupant = None
        self.is_empty = True
