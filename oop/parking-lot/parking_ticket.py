from vehicle import Vehicle
from parking_slot import ParkingSlot

class ParkingTicket:
    def __init__(self, vehicle: Vehicle, slot: ParkingSlot):
        self.vehicle = vehicle
        self.slot = slot
