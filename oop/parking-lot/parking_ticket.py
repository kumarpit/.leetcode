from vehicle import Vehicle
from parking_slot import ParkingSlot
from dataclasses import dataclass

@dataclass
class ParkingTicket:
    vehicle: Vehicle
    slot: ParkingSlot
