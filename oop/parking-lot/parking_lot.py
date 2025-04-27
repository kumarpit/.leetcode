from parking_slot import ParkingSlot
from vehicle import Vehicle
from parking_ticket import ParkingTicket

class ParkingLot:
    def __init__(self, num_slots: int):
        self.slots = [ParkingSlot(i) for i in range(1, num_slots + 1)]
        print(f"Created a parking lot with {num_slots} slots")

    def park(self, vehicle: Vehicle) -> ParkingTicket | None:
        slot = self.__find_slot()
        if slot is not None:
            slot.occupy(vehicle)
            return ParkingTicket(vehicle, slot)
        
        return None

    def __find_slot(self) -> ParkingSlot | None:
        for slot in self.slots:
            if slot.is_empty:
                return slot

        return None
